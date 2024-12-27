//				GRUP ÜYELERİ
//		İsim Soyisim 		Numara
//-------------------------------------------
//	    Abdulbaki Çelebi 	B211210009 
//	    Akif Emre Sula 		B211210030
//	    Hümeyra Öztürk 		B211210014
//	    Sena Erden 			B211210041
//	    Mert Can Yeter 		B211210092


#include "shell.h"

void print_prompt()
{
    printf("> ");
    fflush(stdout); // Çıktı tamponunu temizle
}

// Ctrl+C sinyalini yakala
void sigint_handler(int sig)
{
    // Ctrl+C'ye basıldığında hiçbir şey yapmıyoruz
    // Bu şekilde programı öldürmemiş olacağız
    printf("\n");
    print_prompt();
}

// Main fonksiyon
int main()
{
    // SIGCHLD sinyali için signal kullan
    signal(SIGCHLD, handle_signal);

    // Ctrl+C'ye karşı sinyal yakalama
    signal(SIGINT, sigint_handler);

    char command[MAX_COMMAND_LENGTH]; // Kullanıcı komutunu tutacak dizi

    while (1)
    {
        // Prompt yalnızca burada yazdırılır
        print_prompt();

        // Kullanıcı komutunu oku
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            if (feof(stdin))
            { // EOF kontrolü
                break;
            }
            clearerr(stdin);
            continue;
        }

        // Yeni satır karakterini kaldır
        command[strcspn(command, "\n")] = '\0';

        // Komutu işle
        execute_command(command);
    }

    return 0;
}

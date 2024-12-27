//				GRUP ÜYELERİ
//		İsim Soyisim 		Numara
//-------------------------------------------
//	    Abdulbaki Çelebi 	B211210009 
//	    Akif Emre Sula 		B211210030
//	    Hümeyra Öztürk 		B211210014
//	    Sena Erden 			B211210041
//	    Mert Can Yeter 		B211210092





#include "shell.h"

void execute_background(char *command)
{
    command[strlen(command) - 1] = '\0'; // '&' karakterini temizle
    pid_t pid = fork();
    if (pid == 0)
    {
        // Çocuk süreç: Komutu çalıştır
        execute_single_command(command);
        exit(0);
    }
    else if (pid > 0)
    {
        printf("[Background pid %d]\n", pid); // Arka planda çalışan işlemi yazdır
        fflush(stdout);
    }
    else
    {
        perror("fork failed");
    }
}

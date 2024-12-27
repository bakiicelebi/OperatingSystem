//				GRUP ÜYELERİ
//		İsim Soyisim 		Numara
//-------------------------------------------
//	    Abdulbaki Çelebi 	B211210009 
//	    Akif Emre Sula 		B211210030
//	    Hümeyra Öztürk 		B211210014
//	    Sena Erden 			B211210041
//	    Mert Can Yeter 		B211210092







#include "shell.h"

// Sinyal yakalama fonksiyonu
void handle_signal(int sig)
{
    if (sig == SIGCHLD)
    {
        int status;       // Çocuk işlemin çıkış durumu
        pid_t pid;        // Çocuk işlemin PID'si
        char buffer[256]; // Çıkış mesajı için buffer

        while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
        {
            // Çıkış mesajını doğrudan write ile yazdır
            int len = snprintf(buffer, sizeof(buffer), "[pid %d] retval: %d\n", pid, WEXITSTATUS(status)); // Çıkış mesajını oluştur
            write(STDOUT_FILENO, buffer, len);                                                             // Çıkış mesajını yazdır
            print_prompt();                                                                                // Prompt'u yazdır
        }
    }
}

// Arka planda çalışan işlemleri bekler
void wait_for_background_processes()
{
    int status; // Çocuk işlemin çıkış durumu
    pid_t pid;  // Çocuk işlemin PID'si
    while ((pid = waitpid(-1, &status, 0)) > 0)
    {
        printf("[%d] retval: %d\n", pid, WEXITSTATUS(status)); // Çocuk işlemin çıkış durumunu yazdır
    }
}

//ss
//				GRUP ÜYELERİ
//		İsim Soyisim 		Numara
//-------------------------------------------
//	    Abdulbaki Çelebi 	B211210009 
//	    Akif Emre Sula 		B211210030
//	    Hümeyra Öztürk 		B211210014
//	    Sena Erden 			B211210041
//	    Mert Can Yeter 		B211210092


#include "shell.h"

void handle_redirection(char *command)
{
    char *input_file = NULL;  // Giriş dosyası
    char *output_file = NULL; // Çıkış dosyası
    char *args[MAX_ARG_COUNT];
    int i = 0;

    char *token = strtok(command, " "); // Komutu boşluklara göre ayır
    while (token != NULL)               // Token NULL olana kadar dön
    {
        if (strcmp(token, "<") == 0)
        {
            token = strtok(NULL, " ");
            input_file = token;
        }
        else if (strcmp(token, ">") == 0)
        {
            token = strtok(NULL, " ");
            output_file = token;
        }
        else
        {
            args[i++] = token;
        }
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork(); // Yeni bir işlem oluştur
    if (pid == 0)
    {
        if (input_file)
        {
            int fd_in = open(input_file, O_RDONLY); // Giriş dosyasını aç
            if (fd_in < 0)
            {
                perror("Input file open failed");
                exit(1);
            }
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }

        if (output_file)
        {
            int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_out < 0)
            {
                perror("Output file open failed");
                exit(1);
            }
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }

        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        perror("fork failed");
    }
}

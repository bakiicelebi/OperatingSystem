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

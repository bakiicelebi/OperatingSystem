#include "shell.h"

void execute_pipe(char *command)
{
    char *commands[MAX_ARG_COUNT];
    int i = 0;

    char *token = strtok(command, "|"); // Komutu "|" karakterine göre ayır
    while (token != NULL)
    {
        commands[i++] = token;
        token = strtok(NULL, "|");
    }
    commands[i] = NULL;

    int num_pipes = i - 1;
    int pipes[2 * num_pipes];

    for (i = 0; i < num_pipes; i++)
    { // Pipe'ları oluştur
        if (pipe(pipes + i * 2) < 0)
        {
            perror("pipe failed");
            exit(1);
        }
    }

    int j = 0;
    for (i = 0; i <= num_pipes; i++)
    { // Her bir komutu işle
        pid_t pid = fork();
        if (pid == 0)
        {
            if (i > 0)
            {
                dup2(pipes[(i - 1) * 2], STDIN_FILENO);
            }
            if (i < num_pipes)
            {
                dup2(pipes[i * 2 + 1], STDOUT_FILENO);
            }

            for (j = 0; j < 2 * num_pipes; j++)
            {
                close(pipes[j]);
            }

            handle_redirection(commands[i]);
            exit(0);
        }
        else if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }
    }

    for (i = 0; i < 2 * num_pipes; i++)
    { // Pipe'ları kapat
        close(pipes[i]);
    }

    for (i = 0; i <= num_pipes; i++)
    { // Çocuk işlemleri bekle
        wait(NULL);
    }
}

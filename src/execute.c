#include "shell.h"

void execute_command(char *command)
{
    if (strcmp(command, "quit") == 0) // Eğer komut quit ise
    {
        wait_for_background_processes();
        exit(0);
    }
    else if (strchr(command, '|')) // Eğer komutta pipe varsa
    {
        execute_pipe(command);
    }
    else if (strchr(command, '&')) // Eğer komutta arka planda çalıştırma varsa
    {
        execute_background(command);
    }
    else
    {
        handle_redirection(command);
    }
}

void execute_single_command(char *command)
{
    char *args[MAX_ARG_COUNT];
    int i = 0;
    char *token = strtok(command, " ");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();
    if (pid == 0)
    {
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

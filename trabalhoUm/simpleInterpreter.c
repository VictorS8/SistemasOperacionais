#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    while (1)
    {
        pid_t pid;
        char inputtedCommand[30];

        printf("Digite um comando simples: \"0\" para sair - ");
        scanf("%s", inputtedCommand);

        if (strcmp(inputtedCommand, "0") == 0)
        {
            printf("Shell is closed!");
            exit(0);
        }

        pid = fork();
        if (pid != 0)
        {
            int status;
            waitpid(pid, &status, 0);
        }
        else
        {
            execlp(inputtedCommand, inputtedCommand, NULL);
        }
    }
}

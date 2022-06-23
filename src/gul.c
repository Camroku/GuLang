#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interpreter.h"

#define VERSION "0.1"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("You need to enter exactly 2 arguments while running GuLang.\n");
        return 1;
    }
    if (argv[1][0] == '-')
    {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            printf(
                "GuLang %s\n"
                "usage: %s [file|argument]\n\n"
                "arguments:\n"
                " --help,    -h   show this message and exit\n"
                " --version, -v   show version and exit\n",
                argv[0],
                VERSION);
            return 0;
        }
        else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
        {
            printf("%s-%s\n", argv[0], VERSION);
            return 0;
        }
        else
        {
            printf("Unknown argument '%s'.\n", argv[1]);
            return 1;
        }
    }
    FILE *file = fopen(argv[1], "r");
    gul_int(file);
    return 0;
}

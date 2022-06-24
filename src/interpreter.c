#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "interpreter.h"

void gul_int(FILE *file)
{
    int currentreg = 0;
    int regs[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 0;
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (isdigit(c))
        {
            regs[currentreg] = c - '0';
        }
        else if (c == '`')
        {
            c = fgetc(file);
            currentreg = c - '0';
        }
        else if (c == '+')
        {
            c = fgetc(file);
            int left = regs[c - '0'];
            c = fgetc(file);
            int right = regs[c - '0'];
            regs[currentreg] = left + right;
        }
        else if (c == '-')
        {
            c = fgetc(file);
            int left = regs[c - '0'];
            c = fgetc(file);
            int right = regs[c - '0'];
            regs[currentreg] = left - right;
        }
        else if (c == '*')
        {
            c = fgetc(file);
            int left = regs[c - '0'];
            c = fgetc(file);
            int right = regs[c - '0'];
            regs[currentreg] = left * right;
        }
        else if (c == '/')
        {
            c = fgetc(file);
            int left = regs[c - '0'];
            c = fgetc(file);
            int right = regs[c - '0'];
            regs[currentreg] = left / right;
        }
        else if (c == '%')
        {
            c = fgetc(file);
            int left = regs[c - '0'];
            c = fgetc(file);
            int right = regs[c - '0'];
            regs[currentreg] = left % right;
        }
        else if (c == '"')
        {
            int chr = regs[currentreg];
            printf("%c", chr);
        }
        else if (c == '\'')
        {
            int chr = regs[currentreg];
            printf("%d", chr);
        }
        else if (c == ':')
        {
            c = fgetc(file);
            regs[currentreg] = c;
        }
        else if (c == '#')
        {
            scanf("%d", &regs[currentreg]);
        }
        else if (c == '@')
        {
            scanf("%c", &regs[currentreg]);
        }
        else if (c == '=')
        {
            regs[currentreg] = ftell(file);
        }
        else if (c == '^')
        {
            fseek(file, regs[currentreg], SEEK_SET);
        }
        else if (c == '!')
        {
            exit(0);
        }
        else if (c == '|')
        {
            c = fgetc(file);
            if (regs[currentreg] == 0)
            {
                if (isdigit(c))
                {
                    fseek(file, regs[c - '0'], SEEK_SET);
                }
                else if (c == ' ')
                {
                }
                else
                {
                    printf("If value must be a digit or space, invalid value %d ('%c')\n", c, c);
                    exit(1);
                }
                c = fgetc(file); // skip the next character since it's supposed to be 'else value'.
            }
            else
            {
                c = fgetc(file);
                if (isdigit(c))
                {
                    fseek(file, regs[c - '0'], SEEK_SET);
                }
                else if (c == ' ')
                {
                }
                else
                {
                    printf("Else value must be a digit or space, invalid value %d ('%c')\n", c, c);
                    exit(1);
                }
            }
        }
        else if (c == '[')
        {
            regs[currentreg] = ftell(file);
            while (c != ']')
                c = fgetc(file);

        }
        else if (c == ']')
        {
        }
        else if (isspace(c))
        {
        }
        else
        {
            printf("Unknown opcode %d ('%c')", c, c);
            exit(1);
        }
        char proccessed[2] = {c, 0};
    }
    /* For debugging
    printf("reg[0] = %d\n", regs[0]);
    printf("reg[1] = %d\n", regs[1]);
    printf("reg[2] = %d\n", regs[2]);
    printf("reg[3] = %d\n", regs[3]);
    printf("reg[4] = %d\n", regs[4]);
    printf("reg[5] = %d\n", regs[5]);
    printf("reg[6] = %d\n", regs[6]);
    printf("reg[7] = %d\n", regs[7]);
    printf("reg[8] = %d\n", regs[8]);
    printf("reg[9] = %d\n", regs[9]);
    printf("curreg = %d\n", currentreg);
    */
}
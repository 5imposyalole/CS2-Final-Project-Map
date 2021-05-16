/**
 * This code was copied from the book "C Programming, A Modern Approach 2nd ed."
 * (written by K. N. King), for the lecture "Computer Software II" in Nagoya University.
 */

#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
    int ch, i = 0;

    while(isspace(ch = getchar()))
        ;
    while(ch != '\n' && ch != EOF) {
        if(i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}


/* compile & run:
    gcc -W -Wall -Wextra words.c -o words.out && ./words.out words.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//1.12 write a program that prints it s input one word per line

int main(int argc, char* argv[])
{
    //Setting up input for program
    FILE* input = NULL;
    if (argc < 2) {
        input = stdin;
    } else {
        input = fopen(argv[1], "r");
        if (NULL == input) {
            fprintf(stderr, "Opening file: %s failed\n", argv[1]);
            return -1;
        }
    }

    char prev_char = EOF;
    char ch;

    while (EOF != (ch = getc(input))) {
        const bool end_of_word = !isspace(prev_char) && isspace(ch);

        if (end_of_word) {
            putchar('\n');
        }

        if (!isspace(ch)) {
            putchar(ch);
        }

        prev_char = ch;
    }

    return 0;
}

/* compile & run:
    gcc -W -Wall -Wextra trimcat.c -o trimcat.out && ./trimcat.out trimcat.c
*/

#include <stdio.h>
#include <stdlib.h>

//1.9 Write a program to copy its input to its output, BUT
// replacing each string of one or more blanks by a single blank

//I believe the exercise meant to trim contineuos space-es.
//replace the equality check with is_space() calls to
//eliminate all kind of following whitespaces.

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

    char ch = 0;
    char prev_ch = ch;
    while(EOF != (ch = getc(input))) {
        if (prev_ch == ch && ch == ' ') {
            continue;
        } else {
            putchar(ch);
        }
        prev_ch = ch;
    }

    return 0;
}
/* compile & run:
    gcc -W -Wall -Wextra wc.c -o wc.out && ./wc.out wc.c
*/

#include <stdio.h>
#include <stdlib.h>

//1.8 Write a program to count blanks, tabs, and newlines.
//1.10 is same, but instead of counting print out \t instead of the tab
//Pretty trivial exercise if 1.8 is already ready, could make a lookup table for that as well
//
enum whitespace_indeces {BLANK = 0, TAB = 1, NEWLINE = 2, WHITESPACE_LAST = 3 };

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

    unsigned int count[WHITESPACE_LAST] = {0,0,0};
    char ch;
    //going through the whole file char-by-char "matching our pattern"
    while (EOF != (ch = getc(input))) {
        unsigned int index = WHITESPACE_LAST;
        switch (ch) {
            case ' ':
                index = BLANK; break;
            case '\t':
                index = TAB; break;
            case '\n':
                index = NEWLINE; break;
            default:
                index = WHITESPACE_LAST;
        }
        if (WHITESPACE_LAST != index) {
            count[index]++;
        }
    }

    printf("blanks: %u, tabs: %u newlines: %u\n",
            count[BLANK], count[TAB], count[NEWLINE]);

    return 0;
}
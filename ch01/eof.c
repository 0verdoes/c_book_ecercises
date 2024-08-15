/* compile & run:
    gcc -W -Wall -Wextra eof.c -o eof.out && ./eof.out
*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{   //exercise 1.6
    printf("Read char %s EOF\n", (getchar() != EOF) ? "is not" : "is");
    //exercise 1.7
    printf("EOF: %d\n", EOF);
    return 0;
}

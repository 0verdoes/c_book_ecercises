#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Small program to compare from fahrenheit to Celsius OR
   celsius to Fahrenheit according to the comman line arguments
*/

double fahr2cels(double fahr)
{
    const double fahr2cels_factor = 5./9.;
    const double fahr2cels_offset = -32.0;

    return (fahr2cels_factor) * (fahr + fahr2cels_offset);
}

double cels2fahr(double cels)
{
    const double cels2fahr_factor = 9./5.;
    const double cels2fahr_offset = 32.0;

    return (cels * cels2fahr_factor) + cels2fahr_offset;
}

typedef double (*conv_func_t)(double);


int main(int argc, char* argv[])
{
    //list of accepted arguments
    static const char* accepted_args[] = {
        "cels",
        "celsius",
        "--celsius",
        "-C",
        "-c",
    };

    //decoration print
    const char* heading = "FAHR  CELS  \n";

    //abraction of conversion logic
    conv_func_t conv = fahr2cels;

    if (1 < argc) {
        const size_t len = sizeof(accepted_args)/(sizeof(accepted_args[0]));
        bool not_found = true;

        for(size_t i = 0; i < len && not_found; ++i) {
            if (strcmp(argv[1], accepted_args[i])) {
                conv = cels2fahr;
                heading = "CELS  FAHR  \n";
                not_found = false;
            }
        }

        if (not_found) {
            printf("unrecognized argument: %64s", argv[1]);
        }
    }

    int lower = 0;
    int upper = 200;
    int step  = 25;

    //print heading
    printf("%s", heading);
    for(double temp = lower; temp <= upper; temp += step) {
        double conv_temp = conv(temp);
        //printf formatting: 3f-> leave 3 parts for the number
        //3.5f => display 5 nums after the .
        printf("%3.0f %7.2f\n", temp, conv_temp);
    }

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Small program to compare from fahrenheit to Celsius OR
   celsius to Fahrenheit according to the comman line arguments
*/

//ecercise 1.4 convert the otherway
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

enum {CELS_ARGS = 0, BACK_ARGS = 1, ARGS_LAST = 2};
enum {ARGS_LEN = 5};

int main(int argc, char* argv[])
{
    //list of accepted arguments
    static const char* accepted_args[ARGS_LAST][ARGS_LEN] = {
        {"cels", "celsius",   "--celsius",   "-C", "-c"},
        {"back", "backwards", "--backwards", "-B", "-b"}
    };

    //decoration print
    const char* heading = "FAHR  CELS  \n";
    //abraction of conversion logic
    conv_func_t conv = fahr2cels;
    //1.5: loop backwards exercise
    bool backwards   = false;

    if (1 < argc) {
        for (int arg = 1; arg < argc; ++arg) {
            for(size_t i = 0; i < ARGS_LEN; ++i) {
                if (0 == strcmp(argv[arg], accepted_args[CELS_ARGS][i])) {
                    conv = cels2fahr;
                    heading = "CELS  FAHR  \n";
                }
                if (0 == strcmp(argv[arg], accepted_args[BACK_ARGS][i])) {
                    backwards = true;
                }
            }
        }
    }

    int lower = 0;
    int upper = 200;
    int step  = 25;

    //print heading
    printf("%s", heading);
    if (!backwards) {
        for(double temp = lower; temp <= upper; temp += step) {
            double conv_temp = conv(temp);
            //printf formatting: 3f-> leave 3 parts for the number
            //3.5f => display 5 nums after the .
            printf("%3.0f %7.2f\n", temp, conv_temp);
        }
    } else {
        for(double temp = upper; lower <= temp; temp -= step) {
            double conv_temp = conv(temp);
            //printf formatting: 3f-> leave 3 parts for the number
            //3.5f => display 5 nums after the .
            printf("%3.0f %7.2f\n", temp, conv_temp);
        }
    }

    return 0;
}

#include <stdio.h>
//#include "input.txt"

int main(void) 
{
    // initialing variables
    int numArray[100000];
    int count, i, increased;

    // reading a file into an array
    FILE *input_file;
    input_file = fopen("input.txt", "r");

    // counting num of integers in the file
    while (!feof(input_file)) {
        fscanf(input_file, "%d", &numArray[count]);
        ++count;
    }

    // looping through all the inetegrs in the file
    for (i = 0; i < count - 1; i++) {
        fscanf(input_file, "%d", &numArray[i]);
        printf("%d\n", numArray[i]);
        if (numArray[i+1] > numArray[i]) {
            increased++;
        }

    }
    printf("\nincreased: %d", increased);
    return 0;

}
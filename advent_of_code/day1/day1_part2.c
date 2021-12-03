#include <stdio.h>
//#include "input.txt"

int main(void) 
{
    // initialing variables
    int numArray[100000];
    int count, i, increased, j, num;
    int sumThree[100000];

    // reading a file into an array
    FILE *input_file;
    input_file = fopen("input.txt", "r");

    // counting num of integers in the file
    while (!feof(input_file)) {
        fscanf(input_file, "%d", &numArray[count]);
        ++count;
    }
    
    // making sliding windows consisting of three consecutive elements from the file
    for (i = 0; i < count -1; i++) {
        while(numArray[i+2] != 0) {
            int sum_of_three = numArray[i] + numArray[i+1] + numArray[i+2];
            //printf("%d\n", sum_of_three);

            // appending each sliding window to a new array;
            sumThree[i] = sum_of_three;
            
            // counting number of sliding windows
            num++;

            // appending loop counter
            i++;
        }

    }
    printf("num: %d\n", num);


    // looping through elements in the array of sliding windows
    for (j = 0; j < num; j++) {
        printf("%d\n", sumThree[j]);
        if (sumThree[j+1] > sumThree[j]) {
            increased++;
        }
    }
    printf("\nincreased: %d\n", increased);
    return 0;

}
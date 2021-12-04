#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int parse_binary(char data[13]) {
    int result = 0;
    while (*data) {
        result *= 2;
        if (*data++ == '1') {
            result++;
        }   
    }
    
    return result;
}


int main(void) {
    char line[100000];
    char gamma[13], epsilon[13], c;
    int count, i, data[12];
    memset(data, 0, 12);


    // reading a file into an array
    FILE *input_file = fopen("input.txt", "r");

    // getting every single line from the input file
    while ((c = (char)fgetc(input_file)) > 0) {
        count++;
        //printf("%s", line);

        if (c == '\n') {
            i = 0;
            continue;
        } else if (c == '1') {
            data[i] += 1;
        } else {
            data[i] -= 1;
        }
        i++;
    }

    for (i = 0; i < 12; i++) {
        if (data[i] > 0) {
            gamma[i] = '1';
            epsilon[i] = '0';
        } else {
            gamma[i] = '0';
            epsilon[i] = '1';
        }
    }
            
    gamma[12] = 0;
    epsilon[12] = 0;

    printf("%d\n", parse_binary(gamma) * parse_binary(epsilon));


    fclose(input_file);
    return 0;
}
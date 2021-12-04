#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// atoi() converts str into int

int main(void) {
    /*
    x = horizontal
    y = depth
    down = y+
    up = y-
    */
    int x, y;
    char line[100000];
    int count;

    // reading a file into an array
    FILE *input_file;
    input_file = fopen("input.txt", "r");

    // getting every single line from the input file 
    while (fgets(line, sizeof(line), input_file)) {
        //printf("%s", line);

        // counting forward
        char *forward = NULL; 
        forward = strstr(line, "forward");
        if (forward == line) {
            //printf("%s\n", forward);

            // str num values for forward
            char *forward_num = strtok(line, "forward ");
            //printf("%d\n", atoi(forward_num));
            x += atoi(forward_num);
        }

        // counting down
        char *down = NULL;
        down = strstr(line, "down");
        if (down == line) {
            char *down_num = strtok(line, "down ");
            //printf("%d\n", atoi(down_num));
            y += atoi(down_num);
        }

        // counting up
        char *up = NULL;
        up = strstr(line, "up");
        if (up == line) {
            char *up_num = strtok(line, "up ");
            //printf("%d\n", atoi(up_num));
            y -= atoi(up_num);
        }
    }
    //printf("%d", x);
    //printf("%d", y);
    //printf("%d", y);
    int position = x * y;
    printf("%d\n", position);
    
    
    fclose(input_file);
    return 0;
}

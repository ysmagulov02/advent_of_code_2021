#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// atoi() converts str into int

int main(void) {
    /*
    down = aim+
    up = aim- 
    forward num = x += num, y += aim*num
    */
    int position, horizontal, depth, aim;
    char line[100000];
    int count;

    // reading a file into an array
    FILE *input_file;
    input_file = fopen("input.txt", "r");

    // getting every single line from the input file 
    while (fgets(line, sizeof(line), input_file)) {

        // counting down
        char *down = NULL;
        down = strstr(line, "down");
        if (down == line) {
            char *down_num = strtok(line, "down ");
            aim += atoi(down_num);
        }

        // counting up
        char *up = NULL;
        up = strstr(line, "up");
        if (up == line) {
            char *up_num = strtok(line, "up ");
            aim -= atoi(up_num);
        }

        // counting forward
        char *forward = NULL; 
        forward = strstr(line, "forward");
        if (forward == line) {
            //printf("%s\n", forward);

            // str num values for forward
            char *forward_num = strtok(line, "forward ");
            horizontal += atoi(forward_num);
            depth += (aim * atoi(forward_num));
        }

        
    }
    position = horizontal * depth;
    printf("%d\n", position);
    
    
    return 0;
}

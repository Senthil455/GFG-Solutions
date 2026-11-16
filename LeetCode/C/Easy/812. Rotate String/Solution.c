#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool rotateString(char* s, char* goal) {
    int len_s = strlen(s);
    int len_goal = strlen(goal);
    
    if (len_s != len_goal) {
        return false;
    }
    if (len_s == 0) {
        return true;
    }

    char* temp = malloc(2 * len_s + 1);
    strcpy(temp, s);
    strcat(temp, s);

    bool res = (strstr(temp, goal) != NULL);

    free(temp);
    return res;
}
```[cite: 8]
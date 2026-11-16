#include <string.h>
#include <stdlib.h>

int repeatedStringMatch(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int count = (len_b + len_a - 1) / len_a;
    
    char* temp = malloc((count + 2) * len_a + 1);
    temp[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(temp, a);
    }
    
    if (strstr(temp, b) != NULL) {
        free(temp);
        return count;
    }
    
    strcat(temp, a);
    if (strstr(temp, b) != NULL) {
        free(temp);
        return count + 1;
    }
    
    strcat(temp, a);
    if (strstr(temp, b) != NULL) {
        free(temp);
        return count + 2;
    }
    
    free(temp);
    return -1;
}
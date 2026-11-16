#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool detectCapitalUse(char* word) {
    int count = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            count++;
        }
    }
    if (count == len || count == 0) {
        return true;
    }
    if (count == 1 && isupper(word[0])) {
        return true;
    }
    return false;
}
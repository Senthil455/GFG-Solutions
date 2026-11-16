#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* licenseKeyFormatting(char* s, int k) {
    int n = strlen(s);
    int total_chars = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') {
            total_chars++;
        }
    }
    
    if (total_chars == 0) {
        char* res = malloc(1);
        res[0] = '\0';
        return res;
    }

    int dashes = (total_chars - 1) / k;
    int len = total_chars + dashes;
    char* res = malloc((len + 1) * sizeof(char));
    res[len] = '\0';

    int res_idx = len - 1;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '-') continue;
        if (count == k) {
            res[res_idx--] = '-';
            count = 0;
        }
        res[res_idx--] = toupper(s[i]);
        count++;
    }
    return res;
}
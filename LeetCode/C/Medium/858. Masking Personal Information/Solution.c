#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* maskPII(char* s) {
    char* at = strchr(s, '@');
    if (at) {
        char* res = malloc(100);
        int name_len = at - s;
        res[0] = tolower(s[0]);
        strcpy(res + 1, "*****");
        res[6] = tolower(s[name_len - 1]);
        res[7] = '@';
        int j = 8;
        for (char* p = at + 1; *p != '\0'; p++) {
            res[j++] = tolower(*p);
        }
        res[j] = '\0';
        return res;
    } else {
        char digits[20];
        int d_len = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (isdigit(s[i])) {
                digits[d_len++] = s[i];
            }
        }
        digits[d_len] = '\0';

        int cc_len = d_len - 10;
        char* res = malloc(30);
        int idx = 0;

        if (cc_len > 0) {
            res[idx++] = '+';
            for (int i = 0; i < cc_len; i++) {
                res[idx++] = '*';
            }
            res[idx++] = '-';
        }

        strcpy(res + idx, "***-***-");
        idx += 9;

        for (int i = d_len - 4; i < d_len; i++) {
            res[idx++] = digits[i];
        }
        res[idx] = '\0';
        return res;
    }
}
char* removeOuterParentheses(char* s) {
    int i = 0, j = 0, l = 0, k = 0, cnt = 0;
    int len = strlen(s);
    char *ret = (char *)calloc(1, len);
    
    for (j = 0 ; j < len; j++) {
        if (s[j] == '(') cnt++;
        if (s[j] == ')') cnt--;

        if (cnt == 0) {
            for (k=i+1; k < j ; k++) {
                ret[l] = s[k];
                l++;
            }
            i = j +1;
        }
    }
    return ret;
}
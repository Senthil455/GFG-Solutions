char * digitSum(char * s, int k) {
    int cur = 0;
    int sum = 0;
    for (int i = 0; strlen(s) > k; i++) {
        if (i != 0 && i % k == 0 || i == strlen(s)) {
                char buff[16];
                sprintf(buff, "%d", sum);
                for (int i = 0; buff[i]; i++, cur++)
                    s[cur] = buff[i];
                sum = 0;
            }
        if (i == strlen(s)) {    
            s[cur] = '\0';
            cur = 0;
            i = 0;
        }
        sum += s[i] - '0';
    }
    
    return s;
}
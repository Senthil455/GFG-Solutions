char* digitSum(char* s, int k) {
    int len = strlen(s);

    while (len > k) {
        char* next = (char*)calloc(len * 4 + 1, sizeof(char));
        
        for (int i = 0; i < len; i += k) {
            int sum = 0;
            for (int j = i; j < i + k && j < len; j++) {
                sum += s[j] - '0';
            }
            
            char buf[12];
            sprintf(buf, "%d", sum);
            strcat(next, buf);
        }

        s = next;
        len = strlen(s);
    }

    return s;
}
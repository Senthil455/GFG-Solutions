
bool checkValidString(char* s) {
    int minCount = 0, maxCount = 0;
    while (*s != '\0') {
        char c = *(s++);
        if (c == '(') {
            ++minCount;
            ++maxCount;
        } else {
            minCount -= (minCount > 0);
            if (c == ')') {
                if (--maxCount < 0) return false;
            } else {
                ++maxCount;
            }
        }
    }
    return minCount == 0 || maxCount == 0;
}
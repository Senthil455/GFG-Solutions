bool rotateString(char* s, char* goal) {
    int sLen = strlen(s);
    int goalLen = strlen(goal);

    if (sLen != goalLen)
        return false;

    for (int i = 0; i < sLen * 2; i++) {
        int j = 0;
        for (; j < goalLen; j++)
            if (s[(i+j) % sLen] != goal[j])
                break;
        if (j == goalLen)
            return true;
    }

    return false;
}
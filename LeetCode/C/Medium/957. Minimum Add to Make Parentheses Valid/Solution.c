int minAddToMakeValid(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n * sizeof(char));
    int top = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[top++] = s[i];
        }
        else if (top > 0 && s[i] == ')') {
            top--;
        }
        else if (s[i] == ')') {
            res++;
        }
    }

    int result = top + res;

    free(stack);

    return result;
}
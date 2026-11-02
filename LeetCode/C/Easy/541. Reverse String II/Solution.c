void reverse_fn(char* s, int ind1, int ind2)
{
    for (int i = 0; i < ((ind2 - ind1 + 1)/2); i++) {
        char temp = s[ind1+i];
        s[ind1+i] = s[ind2-i];
        s[ind2-i] = temp;
    } 
}

char* reverseStr(char* s, int k) {
    int n, l, i;

    l = strlen(s);
    n = l / k;

    for(i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            reverse_fn(s, (i-1)*k, i*k-1);
        }
    }
    if(l % k != 0) {
        if(n % 2 == 0) {
            reverse_fn(s, n*k, ((n*k) + (l%k)-1));
        }
    }
    return s;
}
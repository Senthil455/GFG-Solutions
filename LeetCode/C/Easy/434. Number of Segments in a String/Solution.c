int countSegments(char* s)
{
    int i;
    int segment;

    i = 0;
    segment = 0;
    while (s[i] && s[i] == ' ')
        i++;
    while (s[i])
    {
        while (s[i] && s[i] != ' ')
            i++;
        segment++;
        while (s[i] && s[i] == ' ')
            i++;
    }
    return (segment);
}
int lengthOfLastWord(char* s)
{

    char *last = s;

    while (*s != '\0')
    {
        if (*s == ' ' && *(s + 1) != '\0' && *(s + 1) != ' ')
            last = s + 1;
        
        s++;
    }

    int size = 0;

    if (last)
    {
        while (*last != '\0' && *last != ' ')
        {
            size++;
            last++;
        }
    }


    return size;
}
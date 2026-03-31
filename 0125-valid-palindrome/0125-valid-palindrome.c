int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

bool isPalindrome(char* s)
{
    if (!s)
        return false;

    int len = strlen(s);

    char *start = s;
    char *end = s + len;

    while (start < end)
    {
        if (*start >= 'A' && *start <= 'Z')
            *start = *start + 32;

        if (*end >= 'A' && *end <= 'Z')
            *end = *end + 32;

        if (is_alphanum(*start) == 0)
        {
            start++;
            continue;
        }

        if (is_alphanum(*end) == 0)
        {
            end--;
            continue;
        }

        if (*start != *end)
            return false;
        
        start++;
        end--;
    }

    return true;
}
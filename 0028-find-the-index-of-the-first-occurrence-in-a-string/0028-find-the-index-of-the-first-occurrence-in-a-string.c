int strStr(char* haystack, char* needle)
{
    int n_len = strlen(needle);
    int h_len = strlen(haystack);

    if (h_len < n_len)
        return -1;

    for (int i = 0; i <= h_len - n_len; i++)
    {
        int j = 0;

        while (needle[j] != '\0' && needle[j] == haystack[i + j])
            j++;

        if (j == n_len)
            return i;
    }  

    return -1; 
}
bool isValid(char* s)
{
    int len = strlen(s);

    if (len % 2 != 0)
        return false;
    
    char *stack = malloc(sizeof(char) * len);
    if (!stack)
        return false;

    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        else
        {
            if (top == -1)
            {   
                free(stack);
                return false;
            }

            char last = stack[top--];

            if (s[i] == ')' && last != '(')
            {
                free(stack);
                return false;
            }
            if (s[i] == ']' && last != '[')
            {
                free(stack);
                return false;
            }
            if (s[i] == '}' && last != '{')
            {
                free(stack);
                return false;
            }
        }
    }

    free(stack);

    return top == -1;
}
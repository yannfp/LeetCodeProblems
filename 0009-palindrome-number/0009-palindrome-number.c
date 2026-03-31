bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    if (x < 10)
        return true;
    
    long long inverted = 0;

    int n = x;

    while (n > 0)
    {
        inverted = inverted * 10 + n % 10;
        n = n /10;
    }

    return inverted == x;
}
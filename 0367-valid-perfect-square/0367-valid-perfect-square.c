bool isPerfectSquare(int num)
{
    long k = 0;

    while (k * k <= num)
    {
        if (k * k == num)
            return true;

        k++;
    }    

    return false;
}
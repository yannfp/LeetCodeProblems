int mySqrt(int x)
{
    if (x < 2)
        return x;

    long k = 0;

    while (k * k <= x)
        k++;
    
    return k - 1;
}
int addDigits(int num)
{
    int result = 0;

    while (num != 0)
    {
        result = result + (num % 10);

        if (result > 9)
        {
            int temp = result % 10;

            result = result / 10;
            result = result + temp;
        }

        num = num /10;
    }    

    return result;
}
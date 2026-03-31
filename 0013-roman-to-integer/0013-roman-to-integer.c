int romanToInt(char* s)
{

    int res = 0;

    while (*s != '\0')
    {
        switch (*s)
        {
            case 'I':
                
                if (*(s + 1) == 'V')
                {                    
                    res = res + 4;
                    s++;
                }
                else if (*(s + 1) == 'X')
                {
                    res = res + 9;
                    s++;
                }
                else
                    res = res + 1;
                break;
            
            case 'V':
                res = res + 5;
                break;
            
            case 'X':
                if (*(s + 1) == 'L')
                {
                    res = res + 40;
                    s++;
                }
                else if (*(s + 1) == 'C')
                {
                    res = res + 90;
                    s++;
                }
                else
                    res = res + 10;
                break;

            case 'L':
                res = res + 50;
                break;

            case 'C':
                if (*(s + 1) == 'D')
                {
                    res = res + 400;
                    s++;
                }
                else if (*(s + 1) == 'M')
                {
                    res = res + 900;
                    s++;
                }
                else
                    res = res + 100;
                break;
            
            case 'D':
                res = res + 500;
                break;
            
            case 'M':
                res = res + 1000;
                break;

            default:
                return 0;
        }

        s++;
    }

    return res;
}
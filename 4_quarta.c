#include <stdio.h>

int MDC(int a, int b)
{
    int fator = 2;
    int mdc = 1;

    while (a > 1 && b > 1)
    {
        if (a % fator == 0 && b % fator == 0)
        {
            mdc *= fator;
            a /= fator;
            b /= fator;
        }
        else if (a % fator == 0)
        {
            a /= fator;
        }
        else if (b % fator == 0)
        {
            b /= fator;
        }
        else
        {
            fator++;
        }
    }

    return mdc;
}

int MMC(int a, int b)
{
    int mmc = 1;
    int fator = 2;

    while (a > 1 || b > 1)
    {
        if (a % fator == 0 && b % fator == 0)
        {
            mmc *= fator;
            a /= fator;
            b /= fator;
        }
        else if (a % fator == 0)
        {
            mmc *= fator;
            a /= fator;
        }
        else if (b % fator == 0)
        {
            mmc *= fator;
            b /= fator;
        }
        else
        {
            fator++;
        }
    }

    return mmc;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0)
    {
        return 0;
    }
    else
    {
        printf("MDC(%d, %d) = %d\n", a, b, MDC(a, b));
        printf("MMC(%d, %d) = %d\n", a, b, MMC(a, b));
    }

    return 0;
}

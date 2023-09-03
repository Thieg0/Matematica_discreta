#include <stdio.h>

int euclides(int a, int d, int *s, int *t)
{
    if (d == 0)
    {
        *s = 1;
        *t = 0;
        return a;
    } 

    int s1, t1;
    int mdc = euclides(d, a % d, &s1, &t1);
    
    *s = t1;
    *t = s1 - (a / d) * t1;
    
    return mdc;
}

int inversoMod(int a, int d)
{
    int s, t;

    if (euclides(a, d, &s, &t) != 1)
    {
        printf("MDC(%d, %d) != 1. Portanto, o inverso não existe\n", a, d);
        return -1;
    }

    int inverso = (s % d + d) % d;

    return inverso;
}

int main()
{
    int a, d;
    scanf("%d %d", &a, &d);

    if (a <= 0 || d <= 0)
    {
        return 0;
    }
    else
    {
        int inverso = inversoMod(a, d);

        if (inverso != -1)
        {
            printf("O inverso de %d mod %d é igual a %d\n", a, d, inverso);
        }
    }

    return 0;
}
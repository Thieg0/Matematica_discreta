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

int main()
{
    int a, d, s, t;
    scanf("%d %d", &a, &d);

    if (a <= 0 || d <= 0)
    {
        return 0;
    }
    else
    {
        printf("MDC(%d, %d) = %d\n", a, d, euclides(a, d, &s, &t));
        printf("s = %d e t = %d\n", s, t);
    }

    return 0;
}
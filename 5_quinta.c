#include <stdio.h>

int euclides(int a, int d)
{
    if (a % d == 0)
    {
        return d;
    } 
    else
    {
        return euclides(d, a % d);
    }
}

int main()
{
    int a, d;
    scanf("%d %d", &a, &d);

    printf("MDC(%d, %d) = %d\n", a, d, euclides(a, d));

    return 0;
}

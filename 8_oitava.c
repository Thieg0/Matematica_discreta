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

int congruencia(int a, int d, int m)
{
    if(inversoMod(a, m) != -1)
    {
        int solucao = (d * inversoMod(a, m)) % m;
        return solucao;
    }

    return -1;
}

int main()
{
    int a, d, m;
    scanf("%d %d %d", &a, &d, &m);

    if (a <= 0 || d <= 0 || m <= 0)
    {
        return 0;
    }
    else
    {
        if (congruencia(a, d, m) != -1)
        {
            printf("%dx ≡ %d mod %d é: x = %d\n", a, d, m, congruencia(a, d, m));
        }
    }

    return 0;
}

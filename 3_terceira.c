#include <stdio.h>

void decompor_em_fatores_primos(int n)
{
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }

    if (n > 1)
    {
        printf("%d ", n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 1)
    {
        return 0;
    }
    else
    {
        printf("Fatores Primos de %d: ", n);
        
        decompor_em_fatores_primos(n);
        
        printf("\n");
    }

    return 0;
}

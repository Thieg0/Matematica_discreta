#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool ehPrimo(int n)
{
    int i;
    if (n < 2) return false;
    
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int main()
{
    int n = 2;
    time_t start_time = time(NULL);
    int contador = 0;
    
    printf("Lista de números primos em sequência:\n");
    
    while (difftime(time(NULL), start_time) < 60)
    {
        if (ehPrimo(n))
        {
            printf("%d ", n);
            contador ++;
        }
        ++n;
    }
    
    printf("\n");
    printf("Em 60 segundos, foi póssível gerar %d números primos.\n", contador);

    return 0;
}
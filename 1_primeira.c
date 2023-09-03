#include <stdio.h>
#include <stdbool.h>

bool eh_primo(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return false;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (eh_primo(n))
    {
        printf("%d é um número primo.\n", n);
    }
    else
    {
        printf("%d não é um número primo.\n", n);
    }

    return 0;
}

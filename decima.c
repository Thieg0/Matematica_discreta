#include <stdio.h>

int euclides(int a, int d) 
{
    if (d == 0) 
    {
        return a;
    } 
    
    return euclides(d, a % d);
}

int inversoMod(int a, int m) 
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) 
    {
        return 0;
    }

    while (a > 1) 
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) 
    {
        x1 += m0;
    }

    return x1;
}

int chines(int n, int a[], int m[]) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if (euclides(m[i], m[(i + 1) % n]) != 1) 
        {
            printf("Os módulos não são coprimos. O Teorema Chinês do Resto não pode ser aplicado.\n");
            return -1;
        }
    }

    int M = 1;
    for (i = 0; i < n; i++) 
    {
        M *= m[i];
    }

    int resultado = 0;
    for (i = 0; i < n; i++) 
    {
        int Mi = M / m[i];
        resultado += a[i] * Mi * inversoMod(Mi, m[i]);
    }

    resultado = resultado % M;

    return resultado;
}

int main() 
{
    int n;
    
    printf("Digite o número de congruências (n): ");
    scanf("%d", &n);

    int a[n], m[n];

    for (int i = 0; i < n; i++) 
    {
        printf("Digite os valores de a%d e m%d (congruência %d): ", i + 1, i + 1, i + 1);
        scanf("%d %d", &a[i], &m[i]);
    }

    int resultado = chines(n, a, m);

    if (resultado != -1) 
    {
        printf("A solução única é x ≡ %d (mod %d)\n", resultado, m[0] * m[1] * m[2]);
    }

    return 0;
}
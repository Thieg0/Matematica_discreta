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

int chines(int a1, int m1, int a2, int m2, int a3, int m3) 
{
    if (euclides(m1, euclides(m2, m3)) != 1) 
    {
        printf("Os módulos não são coprimos. O Teorema Chinês do Resto não pode ser aplicado.\n");
        return -1;
    }

    int M = m1 * m2 * m3;
    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    int x1 = a1 * M1 * inversoMod(M1, m1);
    int x2 = a2 * M2 * inversoMod(M2, m2);
    int x3 = a3 * M3 * inversoMod(M3, m3);

    int resultado = (x1 + x2 + x3) % M;

    return resultado;
}

int main()
{
    int a1, m1, a2, m2, a3, m3;

    printf("Digite os valores de a1 e m1 (congruência 1): ");
    scanf("%d %d", &a1, &m1);

    printf("Digite os valores de a2 e m2 (congruência 2): ");
    scanf("%d %d", &a2, &m2);

    printf("Digite os valores de a3 e m3 (congruência 3): ");
    scanf("%d %d", &a3, &m3);

    int resultado = chines(a1, m1, a2, m2, a3, m3);

    if (resultado != -1) {
        printf("A solução única é x ≡ %d (mod %d)\n", resultado, m1 * m2 * m3);
    }

    return 0;
}
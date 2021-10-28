//
//  main.c
//  Recursividad
//. Desarrollar un programa en C que, mediante la utilización de un diseño recursivo/función recursiva, de tal manera que, sea A una matriz cuadrada de m * n elementos.

#include <stdio.h>
#include <stdlib.h>



void MenorComp(int n, double m[n][n], int I, int J,double M[n-1][n-1])
{
    int i, a = 0, b = 0, j=0;
    for (i = 0; i < n; i++)
    {
        if (i == I)
        {
            continue;
        }

        b = 0;
        for (j = 0; j < n; j++)
        {
            if (J == j)
            {
                continue;
            }
            M[a][b] = m[i][j];
            b++;
        }
        a++;
    }
}


double  determinante(int n, double M[n][n])
{
    double det = 0;
    if(n==1)
    {
        return M[0][0];
    }
    if (n == 2)
    {
        det = M[0][0] *M[1][1]-M[0][1]*M[1][0];
    }
    else
    {
        double subArr[n-1][n-1];
        for (int i = 0; i < n; i++)
        {
            MenorComp(n,M,0,i,subArr);
            det += M[0][i] * ((i&1)?-1:1)*determinante(n - 1,subArr);
        }
    }
    return det;
}

int main(){
    int i, j, n;
    printf("\t\t\tPrograma para calcular determinante de m*n elementos.\n");
    printf("Por favor escoja el número de filas de su matriz cuadrada: "); scanf("%d", &n);
    double matriz[n][n];
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("\nIntroduzca el elemento [%d, %d] de la matriz: ", i+1, j+1); scanf("%lf", &matriz[i][j]);
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("\nEl elemento [%d, %d] de la matriz es = a %lf", i+1, j+1, matriz[i][j]);
        }
    }
    
    printf("\n");
    printf("El determinante de la matriz es = %f", determinante(n, matriz));
    
}

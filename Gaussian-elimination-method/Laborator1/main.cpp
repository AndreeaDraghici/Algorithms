#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    float matrice[10][10];

    //pasul1-Citim n,dimensiunea matricei A
    cout << "Introduceti dimensiunea matricei= ";
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + 1; j++)
        {
            cout << "matrice" << "[" << i << "][" << j << "]=";
            cin >> matrice[i][j];
        }
    cout << endl;

    //afisare matrice A
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
            cout << matrice[i][j] << "  ";
        cout << endl;
    }

    //pasul2
    int k;
    for (k = 1; k <= n - 1; k++)
    {
        if (matrice[k][k] != 0)
        {
    //aplicam formulele din metoda Gauss(reg. dreptunghiului), adica ultima formula din (3)
            for (i = k + 1; i <= n; i++)
            {
                matrice[i][k] = matrice[i][k] / matrice[k][k];
                for (j = k + 1; j <= n + 1; j++)
                {
                    matrice[i][j] = matrice[i][j] - (matrice[i][k] * matrice[k][j]);
                }
            }
        }

    //blocul de instructiuni de la observatie
    // este implementata mai jos
        else
        {
            int lin;
            for (lin = k + 1; lin <= n; lin++)
            {
                lin = k;
                do
                {
                    lin = lin + 1;
                } while (matrice[lin][k] != 0 || lin > n);
                if (lin > n)
                {

                    cout << "sistemul nu are solutie unica";
                }

                for (j = k; j <= n + 1; j++)
                {
                    float aux;
                    aux = matrice[k][j];
                    matrice[k][j] = matrice[lin][j];
                    matrice[lin][j] = aux;
                }
            }
        }
    }

    //pasul3
    if (matrice[n][n] == 0)
    {
        cout << "sistemul nu are solutie unica";
    }

    //pasul4-determinam Xn aplicand formula (4)
    matrice[n][n + 1] = matrice[n][n + 1] / matrice[n][n];

    //pasul5-determinam xi,n-1>=i>=1, aplicand formulele (5)
    float suma;
    for (i = n - 1; i >= 1; i--)
    {
        suma = 0;
        for (j = i + 1; j <= n; j++)
        {
            suma = suma + matrice[i][j] * matrice[j][n + 1];
        }
        matrice[i][n + 1] = (matrice[i][n + 1] - suma) / matrice[i][i];
    }

    //pasul6
    for (i = 1; i <= n; i++)
    {
        cout << "x" << i << "=" << matrice[i][n + 1] << endl;
    }

}

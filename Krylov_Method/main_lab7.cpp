#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    float a[10][10],y[10][10];
    int n,i,j,k,linie,pivot;
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
pas2:
    for(int i=1; i<=n; i++)
    {
        cin>>y[i][n];
    }

    for(int j=n-1; j>=1; j--)
    {
        for(int i=1; i<=n; i++)
        {

            y[i][j]=0;
            for(int k=1; k<=n; k++)
            {

                y[i][j]=y[i][j]+(a[i][k]*y[k][j+1]);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        y[i][n+1]=0;
        for(int k=1; k<=n; k++)
        {
            y[i][n+1]=y[i][n+1]+(a[i][k]*y[k][1]);
        }
        y[i][n+1]=-y[i][n+1];
    }
    cout<<endl;
    cout<<"matricea este "<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n ; j++)
            cout << y[i][j] << "  ";
        cout << endl;
    }

    for (k = 1; k <= n - 1; k++)
    {
        pivot = fabs(y[k][k]);
        linie = k;
        for (i = k+1; i <= n; i++)
        {
            if(pivot<fabs(y[i][k]))
            {
                pivot = fabs(y[i][k]);
                linie = i;
            }
        }
        if(pivot==0)
        {
            cout << "sistemul nu are solutie unica "<<endl;
            cout<<"alegem alt yo "<<endl;
            goto pas2;
        }
        if (linie != k)
        {
            for (j = k; j <= n + 1; j++)
            {
                int aux;
                aux = y[k][j];
                y[k][j] = y[linie][j];
                y[linie][j] = aux;
            }
        }


        for (i = k + 1; i <= n; i++)
        {
            y[i][k] = y[i][k] / y[k][k];
            for(j=k+1; j<=n+1; j++)
            {
                y[i][j] = y[i][j] - y[i][k] * y[k][j];
            }
        }
    }

    if (y[n][n] == 0)
    {
        cout << "sistemul nu are solutie unica"<<endl;
        cout<<"alegem alt yo "<<endl;
        goto pas2;
    }

    y[n][n + 1] = y[n][n + 1] / y[n][n];


    float suma ;
    for (i = n - 1; i >= 1; i--)
    {
        suma = 0;
        for (j = i + 1; j <= n; j++)
        {
            suma = suma + y[i][j] * y[j][n + 1];
        }
        y[i][n + 1] = (y[i][n + 1] - suma) / y[i][i];

    }
    cout << "Solutiile sunt"<<endl;
    for (i = 1; i <= n; i++)
    {
        cout << "c" << i << "=" << y[i][n + 1] << endl;
    }

    return 0;
}

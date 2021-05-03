#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n, i, j,k,pivot,linie,coloana;
	float A[100][100],eps;
	int c[10][10], aux, npc;
	
	//npc-nr. permutari de coloana
	cout << "Valoare eps: ";
	cin >> eps;
	cout << endl;
	cout << "Introduceti dimensiunea matricei: ";
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n+1;j++)
		{
			cout << "A" << "[" << i << "]""[" << j << "]= ";
			cin >> A[i][j];
		}
	npc = 0;
	for (k = 1; k <= n - 1; k++)
	{
		pivot = fabs(A[k][k]);
		linie = k;
		coloana = k;
		for (j = k; j <= n; j++)
		{
			for (i = k; i <= n; i++)
			{
				if(pivot<fabs(A[i][j]))
				{
					pivot = fabs(A[i][j]);
					linie = i;
					coloana = j;
				}
			}
		}
		if(pivot<=eps)
		{
			cout << "sistemul nu are solutie unica" << endl;
		}
		if (linie != k)
		{
			for (j = k; j <= n + 1; j++)
			{
				aux = A[k][j];
				A[k][j] = A[linie][j];
				A[linie][j] = aux;

			}
		}
		if (coloana != k)
		{
			npc++;
			c[npc][1] = k;
			c[npc][2] = coloana;
			for (i = 1; i <= n; i++)
			{
				aux = A[i][k];
				A[i][k] = A[i][coloana];
				A[i][coloana] = aux;
			}
		}
		for (i = k + 1; i <= n; i++)
		{
			A[i][k] = A[i][k] / A[k][k];
			for (j = k + 1; j <= n + 1; j++)
			{
				A[i][j] = A[i][j] - A[i][k] * A[k][j];
			}
		}

	}
	if (A[n][n] <= eps)
	{
		cout << "sistemul nu are solutie unica"<<endl;
	}
	A[n][n + 1] = A[n][n + 1] / A[n][n];
	float suma;
	for (i = n - 1; i >= 1; i--)
	{
		suma = 0;
		for (j = i + 1; j <= n; j++)
		{
			suma = suma + A[i][j] * A[j][n + 1];
		}
		A[i][n + 1] = (A[i][n + 1] - suma) / A[i][i];
	}
	if (npc != 0)
	{
		for (i = npc; i <= 1; i++)
		{
			
			aux = A[c[i][1]][n + 1];
			A[c[i][1]][n + 1] = A[c[i][2]][n + 1];
			A[c[i][2]][n + 1] = aux;
		}
	}
	cout << "Solutiile sunt: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << A[i][n + 1] << endl;
	}
}
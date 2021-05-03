#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n, i, j,k,pivot,linie;
	float A[10][10];

	//pasul1
	cout << "Introduceti dimenisunea matricei: ";
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			cout << "A" << "[" << i << "]""[" << j << "]= ";
			cin >> A[i][j];
		}

	//pasul2
	
	for (k = 1; k <= n - 1; k++)
	{
		pivot = fabs(A[k][k]);
		linie = k;
		for (i = k+1; i <= n; i++)
		{
			if(pivot<fabs(A[i][k]))
			{
				pivot = fabs(A[i][k]);
				linie = i;
			}
			cout << "Valoarea pivotului este: " << A[i][k];
			cout << endl;
		}
		if(pivot==0)
		{
			cout << "sistemul nu are solutie unica";
		}
		if (linie != k)
		{
			int nr = 0;
			for (j = k; j <= n + 1; j++)
			{
				int aux;
				nr = k;
				aux = A[k][j];
				A[k][j] = A[linie][j];
				A[linie][j] = aux;
			}
			nr=nr+1;

		}
		cout << endl;
		cout << "Nr total de permutari este: " << A[linie][k]; //a[linie][k]=elementul cu valoarea totala
		cout << endl;

		for (i = k + 1; i <= n; i++)
		{
			A[i][k] = A[i][k] / A[k][k];
			for(j=k+1;j<=n+1;j++)
			{
				A[i][j] = A[i][j] - A[i][k] * A[k][j];
			}
		}
	}
	cout << "Pivotul se gaseste pe linia " << k << " si coloana " << i;
	cout << endl;
	cout << "Indicii liniilor ce au fost permutate sunt: " << linie <<" si " << k;
	cout << endl;
	


	//pasul3
	if (A[n][n] == 0)
	{
		cout << "sistemul nu are solutie unica";
	}

	//pasul4
	A[n][n + 1] = A[n][n + 1] / A[n][n];


	//pasul5
	float suma ;
	for (i = n - 1; i >= 1; i--)
	{
		suma = 0;
		for (j = i + 1; j <= n; j++)
		{
			suma = suma + A[i][j] * A[j][n + 1];
		}
		A[i][n + 1] = (A[i][n + 1] - suma) / A[i][i];

	}

	//pasul6
	cout << "Solutiile sunt: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << A[i][n + 1] << endl;
	}
}
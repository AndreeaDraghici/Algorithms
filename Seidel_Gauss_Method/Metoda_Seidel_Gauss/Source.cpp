#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, i, j;
	float a[10][10], b[10], eps, itmax, x[10], it, max, suma, y[10];

	cout << "grad matrice ";
	cin >> n;
	cout << "valoare precizie ";
	cin >> eps;
	cout << "nr maxim de iteratii ";
	cin >> itmax;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cout << "a" << "[" << i << "]""[" << j << "]= ";
			cin >> a[i][j];
		}
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "b" << "[" << i << "]""= ";
		cin >> b[i];
	}
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << "[" << i << "]""= ";
		cin >> x[i];
	}
	cout << endl;
	it = 0;
	do
	{
		max = 0;
		for (i = 1; i <= n; i++)
		{
			suma = 0;
			for (j = 1; j <= n; j++)
			{
				if (j != i)
				{
					suma = suma + a[i][j] * x[j];
				}
			}
			y[i] = (b[i] - suma) / a[i][i];
			if (max < fabs(y[i] - x[i]))
			{
				max = fabs(y[i] - x[i]);
			}
			x[i] = y[i];
		}
		
		it++;

	} while (!((max <= eps) || (it > itmax)));
	if (it > itmax)
	{
		cout << "nu se poate obtine solutia in " << itmax << " iteratii cu precizia " << eps << endl;;
	}
	for (i = 1; i <= n; i++)
	{
		cout << "solutia obtinuta in " << it << " iteratii cu precizia " << eps << " este " << x[i] << endl;
	}

}
#include<iostream>

using namespace std;

int main()
{
	int n,i,j,aux;
	float a[10][10],det;

	cout << "introduceti dimensiunea matricei: ";
	cin >> n;

	for(i=1;i<=n;i++)
		for (j=1; j<=n; j++)
		{
			cout << "a" << "[" << i << "]""[" << j << "]= ";
			cin >> a[i][j];
		}
	cout << endl;

	det = 1;
	do
	{
		if (a[1][1] == 0)
		{
			i = 2;
			while (i <= n && a[i][1] == 0)
			{
				i++;
			}
			if (i > n)
			{
				cout << "det(A)=0";
			}
			for (j = 1; j <= n; j++)
			{
				aux = a[1][j];
				a[1][j] = a[i][j];
				a[i][j] = aux;
			}
			det = (-det);

        }
		for (i = 1; i <= n - 2; i++)
		{
			det = det * a[1][1];
		}
		for (i = 2; i <= n; i++)
		{
			for (j = 2; j <= n; j++)
			{
				a[i][j] = a[i][j] * a[1][1] - a[i][1] * a[1][j];
			}
		}
		n--;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				a[i][j] = a[i + 1][j + 1];
			}
		}

	}while(!(n == 1));
	det = a[1][1] / det;

	cout << "det(A)= " << det;


}
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	float a[10][10],b[10][10],d[10][10],c[10];
    int n,i,j,k,h;

	
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}

	//initializam B cu matricea unitate In
	for(i=1;i<=n;i++)
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				b[i][j] = 1;
			}
			else
			{
				b[i][j] = 0;
			}
		}
	for (k = 1; k <= n - 1; k++)
	{
		//calculam Ak, folosind Ak=A*Bk-1, si notam D=Ak
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				d[i][j] = 0;
				for (h = 1; h <= n; h++)
				{
					d[i][j] = d[i][j] + a[i][h] * b[h][j];
				}
			}

		}

		//calculam Ck, folosind Ck=-Tr(Ak)/k;
		c[k] = 0;
		for (i = 1; i <= n; i++)
		{
			c[k] = c[k] + d[i][i];
		}
		c[k] = -c[k] / k;

        //calculam Bk, folosind Bk=Ck*In+Ak
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i == j)
				{
					b[i][j] = d[i][j] + c[k];
				}
				else
				{
					b[i][j] = d[i][j];
				}
			}
		}

	}
	//calculam An=D
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			d[i][j] = 0;
			for (h = 1; h <= n; h++)
			{
				d[i][j] = d[i][j] + a[i][h] * b[h][j];
			}
		}
	}
	//calculam Cn=-Tr(An)/n
	c[n] = 0;
	for (i = 1; i <= n; i++)
	{
		c[n] = c[n]+d[i][i];
	}
	c[n] = -c[n] / n;
	if (c[n] == 0) 
	{
	 cout << "Matricea nu este inversabila" << endl;
	}
	else
	{
      cout << "Matricea este inversabila" << endl;
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			//int idx = (-b[i][j] / c[n]);
			cout <<(-b[i][j])/c[n]<< "  ";
		}
		cout << endl;
	}
	cout << "Coeficientii polinomului caracteristic sunt: "<<endl;
	for (i = 1; i <= n; i++)
	{
	   cout << " "<<c[i];
	}
	
	return 0;
}
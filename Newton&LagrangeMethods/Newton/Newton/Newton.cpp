#include<iostream>


using namespace std;


int main()
{
	float  x[10], f[10], z[10], N, P, suma;
	int n, i, k, j,h;

	cout << "Nr de noduri= ";
	cin >> n;

	for (i = 0; i <= n; i++) {
		cout << "X" << "[" << i << "]""= ";
		cin >> x[i];
	}

	cout << endl;
	for (i = 0; i <= n; i++) {
		cout << "F" << "[" << i << "]""= ";
		cin >> f[i];
	}


	cout << endl;
	for (h = 0; h <= n; h++){
		cout << "Z" << "[" << h << "]""= ";
		cin >> z[h];
	}


for (h= 0; h <= n; h++)
{
		
	if ((z[h] >= x[0]) && (z[h] < x[n])) {

		N = f[0];
		for (k = 1; k <= n; k++)
		{
			suma = 0;
			for (j = 0; j <= k; j++)
			{
				P = 1;
				for (i = 0; i <= k; i++)
				{
					if (z[h] == x[i]) {
						N = f[i];
					}
					else
					{
						if (i != j) {
							P = P * (x[j] - x[i]);
						}
					}
				}
				suma = suma + f[j] / P;
			}
			P = 1;
			for (i = 0; i <= k - 1; i++){
				P = P * (z[h] - x[i]);
			}
			N = N + suma * P;
		}
		cout << endl;
		cout << "Valoarea aproximativa  functiei f in " << z[h] << " este " << N<<endl;
	}
	else {
			cout << endl;
			cout << "Nu putem aproxima f in " << z[h] << endl;
	}
  }
}


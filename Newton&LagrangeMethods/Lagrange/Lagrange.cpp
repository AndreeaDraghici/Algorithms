#include<iostream>


using namespace std;

int main()
{
	float  x[10], f[10], z[10], L,P;
	int n, i, k,j,m;

	cout << "Nr de noduri= ";
	cin >> n;
	
	
	for (i = 0; i <= n; i++){
		cout << "X" << "[" << i << "]""= ";
		cin>>x[i];
	}

	cout << endl;
	for (i = 0; i <= n; i++){
		cout << "F" << "[" << i << "]""= ";
		cin >> f[i];
	}


	cout << endl;
	for (j = 0; j <= n; j++)
	{
		cout << "Z" << "[" << j<< "]""= ";
		cin >> z[j];
	}

	for (j = 0; j <= n ; j++)
	{
		if ((z[j] >= x[0]) && (z[j] < x[n])) {

			L = 0;
			for (k = 0; k <= n; k++)
			{
				P = 1;
				for (i = 0; i <= n; i++)
				{
					if (z[j] == x[i]) {
						L = f[i];
					}
					else {
						if (i != k) {
							P = P * (z[j] - x[i]) / (x[k] - x[i]);
						}
					}
				}
				L = L + (f[k] * P);
				
			}
			cout << endl;
			cout << "Valoarea aproximativa a functiei f in " << z[j] << " este " << L << endl;
		}
		else {
			cout << endl;
			cout << "Nu putem aproxima f in " << z[j]<<endl;
		}
	}

}
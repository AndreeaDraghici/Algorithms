#include<iostream>
#include<math.h>
using namespace std;



float g(float x)
{
	return 4./ sqrt(x + 3);
}



int main()
{
	float X0, eps, itmax, it, X1, dif;

	cout << "Valoarea lui X0 este ";
	cin >> X0;

	cout << "Citeste valoarea lui eps ";
	cin >> eps;
	
	cout << "Nr maxim de iteratii este ";
	cin >> itmax;
	
	it = 0;

	do
	{
		X1 = g(X0);
		dif = fabs(X1 - X0);
		X0 = X1;
		it++;
	} while (!(dif <= eps) || (it > itmax));

	if (it > itmax)
	{
		cout << "Nu se poate obtine solutia in " << itmax << " iteratii cu precizia " << eps;
	}
   cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << eps << " este " << X1 << endl;
}
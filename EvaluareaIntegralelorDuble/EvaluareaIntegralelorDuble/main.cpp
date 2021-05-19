#include<iostream>
#include<math.h>

using namespace std;


float f(float x, float y)
{
     //return sqrt((x*y)-(y*y));
	//return ((x * y - 1) /( pow(x, 2) + pow(y, 2) + 1)); //pt exemplu 2, cel rezolvat in platforma de lab

	return (sqrt(y) / (sqrt(x) * (1 + x * y)));
}


int main()
{
	float x1, y1, x2, y2, x3, y3,x4,y4, latura1, latura2, latura3, aria, semiperimetru, integrala1,integrala2,integrala;

	cout << "Introduceti x1= ";
	cin >> x1;

	cout << "Introduceti y1= ";
	cin >> y1;

	cout << "Introduceti x2= ";
	cin >> x2;

	cout << "Introduceti y2= ";
	cin >> y2;

	cout << "Introduceti x3= ";
	cin >> x3;

	cout << "Introduceti y3= ";
	cin >> y3;

	latura1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	latura2= sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	latura3= sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	semiperimetru = (latura1 + latura2 + latura3) / 2;

	aria = sqrt(semiperimetru * (semiperimetru - latura1) * (semiperimetru - latura2) * (semiperimetru - latura3));
	integrala1 = (aria / 12) * (f(x1, y1) + f(x2, y2) + f(x3, y3) + 9 * f((x1 + x2 + x3) / 3, (y1+y2+y3) / 3));
	cout << "\n\nValoarea integralei primului triunghi este " <<" "<< integrala1<<endl;

	cout << "\n\nIntroduceti x1= ";
	cin >> x1;

	cout << "Introduceti y1= ";
	cin >> y1;

	cout << "Introduceti x3= ";
	cin >> x2;

	cout << "Introduceti y3= ";
	cin >> y2;

	cout << "Introduceti x4= ";
	cin >> x4;

	cout << "Introduceti y4= ";
	cin >> y4;

	latura1 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	latura2 = sqrt(pow((x3 - x4), 2) + pow((y3 - y4), 2));
	latura3 = sqrt(pow((x4 - x1), 2) + pow((y4 - y1), 2));
	semiperimetru = (latura1 + latura2 + latura3) / 2;

	aria = sqrt(semiperimetru * (semiperimetru - latura1) * (semiperimetru - latura2) * (semiperimetru - latura3));
	integrala2 = (aria / 12) * (f(x1, y1) + f(x3, y3) + f(x4, y4) + 9 * f((x1 + x3 + x4) / 3, (y1 + y3 + y4) / 3));
	cout << "\n\nValoarea integralei celui de al doilea triunghi este " << " " << integrala2 << endl;

	integrala = integrala1 + integrala2;
	cout << "\nValoarea integralei finale este " << integrala<<endl;

}
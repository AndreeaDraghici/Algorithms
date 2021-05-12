#include<iostream>
#include<math.h>

using namespace std;

float f(float x) {

    if (x >= -1 && x <= 0)
        return 0.4 * pow((1 + x), 3) + 0.6 * (1 + x) - 5 * x;
    if (x >= 0 && x <= 1)
        return 1 / (1 + x);
}

int main()
{
    float Integrala, h, b, a, Integrala_O, suma, eps, it;
    int n, i;
    cout << "Introduceti valoarea lui a: ";
    cin >> a;

    cout << "Introduceti valoarea lui b: ";
    cin >> b;

    cout << "Introduceti valoarea erorii eps: ";
    cin >> eps;

    n = 1;
    it = 1;

    Integrala = (f(a) + f(b)) * (b - a) / 2;
    do {
        n = 2 * n;
        h = (b - a) / n;
        Integrala_O = Integrala;
        suma = 0;
        for (i = 1; i <= n - 1; i++)
            suma = suma + f(a + i * h);
        Integrala= (f(a) + 2 * suma + f(b)) * h / 2;
        it++;
    } while (fabs(Integrala - Integrala_O) > eps);

    cout<<"\nValoarea integralei, obtinuta cu precizia "<<eps<<" este "<<Integrala<<endl;
    cout << "S-au realizat " << it << " pasi"<<endl;

    return 0;
}
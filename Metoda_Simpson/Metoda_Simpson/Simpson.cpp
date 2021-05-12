#include<iostream>
#include<math.h>

using namespace std;

float f(float x)
{
    return pow((x*x)+exp(x),1./4);
}

int main()
{
    float Integrala, h, b, a, Integrala_O, suma1,suma2, eps, it,n,i;
    
    std::cout << "Introduceti valoarea lui a: ";
    std::cin >> a;

    std::cout << "Introduceti valoarea lui b: ";
    cin >> b;

    std::cout << "Introduceti valoarea erorii eps: ";
    cin >> eps;

    n = 1;
    it = 1;

    Integrala = (f(a) +4*(f(a+b)/2)+f(b)) * (b - a) / 6;
    do {
        n = 2 * n;
        h = (b - a) / n;
        Integrala_O = Integrala;
        suma1 = 0;
        for (i = 1; i <= n - 1; i++)
        {
            suma1 = suma1 + f(a + i * h);
        }
        suma2 = 0;
        for (i =0; i <= n - 1; i++)
        {
            suma2 = suma2 + f(a + i * h + h / 2);
        }
        Integrala = (f(a) + (2 * suma1) +(4*suma2)+ f(b)) * h / 6;
        it++;
    } while (fabs(Integrala - Integrala_O) > eps);

    std::cout << "\nValoarea integralei, obtinuta cu precizia " << eps << " este " << Integrala << endl;
    std::cout << "S-au realizat " << it << " pasi" << endl;

    return 0;
}
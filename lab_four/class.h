#include <iostream>
#include <math.h>
using namespace std;
class Polynomial {
    int trinomial [4];
    int sextic [7];
public:
    Polynomial();
    Polynomial (int newFreeCoef, int newFirstCoef);
    Polynomial(int firstCoef, int secondCoef, int thirdCoef);
    Polynomial(int freCoef, int firstCoef, int secondCoef, int thirdCoef);
    Polynomial(int coefficientSextic[]);
    Polynomial createP1();
    Polynomial createP2();
    Polynomial createP3();
    void getTrinomial();
    void getSextic();
    int countPolynomialInPoint(Polynomial &);
    Polynomial operator+(Polynomial &);
    Polynomial operator*(Polynomial &);
};

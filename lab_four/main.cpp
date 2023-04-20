#include "class.h"
int main() {
    Polynomial P1, P2, P3, P4, P5 ;
    P1 = P1.createP1();
    P2 = P2.createP2();
    P3 = P3.createP3();

    cout<<"Start data"<<endl;
    cout<<"P1: ";
    P1.getTrinomial();
    cout<<"P2: ";
    P2.getTrinomial();
    cout<<"P3: ";
    P3.getTrinomial();

    P4 = P1 + P2;
    cout<<"P1+P2 = P4:"<<endl;
    P4.getTrinomial();
    P5 = P2*P3;
    cout<<"P2*P3=P5:"<<endl;
    P5.getSextic();
    P4.countPolynomialInPoint(P5);
    return 0;
}

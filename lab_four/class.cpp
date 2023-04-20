#include "class.h"

Polynomial::Polynomial() {
    for (int i = 0; i < size(trinomial); ++i) {
        trinomial[i]=0;
    }
    for (int i = 0; i < size(sextic); ++i) {
        sextic[i]=0;
    }
}
Polynomial::Polynomial(int newFreeCoef, int newFirstCoef) {
    trinomial[0]=newFreeCoef;
    trinomial[1]=newFirstCoef;
    trinomial[2]=3;
    trinomial[3]=4;
    for (int i = 0; i < size(sextic); ++i) {
        sextic[i]=0;
    }
}
Polynomial::Polynomial(int firstCoef, int secondCoef, int thirdCoef){
    trinomial[0]=2;
    trinomial[1]=firstCoef*(-1);
    trinomial[2]=secondCoef*(-1);
    trinomial[3]=thirdCoef*(-1);
    for (int i = 0; i < size(sextic); ++i) {
        sextic[i]=0;
    }
}
Polynomial::Polynomial( int freCoef, int firstCoef, int secondCoef, int thirdCoef) {
    trinomial[0]=freCoef;
    trinomial[1]=firstCoef;
    trinomial[2]=secondCoef;
    trinomial[3]=thirdCoef;

    for (int i = 0; i < size(sextic); ++i) {
        sextic[i]=0;
    }
}
Polynomial::Polynomial(int coefficientSextic[]) {
    for (int i = 0; i < size(sextic); ++i) {
        sextic[i]=coefficientSextic[i];
    }
    for (int i = 0; i < size(trinomial); ++i) {
        trinomial[i]=0;
    }
}

void Polynomial::getTrinomial() {
    for (int i = 0; i < size(trinomial); ++i) {
        if (i == 0) {
            cout << trinomial[i];
            continue;
        }

        //if value is negative
        if (trinomial[i] < 0) {
            cout << " - " << trinomial[i] * (-1)<<"x^"<<i;
            continue;
        }

        //else if value is positive
        cout << " + " << trinomial[i]<<"x^"<<i;
    }
    cout<<endl;
}

void Polynomial::getSextic() {
    for (int i = 0; i < size(sextic); ++i) {
        if (i == 0) {
            cout << sextic[i];
            continue;
        }
        //if value is negative
        if (sextic[i] < 0) {
            cout << " - " <<sextic[i] * (-1)<<"x^"<<i;
            continue;
        }
        //else if value is positive
        cout << " + " << sextic[i]<<"x^"<<i;
    }
    cout<<endl;
}

Polynomial Polynomial::operator+(Polynomial &secondPolynomial) {
    int free, first, second, third;
    free = trinomial[0] + secondPolynomial.trinomial[0];
    first =trinomial[1] + secondPolynomial.trinomial[1];
    second =trinomial[2] + secondPolynomial.trinomial[2];
    third =trinomial[3] + secondPolynomial.trinomial[3];
    Polynomial P4 (free, first, second, third);
    return P4;
}

Polynomial Polynomial::operator*(Polynomial &secondPolynomial) {
    int arrayResult[7];
    arrayResult[0]=trinomial[0]*secondPolynomial.trinomial[0];
    arrayResult[1]=(trinomial[0]*secondPolynomial.trinomial[1])+(trinomial[1]*secondPolynomial.trinomial[0]);
    arrayResult[2]=(trinomial[0]*secondPolynomial.trinomial[2])+(trinomial[1]*secondPolynomial.trinomial[1])+(trinomial[2]*secondPolynomial.trinomial[0]);
    arrayResult[3]=(trinomial[0]*secondPolynomial.trinomial[3])+(trinomial[1]*secondPolynomial.trinomial[2])+(trinomial[2]*secondPolynomial.trinomial[1])+(trinomial[3]*secondPolynomial.trinomial[0]);
    arrayResult[4]=(trinomial[1]*secondPolynomial.trinomial[3])+(trinomial[2]*secondPolynomial.trinomial[2])+(trinomial[3]*secondPolynomial.trinomial[1]);
    arrayResult[5]=(trinomial[2]*secondPolynomial.trinomial[3])+(trinomial[3]*secondPolynomial.trinomial[2]);
    arrayResult[6]=trinomial[3]*secondPolynomial.trinomial[3];
    Polynomial P5 (arrayResult);
    return P5;

}

int Polynomial::countPolynomialInPoint(Polynomial &P5) {
    int x=0, count=0;
    cout<<"Enter point"<<endl;
    cin>>x;
    for (int k = 0; k < size(trinomial); ++k) {
            count += int(trinomial[k] * (pow(x, k)));
        }
    cout<<"Value for P4:"<<count<<endl;
    count=0;
    for (int k = 0; k < size(P5.sextic); ++k) {
        count += int(P5.sextic[k] * (pow(x, k)));
    }
    cout<<"Value for P5:"<<count;
    return count;
}

Polynomial Polynomial::createP1() {
    int freeCoef=0, first=0;
    bool mistake;
    do {
        mistake= false;
        cout << "Enter free and first coefficient in P1, can`t be zero:" << endl;
        cin >> freeCoef >> first;
        if ((freeCoef==0)||(first==0)){
            cout<<"You have mistake"<<endl;
            mistake= true;
            cin.clear();
            cin.ignore();
        }
    } while (mistake);
    Polynomial P1(freeCoef, first);
    return P1;
}

Polynomial Polynomial::createP2() {
    int first=0, second=0, third=0;
    bool mistake;
    do {
        mistake= false;
        cout << "Enter first second third coefficient in P2:" << endl;
        cin >> first >> second >> third;
        if ((first==0)||(second==0)||(third==0)){
            cout<<"You have mistake"<<endl;
            mistake= true;
            cin.clear();
            cin.ignore();
        }
    } while (mistake);
    Polynomial P2(first, second, third) ;
    return P2;
}

Polynomial Polynomial::createP3() {
    int free=0, first=0, second=0, third=0;
    bool mistake;
    do {
        mistake= false;
        cout << "Enter free first second third coefficient in P3:" << endl;
        cin >> free >>first >> second >> third;
        if ((free==0)||(first==0)||(second==0)||(third==0)){
            cout<<"You have mistake"<<endl;
            mistake= true;
            cin.clear();
            cin.ignore();
        }
    } while (mistake);
    Polynomial P3(free, first, second, third) ;
    return P3;
}







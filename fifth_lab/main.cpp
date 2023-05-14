#include "TMatrix.h"

int main() {
    int detA = 0, detB = 0, sumA = 0, result = 0;
    srand(time(nullptr));

    TMatrix *ar[2];
    ar[0] = new matrixA();
    ar[1] = new matrixB();
    ar[0]->print();
    ar[1]->print();
    detB = ar[0]->countDeterminant();
    detA = ar[1]->countDeterminant();
    sumA = ar[0]->countSum();
    result = sumA + detA + detB;
    cout<<"S = sum matrix A + det matrix A + det matrix B = "<<result<<endl;
    delete ar[1];
    delete ar[0];

    return 0;
}

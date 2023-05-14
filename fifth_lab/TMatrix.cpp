//
// Created by Kira on 14.05.2023.
//

#include "TMatrix.h"

TMatrix::TMatrix(int newSize) {
    size = newSize;
    values = new int [size];
    fillRandom();
}

void TMatrix::fillRandom() {
    for (int r= 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            values[size * r + c] = rand() % (100 + 1) - 50;
}

TMatrix::~TMatrix() {
    delete [] values;
}


matrixA::matrixA(): TMatrix(3){}

void matrixA::print() {
    cout<<"Matrix 3x3:"<<endl;
    cout << fixed << setprecision(1);
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            int index = size * r + c;
            cout << (c > 0 ? " " : "") << setw(3);
            cout << values[index];
        }
        cout << std::endl;
    }
}

int matrixA::countDeterminant() {
    int det=0;
    det = (values[0] * values[4] * values[8] + values[1] * values[5] * values[6] + values[2] * values[3] * values[7])-(values[2] * values[4] * values[6] + values[0] * values[5] * values[7] + values[1] * values[3] * values[8]);

    cout<<"Determinant 3x3: "<<det<<endl;
    return det;
}

int matrixA::countSum() {
    int sum=0;
    for (int i = 0; i < pow(size,2); i++) {
       sum +=values[i];
    }
    cout<<"Sum 3x3: "<<sum<<endl;
    return sum;
}

matrixA::~matrixA() {};


matrixB::matrixB() : TMatrix(2){}

void matrixB::print() {
    cout<<"Matrix 2x2:"<<endl;
    cout << std::fixed << std::setprecision(1);
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            int index = size * r + c;
            cout << (c > 0 ? " " : "") << std::setw(5);
            cout << values[index];
        }
        cout << std::endl;
    }
}

int matrixB::countDeterminant() {
    int det = 0;
    det = (values[0] * values[3]) - (values[1] * values[2]);
    cout <<"Determinant 2x2: "<< det << endl;
    return det;
}

int matrixB::countSum() {
    int sum=0;
    for (int i = 0; i < pow(size,2); i++) {
        sum +=values[i];
    }
    cout<<"Sum 2x2: "<<sum<<endl;
    return sum;
}

matrixB::~matrixB() {}
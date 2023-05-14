//
// Created by Kira on 14.05.2023.
//

#ifndef POLIMORF_TMATRIX_H
#define POLIMORF_TMATRIX_H

#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

class TMatrix {
protected:
    int size;
    int *values;
public:
    TMatrix(int);
    void fillRandom();
    virtual int countDeterminant()=0;
    virtual int countSum() = 0;
    virtual void print() = 0;
    virtual ~TMatrix();
};

class matrixA : public TMatrix {
public:
    matrixA();
    int countDeterminant() override;
    int countSum() override;
    void print() override;
    ~matrixA() override;
};

class matrixB : public TMatrix {
public:
    matrixB();
    int countDeterminant() override;
    int countSum() override;
    void print() override;
    ~matrixB() override;
};

#endif //POLIMORF_TMATRIX_H

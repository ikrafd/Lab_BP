#include "function.h"

functionLog::functionLog(float inputNumber): x(inputNumber)
{

}

float functionLog:: calculate(){
    float result =0;
    if (x > 2 && x!=3){
        result = log(x) / log(x - 2);
    }else if (x ==0 || x == 2 ) {
        throw invalid_argument("Неможливо обрахувати логарифм від 0");
    } else if (x<2 && x!=0) {
        throw invalid_argument("Неможливо обрахувати логарифм від від'ємного числа");
    } else if (x==3){
        throw invalid_argument("Ділення на 0");
    }
    return result;
}

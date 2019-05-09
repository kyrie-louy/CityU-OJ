#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int max_Num;
int tempStore[24];
int subseq_first, subseq_second;

void getMaxNumber(int maxBit){
    for (int i = maxBit; i >= 1; i--) {
        max_Num += pow(2.0, (double)i);
    }
}

void getFirstSubSeq(int value, int bitNumber){
    
    // ini
    subseq_first = 0;
    subseq_second = 0;
    for (int i = 0; i<24; i++) {
        tempStore[i] = 0;
    }
    
    int index = 0;
    while (value >= 1) {
        tempStore[index++] = value %2;
        value /= 2;
    }
    
    for (int i = 0; i < bitNumber; i++) {
        subseq_first += tempStore[i]*pow(2.0, i);
    }
    
    for (int i = 1; i <= bitNumber; i++) {
        subseq_second += tempStore[i]*pow(2.0, (i-1));
    }
}

int decToBinary(int dec){
    int result = 0, temp = dec, j = 1;
    while (temp) {
        result += j*(temp%2);
        temp /= 2;
        j *= 10;
    }
    return result;
}


int main(){
    string str;
    getline(cin, str);
    
    double len = (double)str.length();
    double max_Bit = (log(len)/ log(2.0)) + 1;
    int max_Bit_Int = (int) max_Bit;
    
    // inilizatiation the maximum number
    max_Num = 0;
    getMaxNumber(max_Bit_Int);
    
    // ini arr
    bool* arr = new bool[max_Num];
    for (int i = 0; i < max_Num; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < len-max_Bit_Int+1; i++) {
        int value = 0;
        double bit_temp = 0;
        for (int j = i+max_Bit_Int-1; j >= i; j--) {
            value += ((str[j]-48) * pow(2.0, bit_temp));
            bit_temp++;
        }
        arr[value] = 1;
    }
    
//    // only for test
//    for (int i = 0; i < max_Num; i++) {
//        printf("%d ",arr[i]);
//    }
    
    
    // 2: visited, 1: visiting
    while (max_Bit_Int >= 1) {
        max_Bit_Int--;
        for (int i = 0; i < max_Num; i++) {
            if (arr[i] == 1) {
                getFirstSubSeq(i, max_Bit_Int);
                arr[subseq_first] = 1;
                arr[subseq_second] = 1;
                arr[i] = 2;
            }
        }
    }
//    // only for test
//    for (int i = 0; i < max_Num; i++) {
//        printf("%d ",arr[i]);
//    }
    // record answer
    for (int i = 0; i < max_Num; i++) {
        if (arr[i] == 0) {
            printf("%d\n",decToBinary(i));
            break;
        }
    }
    delete [] arr;
    return 0;
}


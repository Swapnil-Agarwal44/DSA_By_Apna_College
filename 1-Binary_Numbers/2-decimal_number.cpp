// write a program to convert a binary number into's it's deciaml format.

#include<bits/stdc++.h>
using namespace std;

void decimal_numbers(int n){
    int d_number = 0;
    int remainder;
    int power = 1;
    while(n>0){
        remainder = n%10;
        n/=10;
        d_number += (remainder*power);
        power *= 2;

    }
    //Although the logic is correct, but this code cannot be used to calculate the value of bigger numbers because the binary numbers of that big numbers will overflows the integer data type capacity. 
    
    cout<<"The binary number is:"<<d_number;
}
int main(){
    int number;
    cout<<"Enter the number";
    cin>>number;
    decimal_numbers(number);
    return 0;
}
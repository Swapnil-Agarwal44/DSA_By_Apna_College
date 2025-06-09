// write a program to convert a number into it's binary format. 

#include<bits/stdc++.h>
using namespace std;

void binary_numbers(int n){
    int b_number = 0;
    int remainder;
    int power = 1;
    while(n>0){
        remainder = n%2;
        n/=2;
        b_number += (remainder*power);
        power *= 10;

    }
    //Although the logic is correct, but this code cannot be used to calculate the value of bigger numbers because the binary numbers of that big numbers will overflows the integer data type capacity. 
    
    cout<<"The binary number is:"<<b_number;
}
int main(){
    int number;
    cout<<"Enter the number";
    cin>>number;
    binary_numbers(number);
    return 0;
}
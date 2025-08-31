#include<iostream>
using namespace std; 

string isPrime(int n){
    for(int i = 2; i*i <=n ; i++){
        if(n%i==0){
            return "The given number is not prime";
        }
    }
    return "The given number is prime";
}

int main(){
    int n = 57; 
    cout<<isPrime(n)<<endl;
    return 0;
}


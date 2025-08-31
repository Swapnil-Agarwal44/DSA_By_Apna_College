// to find the gcd of hcf of two number, the first brute force approach is to just start a loop, and find the number, which is dividing both of the numbers, till we reach the smallest of them. 

// This is the following algorithm of the brute force method.


int gcd = 1; 
for(int i = 1; i<= min(a,b); i++){
    if(a%i == 0 && b % i == 0){
        gcd = i; 
    }
}
return gcd; 




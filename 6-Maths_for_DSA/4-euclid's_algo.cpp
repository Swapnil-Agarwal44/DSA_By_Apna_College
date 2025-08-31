// to find the hcd of the two numbers, another more optimized method is called euclid's algorithm, in which we try to find the difference between the modulo of the largest number with respect to the smallest number, and that of the smallest number, until and unless one of the number becomes zero, so that the corresponding non zero number will be the hcf of the two numbers. 



// simple function: 

int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        } else {
            b=b%a;
        }
    }
    if(a==0) return b; 
    return a;
}


// recursive approach:

int gcdRec(int a, int b){ // in the recursive function itself, we will consider that the first argument passed will always be the greater number among them. 

    if(b==0) return a; 
    
    return gcdRec(b, a%b); // since we are considering the first argument to be the greatest, in this also we will have to pass the smaller value first, because we will be taking the modulo of the greater number with respect to that of the smaller number, so this value will become smaller than that of the previous smaller number. 
    
}
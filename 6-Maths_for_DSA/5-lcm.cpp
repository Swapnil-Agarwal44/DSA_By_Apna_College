// to find the lcm of the two numbers, the most optimized approach is to first find the gcd or hcf of the two numbers, because product of the two numbers is equal to the product of the gcd and lcm of the two numbers. 

// a * b = gcd(a, b)  * lcm(a, b)

// so dividing the product of the two numbers with that of the gcd of the two numbers, will give us with the lcm of the two numbers. 


int lcm(int a, int b){
    int gcd = gcd(a, b);
    return (a*b) / gcd;
 }
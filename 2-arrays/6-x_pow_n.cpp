// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104


// In this question, we have to simply find the power of the x raised to n. We can do this using simple for loop. However, then we will have time complexity of this question in o(n). And we won't be able to solve this question, if the value of n is too large. To solve this question in leetcode, we have to use another method to reduce it's time complexity. 

// The algorithm which we have to use in this question is the use of the binary form of the n. In this algorithm, we will use the binary form of the power n. Starting from the one's digit of the binary form, we will check if it's 1, then only we will multiply it with the x, and then we will double the value of x. If it's 0, then we will simply double the value of x. Because of this, we won't have to use the higher number of loops to find the value of the larger power of x. And then we will simply find our answer by multiplying with the previous values of x. 

// For example, find 3^5, where x = 3, n = 5; Convert n = 5 to its boolean, i.e. 101. And starting from the one's digit, if digit is 1, multiply it with x. And then double the value of x. Following this approach, we will have to just multiply 3^4 and 3^1 and since we are also doubling the value of x every time after the loop, we will already have the value of the 3^4 after looping just 3 times, instead of 5 times. So this is the concept. 


class Solution {
public:
    double myPow(double x, int n) {
    
        long a = n;
       if(a<0){
        x = 1/x;
        a = -a;
       }

        long binForm = a;
       double ans = 1; 

       while(binForm > 0){
        if(binForm % 2 == 1){
            ans *= x;
        }
        x *= x; 
        binForm /= 2; 
       } 

       return ans; 
    }
};
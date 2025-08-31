// 204. Count Primes
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an integer n, return the number of prime numbers that are strictly less than n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Approach:

// In the above question, if we check the count of prime number below the given number n using brute force, then as our test cases are very large numbers as well, therefore we can get TLE.
// To execute this code efficiently, we will use a very important algorithm called Sieve of Eratosthenes. In this approach, we consider create a boolean vector of size (n+1), as it will represent numbers from 0 to n, and will initialize the values to true as will consider each value to be Prime. So starting from 2, we it is prime, will convert all the multiples of the number 2 to false in the isPrime vector, so they all are non_prime. Now moving to next number, that is 3, will again do the same for this number as well. 
// We will also initialize the variable count, and will increase it whenever we will find a prime number, since we have been asked to submit a prime number. 




class Solution {
public:
    int countPrimes(int n) {
     vector<bool> isPrime(n+1, true);
     int count = 0;
     for(int i = 2; i<n; i++){
        if(isPrime[i]){
            // cout<<"The prime number is:" << 
            count++;
            for(int j=i*2; j<n; j=j+i){
                isPrime[j] = false;
            }
        }
     }
     return count;  
    }
};
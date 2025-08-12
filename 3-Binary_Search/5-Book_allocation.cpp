// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i], k ≤ 103


// Approach:

// In this question, we have to find the minimum value of the maximum pages that can be held by a student. 
// The order of the array won't be in a sorted manner, so we cannot direcly apply the binary search to that array. For solving this question, we have to use the different approach. 
// So what we can do is that we can find the min and max number of pagest that a student can have, right now without considering the conditions given. So the min will be 0, and the max will be the sum of all the values of the array. Now we have a min and max values, and now we will apply binary search in this question, and then check whether the mid value is valid or not through isValid() function. 
// We have to find whether the mid value is valid or not on the basis that if there is no case such that the minimum number of maximum pages held by students, after following the conditions, is equal to mid, or is always greater than mid, then it won't be valid. Even if one value is smaller than the mid, then it is valid. 
// To find the mid value we will have two variable with s = 1; and t = 0; and then we will simply travese the original book array, and add the value of the pages in a variable t. On adding the new values of array, we will check if the variable t will be larger than the mid value given or not. If not, we will simply add the new value, otherwise we will increase the count of the s variable and assign the present array value to the t. 
// After traversing the array, we will check the total number of s, if it smaller or equal to the original number of students, then we will return true else false. 


class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
    int sum = 0;
    int n = arr.size();
    int start = 0; 
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int end = sum; 
    int ans = -1; 
    
    if(k > n){
        return -1; 
    }
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isValid(arr, n, k, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid + 1; 
        }
    }
    return ans;
}

bool isValid(vector<int> &arr, int n, int k, int mid){
    int s = 1; 
    int total = 0; 
    
    for(int i = 0; i < n; i++){
        if(arr[i]>mid){
            return false;
        }
        if(total+arr[i] <= mid){
            total += arr[i];
        }else{
            s++; 
            total = arr[i];
        }
    }
    
    if(s<=k) return true;
    else return false;
    
}
    
};
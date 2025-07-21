// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


// APPROACH: 

// in this question, the first brute force approach that we can use to solve this question is that we will have an outer loop, that is followed by an inner loop, and we will multiply the elements of inner loop, until and unless the inner element and outer element are same. If they are same, we won't multiply. In this way, we will get the products of all the elements except self for each element, however, it's time complexity will be O(n^2), and given the contraints of the question, it will give a TLE. 



// in this approach, we tried to created 2 arrays, one is called prefix and the second is called suffix. In the prefix array, we will insert the values of the prefix values of the elements of nums array, and in the suffix array, we will store the values of the suffix values of the elements of the nums array, and then we will multiply both the arrays, to return the desired array. 

// Also to further optimize the space complexity, so that the solution always occupies only o(1) constant space complexity, and since the returned ans array won't be counted in the complexity, so we can just initialize the ans array with all the elements being 1, then we will fill it up with the prefix values of the loop, and then instead of initializing another suffix array to multiply with the prefix array, we will again traverse in the ans array from the end, and will multiply the elements with the suffix values of the nums elements, thus we won't have to use another arrays. 

// To find the prefix value of the current element of the nums, we will multiply the prefix of its predecessor with the predecessor elements itlsef, to get the prefix of the current element, same has to be done with the suffix as well. That same approach has been used in this approach.  

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1; 
        int suffix = 1; 

        ans[0] = 1; 
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1]; 
        }

        for(int j = n-1; j>= 0; j--){
            ans[j] = ans[j] * suffix; 
            suffix *= nums[j]; 
        }

        return ans; 
    }
};
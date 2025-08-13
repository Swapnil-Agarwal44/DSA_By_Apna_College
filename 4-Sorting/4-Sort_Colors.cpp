// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?


//Approach 1: 

// The first approach that we can do is to just sort the array using the sort function of the C++ library. However, in the given question, it has been explicitly asked to avoid the sort function. Also the time complexity of the sort function is O(nlogn). So what we can do is we can count the number of times that the colors are repeated. For example, as we know that there are only three colors, then in one single loop we can count the number of occurences of these three colors, and then in the next seperate loop, we can push the values of these color integers from the beginning of the array, based on the number of their occurances. 


class Solution {
public:
    void sortColors(vector<int>& nums) {
      int red = 0; 
      int white = 0; 
      int blue = 0; 

      for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            red++;
        }else if(nums[i] == 1){
            white++;
        }else{
            blue++;
        }
      }  
        int j; 
      for( j = 0; j < red; j++){
        nums[j] = 0;
      }
      while(j < red+white){
        nums[j] = 1; 
        j++;
      }
     while(j < red+white+blue){
        nums[j] = 2; 
        j++;
      }

    }
};





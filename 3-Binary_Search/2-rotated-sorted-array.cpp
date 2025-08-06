// 33. Search in Rotated Sorted Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies


// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104



//Solution approach: 

// In this approach, the array that is being given to us, is a rotated sorted array, so we are going to find the answer by deciding whether we have to check the left half of the array or the right half of the array. 
// because there may be a transitioning point anywhere in the array, we cannot simply use the binary search. However, one of the either sides will be fully in the sorted manner, and in that side we can apply the binary search. 
// If the first value of the array is smaller than the mid value, than the left side is sorted, and we will check if the target is between the lowest and highest value of that subarray, if not we will check the right array. 
// If the first value of the array is not smaller thatn the mid value, then the right side is sorted, and we will repeat the above process. 
// Here is the code. 




class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() -1;
        while(first <= last){
            int mid = first + (last-first)/2;
            if(nums[mid] == target){
                // cout<<mid;
                return mid; 
            }
            if(nums[first] <= nums[mid]){
                if(nums[first] <= target && target <= nums[mid]) {
                    last = mid-1; 
                }else{
                    first = mid+1 ;
                }
            } else{
                if(nums[mid] <= target && target <= nums[last]){
                    first = mid+1 ;
                }else{
                    last = mid-1;
                }
            }
        }
        return -1;
    }
};
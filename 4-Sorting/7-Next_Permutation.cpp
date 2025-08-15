// 31. Next Permutation
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100




// Approach:

// In this question, we will find the pivot index of the array, whose value is lower than it's next value, starting from the end of the array. This can be understood if we will recognize the pattern of the examples.  
// Then we will find the smallest value greater than the pivot in the elements occuring after the pivot, and swap them. 
// Then we will sort the remaining elements, after the pivot position, either through sort function, or just be reversing the array, by double pointer approach. 


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot=-1;
        int n = nums.size(); 
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){
            sort(nums.begin(), nums.end());
            return;
        }
        int min = INT_MAX;
        int min_idx;
        for(int i = pivot+1; i<n; i++){
            if(nums[i]<min && nums[i]>nums[pivot]){
                min=nums[i];
                min_idx=i;
            }
        }
        swap(nums[pivot], nums[min_idx]);
        sort(nums.begin()+pivot+1, nums.end());
        
    }
};
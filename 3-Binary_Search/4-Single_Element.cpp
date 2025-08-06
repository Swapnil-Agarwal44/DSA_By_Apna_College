// 540. Single Element in a Sorted Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105




// Approach: 

// In this question we have to find the number which only appears once, whereas the other numbers will appear twice. 
// To solve the question in O(logn), we have to apply the binary search. As always, we have to utilize the concept through which we can decide which side we have to check on next iteration, left side or right side of the mid value. Finding this concept is the main core of the binary search problems. 
//In this appraoch we know there will double values of the numbers, except for only one value, and they will be arranged in soreted manner. So we can say that the array will always have odd number of elements. Now on finding the mid value of the array, we will check whether to move left or right. For that we will check if the mid value's duplicate(if it's not singular value, in which we will return it as the answer) lies on the left side or it's right side. Since the array is odd numbered, then both left and right sides subarray will be even numbered. If the duplicate number is in the left side, then that means the left subarray, without the duplicate number will have odd number of values, which can be only possible if it has a singular number. Otherwise we will look for the right side. 
// So we can say that the subarray contains a singular element if it has odd numbers of values. Based on this logic, we will apply the binary search. 






class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int first = 0; 
        int last = nums.size() -1; 

        if(last == first){
            return nums[first];
        }

        while(first<= last){
            int mid = first + (last-first)/2;


             if(mid == 0 && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if(mid == nums.size()-1 && nums[mid] != nums[mid-2]){
                return nums[mid];
            }
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

           
            if(mid%2 == 0){
                if(nums[mid-1] == nums[mid]){
                    last = mid-1;
                }else{
                    first = mid+1;
                }
            }else{
                if(nums[mid-1] == nums[mid]){
                    first = mid+1;
                }else{
                    last = mid-1;
                }
            }
        }
        return -1; 
    }
};
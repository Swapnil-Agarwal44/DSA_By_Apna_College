// 852. Peak Index in a Mountain Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.



//Aproach: 
// In this question, we have to find the index of the peak value of the array, which will be the greatest number. However, by doing simple linear search will give a time complexity of O(n), and the question asks for the time complexity of O(logn). To achieve that we will use the concept of binary search. 
// First we will find the mid value. Then we will check if it lies in the increasing slope or the decreasing slope of the mountain. If the mid is in the increasing slope, then we will not check for the left side of the slope, and will check only for the right side of the slope. Similary, if the mid is in the decreasing slope, then we will check for the left side of the slope. So in this way, binary search is helping us avoid the half of the array, thus reducing the time complexity. 
// To check for slope on which the mid value lies, if the mid value if larger than the previous value, then it lies on the increasing slope, else it will lie on the decreasing slope. 
// Also we have to take note of an important optimization that we have to use in this question. Since the mid value can go to any of the index, we have to check in the case the mid value become the first or the last index of the array, because in that case we won't be able to check if it's the peak value or not because we won't be able to compare it with either the previous value or the next value respectively due to condition of overflow. So either we can apply individual checks, but that will create a lot of confusion, and will make a very hectic code. Or we can just initialize our start variable with second value of the array, and the last variable with the second last value of the array, i.e. :     int start = 1; int last = arr.size() -2;  this is because we know that the first and the last value cannot be the answer, because in that case there won't be any mountain formed, so we can just exclued those cases from our loops, and now there won't be any problem. 




class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1; 
        int last = arr.size() -2; 

        while(start <= last){
            int mid = start + (last - start)/2;
               
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid; 
            }
            else if(arr[mid-1]<arr[mid]){
                start = mid + 1; 
            }else{
                last = mid - 1;
            }
            
        }
        return -1;
    }
};

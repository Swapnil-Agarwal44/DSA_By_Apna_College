// This is another solution to the previous problem. 

// We are going to use a very popular and important algorithm called Dutch National Flag Algorithm. 

// In this algorithm, we will use three pointers, called low, mid, high. 

// In this algorithm certain points and steps have to be remmebered:
// We store the unsorted array between the mid and high index (we initialize the mid with the zero value, and the high with the last index of the array vector )
// Then if the mid value is 0, then we will swap the values of the low index with that of the mid index, and increase both the variables.
// If the mid value is 1, then we will simply increase the value of mid.
// If the mid value is 2, then we will swap the values of mid and high and decrease the value of high. 


// The idea behind the algorithm is that, we will store the 0th value in the range of before low - 1 index of the array, will store the 1th value in the range of the l and m-1 index of the array, and 2nd value in the h+1 and n-1 value of the array. 




class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n = nums.size();  
      int mid = 0, high = n-1, low = 0;

      while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++; 
            mid++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
      }

    }
};
// Majority Element 

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2


#include<bits/stdc++.h>
using namespace std;

int majorityElement_BruteForce(vector<int>& nums) {

// this function's time complexity is O(n^2)

        int size = nums.size();
        int n = size/2;
        int answer;
        for(int i = 0; i < size; i++){
             int count = 1;
            for(int j = i+1; j < size; j++){
                if (nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > n){
                answer = nums[i];
                break;
            }
        }
        return answer; 
    }

    
int majorityElement_UsingSorting(vector<int>& nums) {

// this function's time complexity if o(nlogn)

        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        int ans = nums[0];
        int count = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                count++; 
            }else {
                count = 1; 
                ans = nums[i];
            }
            if(count > n){
                return ans;
            }
        }
        return ans;
    }

int main(){
    vector<int> vec = {1, 1, 2, 4, 4, 4, 4, 4 };
    int ans = majorityElement_UsingSorting(vec);
    cout<<"The answer of the problem is: " << ans;
    return 0;
    
}
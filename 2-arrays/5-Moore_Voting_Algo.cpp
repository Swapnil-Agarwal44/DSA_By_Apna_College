// this algorithm is used to find the most optimized approach for the previous Majority_Element problem.
// the core intitution of the algorithm is that if we have to find an element whose frequency is greater than the half of the length of the array, then that element has the highest frequency among all the elements. 
// Using this intitution, we can use the method in which we will assume the first element to have the greatest frequency, and then we will traverse through the array, if the next element found is same as the previous one, then we will increase the frequency by 1, and if it is not, then we will reduce the frequency by 1. And since the number with the highest frequency( count > n/2 ) will never be negative, even if we subtract all the remaining counts from this frequency, using this thought, we can find the number with the highest frequency. So if the frequency gets negative, then we will change to the next and consider it our answer, and similarly repeat the process. 



#include<bits/stdc++.h>
using namespace std;

int majorityElement_Moore_Voting(vector<int>& nums) {

// this function's time complexity is O(n) and is the most optimized solution for this problem.

        int ans = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (count > 0) {
                if (nums[i] == ans) {
                    count++;
                } else {
                    count--;
                }
            }else{
                ans = nums[i];
                count = 1;
            }
        }

        return ans;
    }

int main(){
    vector<int> vec = {1, 1, 2, 4, 4, 4, 4, 4 };
    int ans = majorityElement_Moore_Voting(vec);
    cout<<"The answer of the problem is: " << ans;
    return 0;
}
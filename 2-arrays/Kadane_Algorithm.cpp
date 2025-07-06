// This algorithm is used to solve the maximum subarray sum problem using the most optimized approach. 
// In this algorithm, the main intitution is that when we add a greater positive number and smaller negative number, the result is still positive. Conversely, if add the greater negative number, and the smaller positive number, then the sum is negative. So in the array, we can add the numbers, untill and unless we come across the value, which is more negative than the sum of the previous values, which can result in the sum going below 0. In that case, we won't take that number in any of the subarray. 
// In this algorithm, the core concept is that, we will start from the beginning of the array, and traverse it to the last, while storing the sum of all the values, and if there comes the value, which is negative, then we will compare the addition of that value with that of the previous values, and choose the maximum of them all. And if the answer is going negative becasue of that value, we will never take that value in any of the subarray. 


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int check_sum_by_Kadane_Algo(vector<int>& nums){

    // we can use the Kadane's algorithm for the most opimized version. 

        int sum = 0; 
        int finalSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            finalSum = max(finalSum, sum);
            if(sum<0) 
            sum = 0;
        }
        return finalSum;
}

int main(){
    int size;
    cout<<"Enter the size of the the array, that you want to create : ";
    cin>>size;
    vector<int> vec1(size, 0); 
    cout<<"Enter the values of the array: " ;
    int num, sum;

    for(int i = 0; i < size; i++){
        cin>>vec1[i];
    }

    sum = check_sum_by_Kadane_Algo(vec1);
    cout<<"The maximum sum of the subarray is : " << sum ;
    return 0;
}
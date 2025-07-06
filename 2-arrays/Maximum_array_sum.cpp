// in this question, we have to find the maximum sum of the subarray from a given array. 
// ex: given array : [3, -4, 5, 4, -1, 7, -8], so the maximum sum of the subarray can be 15 (by having the subarray of 5,4,-1,7)

// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int check_Maximum_Subarray_Sum(vector<int>& vect){
    // to find the size of the maximum subarray value, we can have two brute force techniques. 
    // First is to find all the subarrays, and store their sums. However, their time complexity will be of O(n^3)
    // Another more opimized method is to have a variable that stores the sum of the subarray, and when that subarray is expaned to included more values, we just add that values into the previous sum, which can help us in avoiding another loop, thus reducing the time complexity to o(n^2);

    // we will use the start and end variables to iterate throgh the arrays

    int finalsum = INT_MIN;
    for(int i = 0; i < vect.size(); i++){
        int sum = 0;
        for(int j = i; j < vect.size(); j++){
            sum += vect[j];
            finalsum = max(sum, finalsum);
        }
    }

    return finalsum;
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

    // for(int i : vec1){
    //     cin>>num;
    //     vec1.push_back(num);
    // }

    // cout<<"The given array is ";
    // for(int i : vec1){
    //     cout<<i<<" ";
    // }

    sum = check_Maximum_Subarray_Sum(vec1);
    cout<<"The maximum sum of the subarray is : " << sum ;
    return 0;
}


// IMPORTANT NOTE: This is a brute force algorithm. More optimized is the Kadane's Algorithm.
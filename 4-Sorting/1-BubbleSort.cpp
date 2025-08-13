// IN bubble sort, we will start from the first position and will compare with the next position. If the current value is larger than the next value, then we will swap the values, otherwise we will just traverse the array. 


#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& nums, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }

    for(int k = 0; k < n; k++){
        cout<<"The value of the sorted array has : "<< nums[k]<< endl;
    }
}

int main(){

    int n, a; 
    cout<<"Enter the total number of the values: "<<endl;
    cin>>n; 
    cout<<"Enter the numbers in the array:" << endl;
    vector <int> v1(n, 0);
    for(int i = 0; i< n; i++){
        cin>>a;
        v1[i] = a;
    }
    bubble_sort(v1, n);
    return 0;
}
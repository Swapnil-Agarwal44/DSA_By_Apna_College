// IN insertion sort, we try to place the number in the correct its correct sorting position, just like inserting a card in its correct sorting order. 
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& nums, int n){
    for(int i = 1; i < n; i++){
        int cur = nums[i];
        int prev = i-1; 
        while(prev >= 0 && nums[prev] > cur){
            nums[prev + 1] = nums[prev];
            prev--;
        }
            nums[prev + 1] = cur;
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
    insertion_sort(v1, n);
    return 0;
}
// In selection sort, we first find the minimum value of the array, and place it on the first position of the array. Now starting from the next position, as the position in which we have inserted the minimum value is already sorted, we will again find the minimum value of the remain unsorted array, and then place it in the beginning of the unsorted one. 


#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& nums, int n){
    int min, index;
    // cout<<"initial nums"<<min;
    for(int i = 0; i < n; i++){
        min = nums[i]; 
        index = i;
        for(int j = i; j < n; j++){
            if(nums[j] <= min){
                index = j;
                min = nums[j];
            }
        }
        swap(nums[i], nums[index]);
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
    selection_sort(v1, n);
    return 0;
}
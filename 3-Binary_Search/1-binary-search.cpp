// basic implementation
// optimization
// with recursion

#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>arr, int target){
    int first = 0; 
    int last = arr.size() - 1;
    
    while(first<=last){
        // int mid = (first + last) / 2;
        int mid = first + ((last - first) / 2); // this is an optimization that is being done, because sometimes in test cases, they can give very large values for integer, which can overflow if we will just use the above statement. This statement is mathematically same as the above one, just that we have ensured that the values won't overflow anyhow. 
        if(target < arr[mid]){
            last = mid -1; 
        }
        else if(target > arr[mid]){
            first = mid + 1; 
        }
        else{
            return mid;
        }
    }
    return -1; 
}

int binary_search_recursion(vector<int> arr, int target, int start, int last){
    if(start <= last){
        int mid = start + ((last - start)/ 2);
        if(target < arr[mid]){
            return binary_search_recursion(arr, target, start, mid-1);
        }
        else if(target > arr[mid]){
            return binary_search_recursion(arr, target, mid+1, last);
        }
        else{
            return mid;
        }
    }
    return -1; 
}

// recursive approach takes more space as compared to the direct appraoch because various calls stacks are created.

int main(){
vector <int> vec1 = {2, 4, 5, 6, 7, 19, 39};
vector <int> vec2 = {6, 7, 8, 12, 32, 54, 60, 73};
int index; 
index = binary_search(vec1, 4);
cout<<"The index of the first target is : "<< index<<endl;; 
index = binary_search(vec2, 73);
cout<<"The index of the second target is : "<< index; 
return 0; 
}
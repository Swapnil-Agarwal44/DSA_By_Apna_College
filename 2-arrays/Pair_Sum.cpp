// In this question we have to find the pair of the array, whose sum is equal to a target value. There should be only one such pair that matches the condition. 

#include<bits/stdc++.h>
using namespace std;

vector <int> pairSum(vector<int> vec, int target){
    // this one is a brute force approach, whose time complexity is O(n^2), and is not optimized. 
    vector<int> vec2;
    int size = vec.size();
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(vec[i] + vec[j] == target){
                vec2.push_back(vec[i]);
                vec2.push_back(vec[j]);
            }
        }
    }
    return vec2;
}

vector<int> pairSum_By_Two_pointer(vector<int> vec, int target){
    vector <int> vec2;
    int size = vec.size();
    int i = 0; 
    int j = size - 1;
    while(i<j){
        if(vec[i] + vec[j] < target){
            i++;
        }else if (vec[i] + vec[j] > target){
            j--;
        }else if (vec[i] + vec[j] == target){
            vec2.push_back(vec[i]);
            vec2.push_back(vec[j]);
            break;
        }
    }
    return vec2;
}

int main(){
    vector<int> vec = {2, 11, 15, 7};
    int target = 9; 
    // vector<int> vec3 = pairSum(vec, target);
    vector<int> vec4 = pairSum_By_Two_pointer(vec, target);
    cout<<"The values of the pair, whose sum is equal to the target are : "<<endl;
    for(int i : vec4){
        cout<<i<<" ";
    }
}
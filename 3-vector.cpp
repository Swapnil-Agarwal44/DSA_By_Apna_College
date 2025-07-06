// vectors are like arrays, but they are dynamically created in the memory, so that we can perform various operations on them. They are provided through the STL.

// Their declarations are: 
// vector<int> vec;
// vector<int> vec = {1, 2, 3, 4};
// vector<int> vec(3,0) { in this vector creation form, the first parameter in the bracker tells about the size of the vector that has to be created, and the next parameter tells about the values with which the all the vector indexes has to be initialized. So in this case, a vector of size 3 will be created with the values of 0.}

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3};
    cout<<vec[0]<<endl;
    for(int val : vec){ 

        //This is a vector for each loop. This loop is used to deal with the vectors. In this, we are using the iterator named as val, which will store the value of the vector at that index, unlike the other loops, which are used to store the index of the arrays. We provide the iterator, whose data type is same as that of the vector, and we will provide the vector variable.

        cout<<"The value at the index of the vector is : "<< val << endl;
    }

    //vector functions are the functions that are provided directly from the vector library, to manipulate and perform certain operations on the vectors.

    cout<<"Size: "<<vec.size()<<endl;  //size() function

    //push_back function: This function is used to push a value to the vector at the last index(closer to 0). So the values are arranged in vector in the order in which they are pushed back.

    vector<int> vec2;
    vec2.push_back(20);
    vec2.push_back(30);
    vec2.push_back(40);
    vec2.push_back(50);
    for(int i : vec2){
        cout<<"The value of the vec2 after pushback is: " << i<<endl;
    }

    //pop_back function: This function is used to remove the last index value of the vector.

    vec2.pop_back();  // will pop 50
    for(int i : vec2){
        cout<<"The value of the vec2 after popback is: " << i<<endl;
    }

    // front function is used to print the first value of the vector. Similarly back function is used to print the last value of teh vector.

    cout<<"The front value of the vec2 is:" << vec2.front()<<endl;
    cout<<"The back value of the vec2 is: " << vec2.back()<<endl;

    // at() function: this function is an alternate method to access the values of the vector, just like the vec[i] method.

    for(int j=0; j<vec2.size(); j++){
        cout<<"The value of the vector at index "<< j << " is :" << vec2.at(j)<<endl;
    }

    // in vector, whenever we are trying to push elements in it after it is completely filled, it will first double its size, and then it will include the element automatically. Because of this, comes two concepts of size and capacity. Size refers to the number of elements that are currently present in the vector, whereas, capacity refers to the total number of elements that the vector can hold, under worst case.

    vector<int> vec3;
    vec3.push_back(0);
    vec3.push_back(1);
    vec3.push_back(2);

    cout<<"The size of the vec3 is : " << vec3.size()<<endl;
    cout<<"The capacity of the vec3 is : " << vec3.capacity()<<endl;
    return 0;
}
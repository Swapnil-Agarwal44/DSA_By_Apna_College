// 11. Container With Most Water
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.



// In this approach we can use the double pointer to find the max value of the water between the bars, and increase or decrease the pointers to traverse through the full array. 

// Because we are using the concept of the double pointers, the time complexity of this code is O(n). If we would have used the brute force method to calculate the capacity of every container, then the time complexity of that code would have been O(n^2), so this also proves that the double pointer algorithm is used many times to reduce the O(n^2) time complexity to O(n) time complexity. 



// this one was written by myself
class Solution {
public:
    int maxArea(vector<int>& height) {
      int i = 0; 
      int j = height.size() -1; 
      int water = 0; 
      int maxWater = 0; 

      while(i < j){
        water = min(height[i], height[j]) * (j-i);
        maxWater = max(water, maxWater); 
        if(height[i] < height[j]) i++; 
        else j--; 
      }  

      return maxWater; 
    }
};
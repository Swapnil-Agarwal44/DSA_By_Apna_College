// 567. Permutation in String
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.


// Appraoch:

// In this question, we have to check whether the string s1's permutation exists in the string s2 or not. For that, we can find the count or the frequency of the s1's characters, and store it using the frequency array having 26 elements, i.e.: freq[26]. The idea behind it is that each index corresponds to the letter in the alphabet, like the 0th index corresponds to letter 'a', and if there is a letter 'a' in string s1, then we will increase the value in the corresponding index of the freq array. 

// IMP NOTE: As it is given in the question, that all the letters in the given strings are in small case, that's why we can declare an array of 26 elements. This can be done, only if there are single variety of characters, like only small case letters, or large case letters or numbers. However, if the question says that the strings may contain any combination of characters, like it can contain both smaller case and larger case letters, as well as numbers, then we would have to use the map for this function. 

// After storing the count of the characters in the string s1, we will use the concept of sliding window, that will traverse through string s2, and will have size of that of the string s1. As the window traverses the string s2, we will count the characters in that window, and then we will check if the array formed, using the same concept as discussed earlier, is equal to that of the frequency array of the string s1. If it is, then we will return true, if it's not, then the loop will continue. After the loop is finished, and if it doesn't return true, then it means there is no permutation of the string s1 in string s2, and then we will return false. 




class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        int l = s1.length();
        int n = s2.length();

        //count the frequency of the characters in the array s1
        for(int i=0; i<l; i++){
            freq[s1[i]-'a']++;
        }
        
        // starting the sliding window concept
        for(int j=0; j<=n-l;j++){
            int window[26] = {0};
            // counting the characters frequency in the window
            for(int k=j; k<j+l; k++){
                window[s2[k]-'a']++;
            }
            // comparing the two arrays. 
            if(equal(begin(freq), end(freq), begin(window), end(window))){
                return true;
            }
        }
        return false;
    }
};
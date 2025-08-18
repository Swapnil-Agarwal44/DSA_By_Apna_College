// 151. Reverse Words in a String
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.



// Approach:

// First we will reverse the entire string. By doing that, we will correctly position the new words, now we have to reverse the words individually.
// We will start the loop from the beginning of the string, and will check for the words, by checking the empty spaces. we will push the characters in a new string, until an empty space comes, then we will reverse that word string, and add this string to a new answer string. 




class Solution {
public:
    string reverseWords(string s) {
         string s2 = ""; 
        reverse(s.begin(), s.end());
        // reversing all the words of the string individually. 
        for(int i=0; i<s.length(); i++){
            string word = ""; 
            while(i < s.length() && s[i] != ' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(), word.end());
             if (word.length() > 0) {
                s2 += " " + word;
            }

        }
        return s2.substr(1);
    }
};
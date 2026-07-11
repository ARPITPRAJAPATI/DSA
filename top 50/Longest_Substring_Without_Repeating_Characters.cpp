Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.


solution:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int left =0; // left pointer 
        int maxy =0; // for max
        for(int right =0;right<s.size();right++){ // right pointer 
            char ch = s[right]; // store right into a var
            if(mp.count(ch) && mp[ch] >=left){  // if dublicate is in map btw left and right
                left = mp[ch] + 1; // move left + 1 to index of dubpi
            }
            mp[ch]=right; //put the change index of dubpli or add new right into 
            int length = right - left + 1; // cal len
            maxy = max(length,maxy);
        } 
        return maxy; // return 
    }
};  


tips .. its a sliding window question
        1. Make a map which store occuring element 
        2. add a pointer left to get the start point
        3. make a for loop for right pointer 
        4. take element of right and put into map
        5. move and calculate length 
        6 compare with max and return the maxy
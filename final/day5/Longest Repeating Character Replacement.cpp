Longest Repeating Character Replacement
lc 424 

class Solution {
public:
    int characterReplacement(string s, int k) {
       int j = 0;
       unordered_map<char,int>mp; // for sliding window , too store max freq
       int maxF = 0; // max freq
       int maxW = 0; // for max window size
       for(int i=0;i<s.size();i++) {
         mp[s[i]]++; // take the element into the map
         maxF = max(mp[s[i]],maxF); // extract the max freq
         while((i-j+1)-maxF>k){ // if window size - maxf > k in while loop
            mp[s[j]]--; // reduce freq of current j element
            j++; // reduce the size of window 
         }
         maxW=max(maxW,i-j+1); // get the new size 
       }
         return maxW;
    }
};
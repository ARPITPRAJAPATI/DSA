lc 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp; // take a map
        int length = 0; 
        int l = 0; // for sliding window
        for(int i=0;i<s.size();i++){
            char c = s[i]; // take first element
            if(mp.count(c)&&mp[c]>=l){
                l = mp[c]+1; // if that come again so move the window to l+ where it come
            }
            length =max(i-l+1,length); // new window size
            mp[c]=i;
        }
        return length; // return max
    }
};
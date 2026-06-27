class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < 256; i++) {
            mp[(char)i] = -1;
        }
        
        int mex=0,l=0,r=0;
        while(r<s.size()){
            if(mp[s[r]]!=-1){
                l = max(l, mp[s[r]] + 1);
            }
            mp[s[r]]=r;
            mex = max(mex, r - l + 1);
            r++;
        }
        return mex;
    }
};

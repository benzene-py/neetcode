class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);

        int maxcount=0;
        int l=0,r=0;
        int ans=0;
        while(r<s.size()){
            freq[s[r]-'A']++;

            maxcount=max(maxcount,freq[s[r]-'A']);

            while((r-l+1)-maxcount>k){
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

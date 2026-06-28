class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v(26,0);
        for(auto x:s1){
            v[x-'a']++;
        }
        int l=0,r=s1.size();
        while(r<=s2.size()){
            vector<int>u(26,0);
            for(int i=l;i<r;i++) u[s2[i]-'a']++;
            if(v==u) return true;
            l++;
            r++;
        }
        return false;
    }
};

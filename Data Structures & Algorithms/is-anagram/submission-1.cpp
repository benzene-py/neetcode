class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int>m;
        map<char,int>n;
        for(auto x:s) m[x]++;
        for(auto x:t) n[x]++;
        for(auto x:m){
            if(x.second!=n[x.first]) return false;
        }
        return true;
    }
};

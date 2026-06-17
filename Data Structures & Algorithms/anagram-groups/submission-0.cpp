class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>m;
        for(auto s:strs){
            vector<int>v(26,0);
            for(char ch:s){
                v[ch-'a']++;
            }
            m[v].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};

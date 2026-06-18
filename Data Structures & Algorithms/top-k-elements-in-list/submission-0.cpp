class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        vector<vector<int>>v;
        for(auto x:m){
            v.push_back({x.second,x.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};

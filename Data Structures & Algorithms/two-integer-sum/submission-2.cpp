class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        for(int i=0;i<nums.size();i++){
            vector<int>a={nums[i],i};
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int l=0,r=nums.size()-1;
        vector<int>ans;
        while(l<r){
            if(v[l][0]+v[r][0]==target){
                ans.push_back(v[l][1]);
                ans.push_back(v[r][1]);
                sort(ans.begin(),ans.end());
                return ans;
            }
            else if(v[l][0]+v[r][0]<target) l++;
            else r--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

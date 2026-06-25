class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>num(nums.begin(),nums.end());
        int l=0;
        for(int x:num){
            if(num.find(x-1)==num.end()){
                int len=1;
                while(num.find(x+len)!=num.end()) len++;
                l=max(l,len);
            }
        }
        return l;
    }
};

class Solution {
   public:
    vector<int> getleft(vector<int>& height, int& n) {
        vector<int> lm(n);
        lm[0] = height[0];
        for (int i = 1; i < n; i++) {
            lm[i] = max(height[i], lm[i - 1]);
        }
        return lm;
    }

    vector<int> getright(vector<int>& height, int& n) {
        vector<int> rm(n);
        rm[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rm[i] = max(height[i], rm[i + 1]);
        }
        return rm;
    }

    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> lm = getleft(height, n);
        vector<int> rm = getright(height, n);

        for (int i = 0; i < height.size(); i++) {
            ans += (min(lm[i], rm[i]) - height[i]);
        }

        return ans;
    }
};

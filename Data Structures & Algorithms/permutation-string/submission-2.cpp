class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> v(26, 0);
        for (auto x : s1) {
            v[x - 'a']++;
        }
        int l = 0, r = s1.size();
        vector<int> u(26, 0);
        for (int i = l; i < r; i++)
            u[s2[i] - 'a']++;
        while (r < s2.size()) {
            if (v == u)
                return true;
            u[s2[l] - 'a']--;
            u[s2[r] - 'a']++;
            l++;
            r++;
        }
        return v==u;
    }
};

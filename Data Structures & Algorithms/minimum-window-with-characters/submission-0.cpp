class Solution {
public:
    bool isValid(map<char, long long>& fl, map<char, long long>& tm) {
        for (auto const& [ch, count] : tm) {
            if (fl[ch] < count) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char, long long> tm;
        for (char x : t)
            tm[x]++;

        if (t.size() > s.size())
            return "";

        int l = 0, r = 0;
        map<char, long long> fl;

        string ans = "";

        while (r < s.size()) {

            if(tm.count(s[r])) fl[s[r]]++;

            while (isValid(fl,tm)) {
                string cur(s.begin() + l, s.begin() + r + 1);

                if (ans.empty() || cur.size() < ans.size())
                    ans = cur;

                if (tm.count(s[l])) {
                    fl[s[l]]--;
                    if (fl[s[l]] == 0)
                        fl.erase(s[l]);
                }
                l++;
            }

            r++;
        }

        return ans;
    }
};

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

        int min_len = INT_MAX;
        int best_l = -1;

        while (r < s.size()) {

            if(tm.count(s[r])) fl[s[r]]++;

            while (isValid(fl,tm)) {
                int current_window_len = r - l + 1;
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    best_l = l;
                }

                if (tm.count(s[l])) {
                    fl[s[l]]--;
                    if (fl[s[l]] == 0)
                        fl.erase(s[l]);
                }
                l++;
            }

            r++;
        }

        return (best_l == -1) ? "" : s.substr(best_l, min_len);
    }
};

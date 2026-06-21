class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size();i++){
            s = s+to_string(strs[i].size())+"#"+strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        string c="";
        vector<string>v;
        int i=0;
        while(i<s.size()){
            int j=s.find('#', i);
            int len=stoi(s.substr(i, j - i));
            v.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return  v;
    }
};

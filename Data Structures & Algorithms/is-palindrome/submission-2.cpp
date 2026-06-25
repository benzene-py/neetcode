class Solution {
public:
    bool isPalindrome(string s) {
        string abc="";
        for(char x:s){
            if(isalnum(x)) abc+=tolower(x);
        }
        string cba=abc;
        reverse(cba.begin(),cba.end());
        if(abc==cba) return true;
        else return false;
    }
};

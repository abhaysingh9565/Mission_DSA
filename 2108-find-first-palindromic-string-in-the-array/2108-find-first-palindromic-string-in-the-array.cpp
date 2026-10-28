class Solution {
private:
    bool isPalindrome(string & s)
    {
        int b = 0 , e = s.size()-1;
        while(b<e)
        {
            if(s[b++]!=s[e--])return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string &s: words)
        {
            if(isPalindrome(s))return s;
        }
        return "";
    }
};
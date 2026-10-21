class Solution {
    private:
    string invert(string& s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string generate(int n)
    {
        if(n==1)return "0";
        string prev = generate(n-1);
        string curr = prev+"1"+invert(prev);
        return curr;
    }
public:
    char findKthBit(int n, int k) {
        string nth = generate(n);
        cout<<nth;
        return nth[k-1];

        
    }
};
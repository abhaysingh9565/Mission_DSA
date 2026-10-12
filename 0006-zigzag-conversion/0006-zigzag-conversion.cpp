class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows>=s.size())return s;
        int row = 0;
        int dir =1;
        vector<string>str(numRows);
        for(char c : s)
        {
            str[row]+=c;

            if(row == 0)dir = 1;
            else if(row == numRows-1)dir = -1;

            row+= dir;
        }
        string ans;
        for(string st : str)ans+=st;
        
        return ans;
    }
};
class Solution {
public:
    bool judgeCircle(string moves) {
        int first = 0;
        int second = 0;
        for(char c : moves)
        {
            if(c=='R')
            {
                second++;
            }
            else if(c=='L'){
                second--;
            }
            else if(c=='U')first--;

            else if(c=='D')first++;
        }
        return first == 0 && second ==0;
    }
};
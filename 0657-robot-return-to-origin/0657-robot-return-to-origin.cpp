class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int>start = {0,0};
        for(char c : moves)
        {
            if(c=='R')
            {
                start.second++;
            }
            else if(c=='L'){
                start.second--;
            }
            else if(c=='U')start.first--;

            else if(c=='D')start.first++;
        }
        return start.first == 0 && start.second ==0;
    }
};
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i ++)
        {
            q.push({tickets[i],i});
        }
        int val = tickets[k];
        int time = 0 ;
        while(true)
        {
            auto [tic , i] = q.front();
            q.pop();
            tic--;
            time++;
            if(i==k && tic==0){
                return time;
            }
            if(tic!=0)
            q.push({tic,i});
        }
        return time;
        
    }
};
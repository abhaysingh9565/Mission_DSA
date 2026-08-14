class Solution {
public:
    bool canMake(vector<int>& bloomDay,int m, int k, int mid)
    {
        int adjacent = 0;
        int bq = 0;
        for(int num : bloomDay)
        {
            if(num<=mid)
            {
                adjacent++;
                if(adjacent == k )
                {
                    adjacent = 0 ;
                    bq++;
                }
            }
            else adjacent = 0;
        }
        return bq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int s = 1 ;
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            if(canMake(bloomDay, m,k , mid))
            {
                ans  = mid;
                e = mid-1;
            }
            else s= mid+1;
        }
        return ans;
        
    }
};
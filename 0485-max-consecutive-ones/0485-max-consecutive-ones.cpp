class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 , count = 0;
        for(int x : nums)
        {
            if(x==0)
            {
                ans = max(ans,count);
                count=0;
            }
            else{
                count++;
            }
        }
        ans = max(ans,count);
        count=0;
        return ans;
    }
};
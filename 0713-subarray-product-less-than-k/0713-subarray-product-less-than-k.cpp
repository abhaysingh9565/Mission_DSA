class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
        {
            return 0;
        }
        int i = 0 , j = 0 , prod = 1 , ans = 0;
        while(j<nums.size())
        {
            prod*=nums[j];
            while(prod>=k)
            {
                prod/=nums[i];
                i++;
            }
            ans = ans + j-i+1;
            j++;
        }
        return ans;
    }
};
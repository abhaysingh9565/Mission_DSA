class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        while(i<n){
            int eindex= nums[i]-1;
            if(eindex<0 || eindex>=n || nums[eindex]==nums[i])
            {
                i++;
            }
            else swap(nums[i],nums[eindex]);
        }
        for(int i =0;i<n;i++)
        {
            if(nums[i]-1!=i)return i+1;
        }
        return i;
        
    }
};
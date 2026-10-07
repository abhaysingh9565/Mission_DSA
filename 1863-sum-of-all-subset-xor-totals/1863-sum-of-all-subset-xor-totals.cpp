class Solution {
    int ans = 0;
    void sum(vector<int>& nums , int index,int curr)
    {
        if(index>=nums.size()){
            ans+=curr;
            return;
        }
        sum(nums,index+1,curr^nums[index]);
        sum(nums,index+1,curr);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        sum(nums,0,0);
        return ans;
    }
};
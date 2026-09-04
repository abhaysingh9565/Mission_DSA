class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0 ;
        int count = 1;
        for(int i = 1 ; i< nums.size() ; i++)
        {
            int x = nums[i];
            if(x==nums[k] && count<2)
            {
                nums[++k]=x;
                count++;
            }
            else if(x!= nums[k])
            {
                nums[++k]=x;
                count=1;
            }

        }
        return k+1;
        
    }
};
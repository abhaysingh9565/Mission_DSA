class Solution {
  public:
      void sortColors(vector<int>& nums) {
          int n = nums.size();
          int f = 0 , m = 0 , e = n-1;
          while(m<=e)
          {
              if(nums[m]==0){
                  swap(nums[m],nums[f]);
                  f++;
                  m++;
              }
              else if(nums[m]==1)
              {
                  m++;
              }
              else{
                  swap(nums[m],nums[e]);
                  e--;
              }
          }
          
      }
  };
class Solution {
  public:
      int numSubarrayProductLessThanK(vector<int>& nums, int k) {
  
          int prod = 1;
          int ans = 0 ;
          int i =0;
          for(int j = 0 ; j< nums.size() ; j++)
          {
              prod *= nums[j];
              while(prod >= k  && i < nums.size())
              {
                  prod /= nums[i];
                  i++;
              }
              ans = ans + j-i+1;
          }
          return ans;
          
      }
  };
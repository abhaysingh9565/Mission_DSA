class Solution {
  public:
      int maxProduct(vector<int>& nums) {
          int ans = nums[0];
          int mini = nums[0],maxi = nums[0];
          int n = nums.size();
          for(int i = 1 ; i < n ; i++)
          {
              if(nums[i]<0)
              {
                  swap(mini,maxi);
              }
              maxi = max(nums[i],maxi*nums[i]);
              mini = min(nums[i],mini*nums[i]);
  
              ans = max(ans,maxi);
              
          }
          
          return ans;
          // int currentSum = nums[0] , maxSum = nums[0];
          // for(int i = 1 ; i<nums.size() ; i++)
          // {
          //     currentSum = currentSum*nums[i];
          //     maxSum = max(maxSum,currentSum);
          // }
          // return maxSum;
          
      }
  };
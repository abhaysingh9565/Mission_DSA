class Solution {
  public:
      long long maximumSubarraySum(vector<int>& nums, int k) {
          long long sum = 0 ,ans = 0 ;
          set<int>st;
          for(int i = 0,j = 0 ; j<nums.size() ; j++)
          {
              if(st.find(nums[j]) != st.end()){
                  while(nums[i]!=nums[j]){
                      sum-=nums[i];
                      st.erase(nums[i]);
                      i++;
                  }
                  sum-=nums[i];
                  st.erase(nums[i]);
                  i++;
              }
              sum += nums[j];
              st.insert(nums[j]);
              if(j - i + 1 == k)
              {
                  ans = max(sum,ans);
                  sum-=nums[i];
                  st.erase(nums[i]);
                  i++;
              }
              
  
          }
          return ans;
          
      }
  };
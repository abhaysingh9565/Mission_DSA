
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      vector<int> productExceptSelf(vector<int>& nums) {
          int n = nums.size();
          vector<int>ans(n,0);
          int total = 1;
          int flag = 0 ;
          int index;
          for(int i = 0; i< n ; i++)
          {
              if(nums[i]==0)
              {
                  flag++;
                  index = i;
                  if(flag>1)return ans;
              }
              else total *= nums[i];
          }
          if(flag == 1)
          {
              ans[index]=total;
          }
          else {
              for(int i = 0 ; i< n ; i++)
              {
                  ans[i] = total/nums[i];
              }
          }
          return ans;
          
      }
  };
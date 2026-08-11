#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      int maxAbsoluteSum(vector<int>& nums) {
          int maxSum = INT_MIN;
          int minSum = INT_MAX;
          int n = nums.size();
          int sum1 =0,sum2=0;
          for(int i = 0; i< n ; i++)
          {
              sum1 += nums[i];
              sum2 += nums[i];
              maxSum= max(sum1,maxSum);
              if(sum1<0)
                  sum1=0;
              minSum= min(sum2,minSum);
              if(sum2>0)
                  sum2 =0;
              
          }
          // sum =0;
          // for(int i = 0; i< n ; i++)
          // {
          //     sum += nums[i];
          //     minSum= min(sum,minSum);
          //     if(sum>0)
          //         sum =0;
              
          // }
          return abs(minSum)>abs(maxSum)?abs(minSum):abs(maxSum);
          
      }
  };
  
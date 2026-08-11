#include <iostream>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> ans;
          int n = nums.size();
  
          if (n < 3)
              return ans;
  
          sort(nums.begin(), nums.end());
  
          for (int i = 0; i < n - 2; i++) {
  
              
              if (i > 0 && nums[i] == nums[i - 1])
                  continue;
  
              
              if (nums[i] > 0)
                  break;
  
              int target = -nums[i];
              int left = i + 1;
              int right = n - 1;
  
              while (left < right) {
  
                  int sum = nums[left] + nums[right];
  
                  if (sum == target) {
  
                      ans.push_back({nums[i], nums[left], nums[right]});
  
                      left++;
                      right--;
  
                      
                      while (left < right && nums[left] == nums[left - 1])
                          left++;
  
                     
                      while (left < right && nums[right] == nums[right + 1])
                          right--;
  
                  }
                  else if (sum < target) {
                      left++;
                  }
                  else {
                      right--;
                  }
              }
          }
  
          return ans;
          
      }
  };

  //map approach
  class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            map<vector<int>,int>mp;
            vector<vector<int>>ans;
            for(int i = 0 ; i< nums.size();i++)
            {
                int b = i+1,e = nums.size()-1;
                while(b<e)
                {
                    int sum = nums[b]+nums[e];
                    if(sum==abs(nums[i]))
                    {
                        if(mp.count({nums[i],nums[b],nums[e]})==0)
                        ans.push_back({nums[i],nums[b],nums[e]});
                        mp[{nums[i],nums[b],nums[e]}]++;
                        b++;
                        e--;
                    }
                    else if(sum < abs(nums[i]))
                    b++;
                    else e--;
                }
            }
            return ans;
            
        }
    };

    //set approach

    class Solution {
      public:
          vector<vector<int>> threeSum(vector<int>& nums) {
              sort(nums.begin(),nums.end());
              set<vector<int>>st;
              vector<vector<int>>ans;
              for(int i = 0 ; i< nums.size();i++)
              {
                  int b = i+1,e = nums.size()-1;
                  while(b<e)
                  {
                      int sum = nums[b]+nums[e];
                      if(sum==abs(nums[i]))
                      {
                          st.insert({nums[i],nums[b],nums[e]});
                          b++;
                          e--;
                      }
                      else if(sum < abs(nums[i]))
                      b++;
                      else e--;
                  }
              }
              for(auto x : st)
              ans.push_back(x);
              return ans;
              
          }
      };
// brute force
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          int n = nums.size();
          vector<int>result;
          for(int i = 0; i<=n-k; i++)
          {
              int ans = nums[i];
              for(int j = i ;j < i+k ;j++)
              {
                  ans = max(ans,nums[j]);
              }
              result.push_back(ans);
              
          }
          return result;
          
      }
  };

  // using prority queue

  class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            priority_queue<pair<int,int>> pq;
        vector<int> ans;
    
        for(int i=0;i<nums.size();i++){
    
            pq.push({nums[i],i});
    
            while(!pq.empty() && pq.top().second<=i-k){
                pq.pop();
            }
    
            if(i>=k-1){
                ans.push_back(pq.top().first);
            }
        }
    
        return ans;
            
        }
    };

    // using deque
    class Solution {
      public:
          vector<int> maxSlidingWindow(vector<int>& nums, int k) {
              deque<int> dq;
              vector<int> ans;
      
              for(int i=0;i<nums.size();i++){
      
      
                  while(!dq.empty() && dq.front()<=i-k)
                      dq.pop_front();
      
      
                  while(!dq.empty() && nums[dq.back()]<nums[i])
                      dq.pop_back();
      
                  dq.push_back(i);
      
                  if(i>=k-1)
                      ans.push_back(nums[dq.front()]);
              }
      
              return ans;
              
          }
      };
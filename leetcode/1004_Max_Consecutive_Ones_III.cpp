#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int ans = 0 ; 
          for(int j = 0 ,i = 0 ; i<nums.size() ; i++)
          {
              if(nums[i]==0)
              {
                  if(!k)
                  {
                      while(nums[j]!=0)j++;
  
                      j++;
                  }
                  else 
                  k--;
              }
              ans = max(ans,i-j+1);
          }
          return ans;
          
      }
  };


//o(n^2) solution

class Solution1 {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int ans = 0 ; 
          for(int j = 0 ,i = 0 ; i<nums.size() ; i++)
          {
              if(nums[i]==0)
              {
                  if(!k)
                  {
                      while(nums[j]!=0)j++;
  
                      j++;
                  }
                  else 
                  k--;
              }
              ans = max(ans,i-j+1);
          }
          return ans;
          
      }
  };
  
  class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int ans = 0 ; 
          for(int i = 0 ; i<nums.size() ; i++)
          {
              int flip = k;
              int j = i;
              while(j<nums.size())
              {
                  if(nums[j]==0){
                      if(!flip){
                          break;
                      }
                      else flip--;
                  }
  
                  j++;
              }
              if(j==nums.size())
              return max(ans,j-i);
  
              ans = max(ans,j-i);
          }
          return ans;
          
      }
  };
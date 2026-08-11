#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      int lengthOfLongestSubstring(string s) {
          vector<int>freq(256,0);
          int i = 0 ,ans =0;
          for(int j = 0 ; j<s.size();j++)
          {
              freq[s[j]]++;
              if(freq[s[j]]>1)
              {
                  while(s[i]!=s[j]){
                      freq[s[i]]--;
                      i++;
                  }
                  if(i<s.size()){
                      freq[s[i]]--;
                      i++;
                  }
              }
              ans = max(ans,j-i+1);
          }
          return ans;
  
          
      }
  };
class Solution {
  public:
      int totalFruit(vector<int>& fruits) {
          unordered_map<int,int> mp;
          int ans = 0 ;
          int j = 0;
          for(int i = 0 ; i< fruits.size() ; i++)
          {
              if(mp.size() < 2 || mp.count(fruits[i])!=0)
              {
                  mp[fruits[i]]=i;
              }
              else {
                  int index = INT_MAX;
                  int del;
                  for(auto x : mp)
                  {
                      if(x.second < index)
                      {
                          index = x.second;
                          del = x.first;
                      }
                  }
                  j = index+1;
                  mp.erase(del);
                  mp[fruits[i]]=i;
              }
  
              ans = max(ans , i - j +1);
  
          }
          return ans;
          
      }
  };
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      vector<int> asteroidCollision(vector<int>& asteroids) {
          vector<int>ans;
          int i = 0;
          while(i < asteroids.size())
          {
              if(asteroids[i]>0)
              {
                  ans.push_back(asteroids[i]);
                  i++;
              }
              else if(ans.size()==0){
                  // if(i==asteroids.size()-1)
                  // return {};
                  // else 
                  ans.push_back(asteroids[i]);
                  i++;
              }
  
              else {
                  int item = ans.back();
                  if(item < 0 ){
                      ans.push_back(asteroids[i]);
                      i++;
                  }
                  else if(item < abs(asteroids[i]))
                      ans.pop_back();
                  else if(item == abs(asteroids[i])){
                      ans.pop_back();
                      i++;
                  }
                  else {
                      i++;
                  }
  
              }
          }
          return ans;
          
      }
  };
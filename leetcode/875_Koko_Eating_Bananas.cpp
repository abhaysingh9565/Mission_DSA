#include <iostream>
#include <stack>
#include <algorithm>
#include<vector>
using namespace std;
class Solution {
  public:
      bool canEat(vector<int>& piles , int mid , int h)
      {
          int hours = 0 ;
          for(int num : piles)
          {
              hours += num/mid;
              if(num%mid != 0){
                  hours ++;
              }
          }
          return hours<=h;
      }
      int minEatingSpeed(vector<int>& piles, int h) {
          int s = 1 ;
          int e = *max_element(piles.begin(),piles.end());
          while(s<e)
          {
              int mid = s + ( e-s)/2;
              if(canEat(piles,mid,h))
              {
                  e = mid;
              }
              else {
                  s = mid+1;
              }
          }
          return s;
  
          
      }
  };
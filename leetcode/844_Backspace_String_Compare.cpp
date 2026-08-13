#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      void format(string &s)
      {
          for(int i = 0 ; i < s.size() ; i++)
          {
              if(s[i]=='#')
              {
                  int j = i-1 ;
                  while(j>=0 && s[j]=='#')j--;
  
                  if(j>=0)s[j]='#';
  
              }
          }
      }
      bool backspaceCompare(string s, string t) {
          format(s);
          format(t);
          int i = 0 , j = 0;
          while(i<s.size() && j < t.size())
          {
              if(s[i]=='#')i++;
              else if(t[j]=='#')j++;
              else if(s[i]!=t[j])return false;
  
              else{
                  i++;
                  j++;
              }
          }
          while(i< s.size())
          {
              if(s[i++]!='#')return false;
          }
          while(j< t.size())
          {
              if(t[j++]!='#')return false;
          }
          return true;
          
      }
  };


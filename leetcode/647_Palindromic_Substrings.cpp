#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  private:
  int  isPalindrome(string &s , int b, int e )
  {
      int count = 0 ;
      while(b >= 0  && e < s.size() && s[b]==s[e])
      {
          count++;
          b--;
          e++;
      }
      return count;
  }
public:
  int countSubstrings(string s) {
      int n=s.size();
      int ans = 0;
      for(int i=0;i<n;i++)
      {
          ans += isPalindrome(s,i,i);
          ans += isPalindrome(s,i,i+1);
      }
      return ans;
      
  }
};

class Solution {
  private:
  bool is_palindome(string &s,int b,int e)
  {
      while(b<=e)
      {
          if(s[b]!=s[e])
          return false;

          b++;
          e--;
      }
      return true;

  }
public:
  int countSubstrings(string s) {
      int n=s.size();
      int ans = 0;
      for(int i=0;i<n;i++)
      {
          for(int j=i+1;j<n;j++)
          {
              if(is_palindome(s,i,j)){
                  ans++;
              }
          }
      }
      return ans+n;
      
  }
};
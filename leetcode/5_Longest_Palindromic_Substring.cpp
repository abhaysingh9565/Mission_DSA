#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      int  isPalindrome(string &s , int b, int e )
      {
          while(b >= 0  && e < s.size() && s[b]==s[e])
          {
              b--;
              e++;
          }
          return e-b-1;
      }
      string longestPalindrome(string s) {
          int n = s.size();
          // if(n<=1)return s;
          int start = 0 , end = 0;
          for(int i = 0 ; i< n ; i++)
          {
              int odd = isPalindrome(s,i,i);
              int even = isPalindrome(s,i,i+1);
              int len = max(odd,even);
  
              if(len>(end-start)){
                  start =  i-(len-1)/2;
                  end = i+len/2;
              }
          }
          return s.substr(start, end - start + 1);
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
    string longestPalindrome(string s) {
        int n=s.size();
        int b=0,e=0,maxl=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(is_palindome(s,i,j)){
                    if(j-i+1>maxl)
                    {
                        maxl=j-i+1;
                        b=i;
                        e=j;
                    }
                }
            }
        }
        string ans;
        for(int i=b;i<=e;i++)
        ans.push_back(s[i]);

        return ans;
        
    }
};
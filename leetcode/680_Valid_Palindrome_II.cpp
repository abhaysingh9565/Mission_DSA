class Solution {
  public:
      bool checkPalindrome(string &s , int b, int e)
      {
          while(b<e)
          {
              if(s[b]!=s[e])return false;
  
              b++;
              e--;
          }
          return true;
      }
      bool validPalindrome(string s) {
          int i = 0 , j = s.size()-1;
          while(i<j)
          {
              if(s[i]!=s[j])
              {
                  return checkPalindrome(s,i,j-1)||checkPalindrome(s,i+1,j);
                  
              }
              i++;
              j--;
          }
          return true;
          
      }
  };
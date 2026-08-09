class Solution {
  public:
      bool isPalindrome(string s) {
          string str ="";
          for(int i = 0 ; i < s.size();i++)
          {
              char ch = s[i];
              if((ch>=65 && ch <= 90)||(ch>=97 && ch<=122)||(ch>=48 && ch<=57))
              {
                  if((ch>=65 && ch <= 90))
                  {
                      str+=char(ch+32);
                  }
                  else str+=ch;
              }
          }
          int i = 0 , j = str.size()-1;
          while(i<=j)
          {
              if(str[i]!=str[j])return false;
  
              i++;
              j--;
          }
          return true;
          
      }
  };
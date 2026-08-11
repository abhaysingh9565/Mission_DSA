#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
          int r = mat.size(),c = mat[0].size();
          vector<vector<int>>prefix(r,vector<int>(c));
          vector<vector<int>>ans(r,vector<int>(c));
          for(int i = 0; i< r; i++)
          {
              for(int j = 0 ; j< c; j++)
              {
                  if(j!=0){
                      mat[i][j]+=mat[i][j-1];
                  }
              }
  
          }
          for(int i = 0 ; i< r ; i++)
          {
              for(int j =0; j< c ; j++)
              {
                  int colMa = min(j+k,c-1);
                  int colMi = max(0,j-k);
                  int rowMi = max(i-k,0);
                  int rowMa = min(i+k,r-1);
                  int sum = 0;
                  int prev = 0;
                  for(int l = rowMi ; l<=rowMa ; l++)
                  {
                      sum+=mat[l][colMa];
                      if(colMi>0)
                      {
                          prev += mat[l][colMi-1];
                      }
                  }
                  ans[i][j]=sum-prev;
              }
          }
          return ans;
  
          
      }
  };
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = n*m;
        int count = 0 ;
        int fcol = 0 , frow = 0 , lcol= n-1, lrow = m-1;
        vector<int>ans;
        while(count < total)
        {
            for(int i = fcol ; i<=lcol && count < total; i++)
            {
                ans.push_back(matrix[frow][i]);
                count ++;
            }
            frow++;
            for(int i = frow ; i<=lrow && count < total; i++)
            {
                ans.push_back(matrix[i][lcol]);
                count ++;
            }
            lcol--;
            for(int i = lcol ;count < total && i>=fcol; i--)
            {
                ans.push_back(matrix[lrow][i]);
                count ++;
            }
            lrow--;
            for(int i = lrow ;count < total && i>=frow; i--)
            {
                ans.push_back(matrix[i][fcol]);
                count ++;
            }
            fcol++;

        }
        return ans;

        
    }
};
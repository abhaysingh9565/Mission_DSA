class Solution {
public:
    void moveZeros(vector<int>&row)
    {
        int z = 0 ;
        for(int i = 0 ;i< row.size(); i++)
        {
            if(row[i]==0)
            {
                swap(row[i],row[z]);
                z++;
            }
        }
    }
    int findFirst(vector<int>&row)
    {
        int s = 0 , e = row.size()-1;
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(row[mid]==1)
            {
                ans = mid;
                e= mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int col = mat[0].size();
        int result = 0;
        int max1 = 0;
        for( int  i = 0 ; i<n ;i++)
        {
            moveZeros(mat[i]);
            int f = findFirst(mat[i]);
            if(f!=-1)
            {
                if(max1 < (col-f)){
                    max1 = col-f;
                    result = i;
                }
            }
        }
        return {result,max1};
        
    }
};
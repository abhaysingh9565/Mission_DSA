class Solution {
private: 
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            int h = i==n ? 0 : heights[i];
            while(!st.empty() && h < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top()-1;
                int area = height * width;
                ans = max(ans, area);
            }
            st.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>arr(m,0);
        int ans = 0;

        for(int i = 0 ;  i< n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j]=='1')
                {
                    arr[j]+=1;
                }else{
                    arr[j]=0;
                }
            }
            ans = max(ans, largestRectangleArea(arr));
        }
        return ans;
        
    }
};
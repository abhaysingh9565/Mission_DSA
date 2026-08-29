class Solution {

private:
void nextSmallerElement(vector<int> arr, int n ,vector<int>&ans)
{
   stack<int> s;
   s.push(-1);

   for(int i=n-1;i>=0;i--)
   {
       int curr=arr[i];
       while(s.top() != -1 && arr[s.top()]>=curr)
       {
           s.pop();
       }
       ans[i]=s.top();
       s.push(i);
   }

}

void prevSmallerElement(vector<int> arr, int n,vector<int>&ans)
{
   stack<int> s;
   s.push(-1);

   for(int i=0;i<n;i++)
   {
       int curr=arr[i];
       while(s.top() != -1 && arr[s.top()]>=curr)
       {
           s.pop();
       }
       ans[i]=s.top();
       s.push(i);
   }
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;

        // vector<int>next(n);
        // nextSmallerElement(heights,n,next);

        // vector<int>prev(n);
        // prevSmallerElement(heights,n,prev);

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
};
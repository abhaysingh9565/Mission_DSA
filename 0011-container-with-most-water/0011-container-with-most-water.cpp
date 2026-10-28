class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int s = 0, e= height.size()-1;
        while(s<e)
        {
            int area = min(height[s],height[e])*(e-s);
            ans = max(ans,area);
            if(height[s]<height[e])s++;
            else e--;
        }
        return ans;
    }
};
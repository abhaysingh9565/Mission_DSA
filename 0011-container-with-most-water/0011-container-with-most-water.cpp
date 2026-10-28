class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        int s = 0, e= height.size()-1;
        while(s<e)
        {
            if(height[s]<=height[e]){
                area = max(height[s]*(e-s),area);
                s++;
            }
            else{
                area = max(height[e]*(e-s),area);
                e--;
            }
        }
        return area;
    }
};
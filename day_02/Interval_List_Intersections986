class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size()==0 || secondList.size()==0)
        {
            return {};
        }
        int i  = 0 , j=0;
        vector<int>curr(2);
        vector<vector<int>> ans;
        while(i < firstList.size() &&  j < secondList.size())
        {
                curr[0]=max(firstList[i][0],secondList[j][0]);
                curr[1]=min(firstList[i][1],secondList[j][1]);
                if(curr[0]<=curr[1])
                ans.push_back(curr);

                if(firstList[i][1]<secondList[j][1])
                i++;

                else j++;
        }
        return ans;
        
    }
};
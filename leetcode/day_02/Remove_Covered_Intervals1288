class Solution1 {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //sort(intervals.begin(),intervals.end());
        int cov= 0;
        for(int i = 0;i<n ;i++)
        {
            for(int j = 0; j<n ;j++)
            {
                if(i==j)continue;
                if((intervals[i][1]<=intervals[j][1])&&(intervals[i][0]>=intervals[j][0]))
                {
                cov++;
                break;
                }
            }
        }
        return n-cov;
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int cov= 0;
        int left = -1,right = -1;
        for(int i = 0;i<n ;i++)
        {
            if(intervals[i][0]>left && intervals[i][1]>right)
            {
                cov++;
                left=intervals[i][0];
            }
            right = max(right , intervals[i][1]);
        }
        return cov;
    }
};
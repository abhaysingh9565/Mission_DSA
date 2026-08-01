#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>result;
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size() ; i++)
    {
        if(intervals[i][0]<=result.back()[1])
        {
            result.back()[1] = max(result.back()[1],intervals[i][1]);
        }
        else result.push_back(intervals[i]);
    }
    return result;
    
}
int main(){
    vector<vector<int>> intervals;
    vector<vector<int>> ans = merge(intervals);
    return 0;
}
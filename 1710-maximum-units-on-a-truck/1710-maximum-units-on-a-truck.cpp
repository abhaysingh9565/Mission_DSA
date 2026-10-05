class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        int count = 0;
        for(int i = 0 ; i< boxTypes.size() ; i++)
        {
            int n = boxTypes[i][0];
            if(truckSize - n<=0){
                n = truckSize;
                count += n*boxTypes[i][1];
                break;
            }
            truckSize = truckSize - boxTypes[i][0];
            count += n*boxTypes[i][1];
        }
        return count;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> v=nums;
        int n=nums.size();
        int start=0;
        int end=n-1;
        long long int tar;
       std::sort(v.begin(), v.end());
        while(start<end){
            tar=v[start]+v[end];
            if(tar==target){
                int i=0;int j=0;
                for(i=0;i<n;i++){
                    if(nums[i]==v[start]){
                        ans.push_back(i);
                        break;
                    }}
                    for(int j=0;j<n;j++){
                    if(nums[j]==v[end]&& i!=j){
                        ans.push_back(j);
                        break;
                    }
                }
                return ans;
            }
            else if(tar>target){
                end--;
            }
            else 
            start++;
        }
        return ans;
    }
};
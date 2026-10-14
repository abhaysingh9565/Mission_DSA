class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num : nums)
        {
            pq.push(num);
            if(pq.size()>k)pq.pop();
        }
        // for(int i = 1 ; i < k ; i++)
        // {
        //     pq.pop();
        // }
        return pq.top();
        
    }
};
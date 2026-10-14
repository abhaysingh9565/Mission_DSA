class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> pq;

    int mx = -1;

    KthLargest(int k, vector<int>& nums) {
        mx = k;
        for(auto x:nums)
            add(x);
    }
    
    int add(int val) {
        int sz = pq.size();
        if(sz<mx) pq.push(val);
        else if((int)pq.top()<val)
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
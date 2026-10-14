class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int nth ;
    KthLargest(int k, vector<int>& nums) {
        nth = k;
        for(auto n : nums)
        {
            add(n);
        }
    }
    
    int add(int val) {
        if(pq.size()<nth)pq.push(val);
        else if((int)pq.top()<val)
        {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
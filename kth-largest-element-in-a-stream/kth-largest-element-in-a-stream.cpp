class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int global_k;
    
    KthLargest(int k, vector<int>& nums) {
        global_k = k;
        for(auto x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
       if(minHeap.size() >= global_k) {
            if(minHeap.top() < val) {
                minHeap.pop();
                minHeap.push(val);
            }
        }
        else 
            minHeap.push(val);
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
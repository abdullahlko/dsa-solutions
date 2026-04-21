class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using pii = pair<int, int>;  // (frequency, element)

        unordered_map<int, int> freqMap;

        // Count frequencies
        for (int num : nums) {
            freqMap[num]++;
        }

        // Min Heap (keeps top k elements)
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;

        for (const auto& entry : freqMap) {
            int num = entry.first;
            int freq = entry.second;

            minHeap.push({freq, num});

            // Keep only k elements in heap
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Extract result
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
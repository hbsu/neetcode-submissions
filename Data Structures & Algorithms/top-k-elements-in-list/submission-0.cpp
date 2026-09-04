class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //have n buckets, where n represents how frequent number occurs in vector
        //then just return k amount of buckets starting from n
        unordered_map<int, int> count;
        for (int n = 0; n < nums.size(); n++) count[nums[n]]++; 
        //bumps count up one by one
        //buckets
        vector<vector<int>> buckets(nums.size() + 1); //vector of vectors for bucket
        for (unordered_map<int, int>::iterator it = count.begin(); it != count.end(); ++it) {
            int num = it->first; //the key 
            int freq = it->second; //the value
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for(int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num = 0; num < buckets[i].size(); num++) {
                result.push_back(buckets[i][num]);
                if(result.size() == k) break;
            }

        }

        return result;
    }
};

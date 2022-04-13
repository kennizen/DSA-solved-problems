Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        pair<int,int> p;
        unordered_map<int,int> umap;
        
        for(int i = 0; i<nums.size(); i++){
            if(umap.find(nums[i]) != umap.end()){
                umap[nums[i]]++;
            }
            else{
                umap.insert({nums[i],1});
            }
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto i : umap){
            p.first = i.second;
            p.second = i.first;
            pq.push(p);
        }
        
        for(int i = 0; i<k; i++){
            p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        
        return ans;
    }
};

bucket sort approach - O(n) time

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};
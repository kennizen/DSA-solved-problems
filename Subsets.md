Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.


class Solution {
private:
    void solve(vector<int>& nums,  vector<int> op, int i, vector<vector<int>>& res)
    {
        if(i >= nums.size())
        {
            res.push_back(op);
            return;
        }
        
        solve(nums, op, i+1, res);
        
        op.push_back(nums[i]);
        solve(nums, op, i+1, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        int i = 0;
        solve(nums, op, i, res);
        return res;
    }
};
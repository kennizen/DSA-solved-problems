Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.


class Solution {
private:
    void solve(vector<vector<int>> &res, vector<int>& nums, int k)
    {
        if(k >= nums.size())
        {
            res.push_back(nums);
            return; 
        }
        
        for(int i = k; i<nums.size(); i++)
        {
            swap(nums[k],nums[i]);
            solve(res,nums,k+1);
            // swaping again to react the original previous state
            swap(nums[k],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        solve(res,nums,0);
        
        return res;
    }
};
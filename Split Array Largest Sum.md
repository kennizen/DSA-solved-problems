Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)


class Solution {
private:
    bool isPossible(int mid, int n, vector<int>& nums, int m){
        int count = 1;
        int sum = 0;
        
       for(int i = 0; i<n; i++) {
           if(sum + nums[i] <= mid) {
               sum += nums[i];
           }
           else {
               count++;
               if(count > m || nums[i] > mid)
                   return false;
               sum = nums[i];
           }
       }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int s,mid,e = 0;
        int n = nums.size();
        int ans = INT_MAX;
        
        s = 0;
        
        for(int i = 0; i<n; i++)
            e += nums[i];
        
        mid = s + (e-s)/2;
        
        while(s <= e)
        {
            if(isPossible(mid, n, nums, m)) {
                /* the only diff here is we take min of ans and mid
                as we have to get the minimum largest sum*/ 
                ans = min(mid,ans);
                
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
              
            mid = s + (e-s)/2;
        }
        
        return ans;
    }
};
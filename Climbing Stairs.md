You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

intuition - use dp

class Solution {
public:
    int count(int n, unordered_map<int,int> &umap){
        if(n <= 1) return 1;
        if(umap[n]) return umap[n];
        return umap[n] = count(n-1,umap) + count(n-2,umap);
    }
    
    int climbStairs(int n) {
        unordered_map<int,int> umap;
        return count(n,umap);
    }
};
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        string compare = strs[0];
        
        for(int i = 1; i<n; i++)
        {
            if(compare[0] != strs[i][0])
                return "";
        }
        
        string smallest = "";
        int small = INT_MAX;
        
        for(int i = 0; i<n; i++)
        {
            if(strs[i].length() < small)
            {
                small = strs[i].length();
                smallest = strs[i];
            }
        }
         
        for(int j = 0; j<small; j++)
        {
            for(int i = 0; i<n; i++)
            {
                int f = strs[i].find(smallest);
                if(f == string::npos)
                    smallest.pop_back();
                else if(f != 0)
                    smallest.pop_back();
            }
        }
        
        return smallest;
    }
};
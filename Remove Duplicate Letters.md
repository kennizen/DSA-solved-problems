Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Accepted
173,866
Submissions
405,787


class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int visited[26] = {0};
        int freq[26] = {0};
        
        string ans = "";
        
        for(int i = 0; i<s.length(); i++)
            freq[s[i]-'a']++;
        
        
        for(int i = 0; i<s.length(); i++)
        {
            int index = s[i] - 'a';
            
            freq[index]--;
            
            if(!visited[index])
            {
                while(!ans.empty() && ans.back() > s[i] && freq[ans.back() - 'a'] > 0)
                {
                    visited[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                
                ans.push_back(s[i]);
                visited[index] = 1;
            } 
        }
        
        return ans;
    }
};
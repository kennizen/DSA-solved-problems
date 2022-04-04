Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


class Solution {
public:
    bool isValid(string s) {
        
        string ans = "";
        
        ans.push_back(s[0]);
        
        for(int i = 1; i<s.length(); i++)
        {
            if(ans.back() == s[i]-1)
                ans.pop_back();
            else if(ans.back() == s[i]-2)
                ans.pop_back();
            else if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                ans.push_back(s[i]);
            else
                return false;
        }
        
        if(ans.length() == 0)
            return true;
        return false;
    }
};
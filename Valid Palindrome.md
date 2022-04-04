A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.


class Solution {
public:
    
    bool isValid(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }
    
    char toLowercase(char c)
    {
        if(c >= 'A' && c <= 'Z')
            return (c - 'A') + 'a';
        return c;
    }
    
    bool isPalindrome(string s) {
        
        string res;
            
        int n = s.size();
        
        for(int i = 0; i<n; i++)
        {
            if(isValid(s[i]))
                res.push_back(toLowercase(s[i]));                
        }
        
        if(res.size() == 0)
            return true;
        
        int i = 0, j = res.size() - 1;
        
        while(i <= j)
        {
            if(res[i] == res[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};
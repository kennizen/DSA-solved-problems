Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

intuition - since we use two pointers for the approach. So if i != j then either
            i does not belong in the string or j. So delete one of each and check the remaining
            string.

class Solution {
private:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                return (isPalindrome(s,i,j-1) || isPalindrome(s,i+1,j));
            }
            i++;
            j--;
        }
        return true;
    }
};
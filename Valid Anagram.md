Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


class Solution {
public:
    bool isAnagram(string m, string r) {
        unordered_map<char, int> umap;
        
        if(m.length() != r.length())
        {
            return false;
        }
        
        for(int i = 0; i<m.length(); i++)
        {
            if(umap.find(m[i]) != umap.end())
            {
                umap[m[i]]++;
            }
            else
            {
                umap.insert({m[i],1});
            }
        }
        
        for(int i = 0; i < r.length(); i++)
        {
            if(umap.find(r[i]) == umap.end())
                return false;
            else
                if(umap[r[i]] <= 0)
                    return false;
                umap[r[i]]--;
        }
        
        return true;
    }
};
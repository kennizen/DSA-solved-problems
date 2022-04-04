Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.


class Solution {
public:
    bool canConstruct(string r, string m) {
        
        unordered_map<char, int> umap;
        
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
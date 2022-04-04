The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

 

Example 1:

Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
Example 2:

Input: n = 5, k = 73
Output: "aaszz"
 

Constraints:

1 <= n <= 105
n <= k <= 26 * n

solution mine---
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        
        vector<int> v;
        
        int sum = 0;
        
        for(int i = 0; i<n; i++)
            v.push_back(26);
        
        for(int i = 0; i<v.size(); i++)
            sum += v[i];
        
        
        for(int i = 0; i<v.size(); i++)
        {
            if(sum == k)
                break;
            
            v[i] = 1;
            sum -= 25;
            
            if(sum < k)
            {
                int l = 1;
                for(int j = 2; j<=26; j++)
                {
                    v[i] = j;
                    sum += j-l;
                    l++;
                    if(sum == k)
                        break;
                }
            }
        }
        
        for(int i = 0; i<v.size(); i++)
            res.push_back(v[i] + 96);
        
        return res;
    }
};

solution discuss---
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s="";
        for(int i=0;i<n;i++)
            s+='a';
        k=k-n;
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)
                break;
            else if(k<25)
            {
                s[i] = (char)('a'+k);          //using (char) to convert ASCII to respective character
                k=0;
            }
            else{
                s[i] = (char)('a'+25);
                k = k - 25;
            }
        }
        return s;
    }
};
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.


class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.length();
        int m = b.length();
        
        char carry = '0';
        
        int i = n-1;
        int j = m-1;
        
        while(i >= 0 && j >= 0){
            if(a[i] == '0' && b[j] == '0'){
                if(carry == '1'){
                    ans.push_back('1');
                    carry = '0';
                } 
                else ans.push_back('0');
            } 
            else if(a[i] == '1' && b[j] == '1'){
                if(carry == '1') ans.push_back('1');
                else ans.push_back('0');
                carry = '1';
            }
            else if((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0')){
                if(carry == '1'){
                    ans.push_back('0');
                    carry = '1';
                } 
                else ans.push_back('1');
            }
            i--;
            j--;
        }
        
        while(i >= 0){
            if(carry == '1' && a[i] == '1' && i-1 < 0){
                ans.push_back('0');
                ans.push_back('1');
                carry = '0';
            }
            else if(carry == '1' && a[i] == '1'){
                ans.push_back('0');
                carry = '1';
            }
            else if(carry == '1' && a[i] == '0'){
                ans.push_back('1');
                carry = '0';
            }
            else if(carry == '0'){
                ans.push_back(a[i]);
            }
            i--;
        }
        
        while(j >= 0){
            if(carry == '1' && b[j] == '1' && j-1 < 0){
                ans.push_back('0');
                ans.push_back('1');
                carry = '0';
            }
            else if(carry == '1' && b[j] == '1'){
                ans.push_back('0');
                carry = '1';
            }
            else if(carry == '1' && b[j] == '0'){
                ans.push_back('1');
                carry = '0';
            }
            else if(carry == '0'){
                ans.push_back(b[j]);
            }
            j--;
        }
        
        if(carry == '1') ans.push_back('1');
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;
        
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
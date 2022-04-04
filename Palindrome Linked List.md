Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode *reverse(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL)
        {
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
            else
                fast = fast->next;
        }
        
        ListNode *res = reverse(slow);
        ListNode *nl = res;
        
        fast = head;
        
        while(res != NULL)
        {
            if(fast->val != res->val)
                return false;
            res = res->next;
            fast = fast->next;
        }
        
        reverse(nl);
         
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode res;
        res.next = NULL;
        
        ListNode *tmp = head;
        ListNode *tmp3 = &res;
        
        while(tmp != NULL)
        {
            ListNode *newNode = new ListNode();
            newNode->next = NULL;
            newNode->val = tmp->val;
            newNode->next = tmp3;
            tmp3 = newNode;
            tmp = tmp->next;
        }
        
        tmp = head;
        
        while(tmp != NULL)
        {
            if(tmp->val != tmp3->val)
                return false;
            tmp = tmp->next;
            tmp3 = tmp3->next;
        }
        
        return true;
        
    }
};
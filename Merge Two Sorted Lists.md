You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.


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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode res;
        
        res.next = NULL;
        
        ListNode *pres = &res;
        
        ListNode *i = l1;
        ListNode *j = l2;
        
        while(i != NULL && j != NULL)
        {
            ListNode *tmp;
            
            tmp->next = NULL;
            
            if(i->val <= j->val)
            {
                tmp = i;
                pres->next = tmp;
                i = i->next;
            }
            else
            {
                tmp = j;
                pres->next = tmp;
                j = j->next;
            }
            pres = tmp;
        }
        
        if(i != NULL)
            pres->next = i;  
        
        if(j != NULL)
            pres->next = j;
        
        return res.next;
        
    }
};
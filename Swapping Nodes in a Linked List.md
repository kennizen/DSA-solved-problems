You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100


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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        
        ListNode *tmp = head;
        
        while(tmp != NULL){
            len++;
            tmp = tmp->next;
        }
        
        if(len == 1){
            return head;
        }
        
        tmp = head;
        ListNode *tmp2 = head;
        
        int lim1 = k-1;
        int lim2 = len-k;
        
        while(lim1--){
            tmp = tmp->next;
        }
        
        while(lim2--){
            tmp2 = tmp2->next;
        }
        
        swap(tmp->val, tmp2->val);
        
        return head;
    }
};

intuition - since we got the distance of k then by keeping that constant we can
            find the kth element from head and kth element from back

ListNode* swapNodes(ListNode* head, int k) 
{
    ListNode *p1 = head;
    for(int i=1; i<k; i++)
        p1 = p1->next;
    
    ListNode *slow = head, *fast = p1->next;
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    swap(slow->val, p1->val);
    return head;
} 
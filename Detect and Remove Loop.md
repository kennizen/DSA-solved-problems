Problem Statement
Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.
Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.
Input format:
The first line of input contains two values: the number of nodes in the linked list and the value of the kth node from which the last node connects to form the loop while the second line of input contains the given linked list.
The value of k should be greater than or equal to 0 and less than equal to n. For, k equal to 0, there is no loop present in the linked list and for k equal to n, the last node is connected to itself to form the cycle.
Output Format:
The only output line contains the linked list after removing the loop if present.
Constraints:
1 <= N <= 100000.
1 <= ‘VAL’ <= 1000 .  

Time limit: 1 sec
Sample Input:
6 2
1 2 3 4 5 6 
Sample Output:
1 2 3 4 5 6
Explanation:
For the given input linked list, the last node is connected to the second node as:

Now, after detecting and removing this loop the linked list will be:


/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    if(head->next == head)
    {
        head->next = NULL;
        return head;
    }
    
    Node *slow = head;
    Node *fast = head;
    
    // to keep track of the last node in the loop
    Node *prev = NULL; 
    
 	while(fast != NULL && slow != NULL)
    {
        // updating prev to keep track of last node
        prev = slow; 
        slow = slow->next;
        fast = fast->next;
        
        if(fast->next != NULL)
            fast = fast->next;
        else
            // if fast->next is NULL then no loop, return head;
            return head; 
        
        if(slow == fast)
            break;  
    }
    
    /* after finding point off intersection
    A + B = KC if K = 1 then and we know B then slow
    and fast must travel A distance to meet at starting
    point */
    
    slow = head;
    
    while(slow != fast)
    {
        slow = slow->next;
        
        /* since slow is pointing to head prev will be pointing to fast to keep track of
        the last node */
        prev = fast;
        
        fast = fast->next;
    }
    
    /* when slow and fast meet then that is the starting node of the loop,
    hence prev will be then pointing to the last node of the list. We then make the 
    last node point to null removing the loop */
    prev->next = NULL;
    
    return head;
}
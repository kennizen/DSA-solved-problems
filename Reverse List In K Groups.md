Problem Statement
You are given a linked list of 'N' nodes and an integer 'K'. You have to reverse the given linked list in groups of size K i.e if the list contains x nodes numbered from 1 to x, then you need to reverse each of the groups (1,K),(K+1,2*K), and so on.
For example, if the list is [1, 2, 3, 4, 5, 6] and K = 2, then the new list will be [2, 1, 4, 3, 6, 5].
Note:
1. In case the number of elements in the last cannot be evenly divided into groups of size k, then just reverse the last group(with any size). For example if the list is 1 2 3 4 5 and K = 3, then the answer would be 3 2 1 5 4.

2. All the node values will be distinct.
Input Format:
The first line of input contains an integer 'T' representing the number of test cases. Then T test cases follow.

The first line of each test case contains a Linked list whose elements are separated by space and the linked list is terminated by -1.

The second line of each test case contains an integer K.
Output Format:
 For each test case print the elements of  modified linked list separated by space..

The output of each test case will be printed in a separate line.
Note:
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100   
1 <= N <= 10^4
1 <= K <= 10^4

Time Limit: 1sec
Sample Input 1:
2
1 2 3 4 5 6 -1
2
5 4 3 7 9 2 -1
4 
Sample Output 1:
2 1 4 3 6 5
7 3 4 5 2 9
Explanation Of The Sample Input1:
For the first test case, we reverse the nodes in groups of two, so we get the modified linked list as 2 1 4 3 6 5.
For the second test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so we reverse those two elements only. Hence the linked list becomes 7 3 4 5 2 9.
Sample Input 2:
2
3 2 1 4 5 6 -1
1
4 3 2 8 -1
4 
Sample Output 2:
3 2 1 4 5 6
4 3 2 8


/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    
    Node *tmp = NULL;
    Node *cur = head;
    Node *prev = NULL;
    
    int count = 0;
    
    while(count < k && cur != NULL)
    {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
        count++;
    }
    
    if(tmp != NULL)
        head->next = kReverse(tmp, k);
    
    return prev;
}
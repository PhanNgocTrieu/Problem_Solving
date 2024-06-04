/*
  Given the head of a linked list, rotate the list to the right by k places.
  Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]

  Example 2:
    Input: head = [0,1,2], k = 4
    Output: [2,0,1]
*/
class Solution {
public:
    int Len(ListNode* head)
    {
        int l = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            temp = temp->next;
            l++;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        int len = Len(head);
        int num = k % len;
        if (num == 0)
            return head;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = head;  // Form a circular linked list
        
        // Find the new tail: len - num - 1 steps from the head
        ListNode* newTail = head;
        for(int i = 0; i < len - num - 1; i++)
        {
            newTail = newTail->next;
        }
        
        // The new head is the next node after the new tail
        ListNode* newHead = newTail->next;
        newTail->next = NULL;  // Break the circular linked list
        
        return newHead;
    }
};

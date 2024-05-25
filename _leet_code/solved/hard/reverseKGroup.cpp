#include "common.h"

/**
 * @brief
 *      Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 *      k is a positive integer and is less than or equal to the length of the linked list.
 *      If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 *      You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *
 *
 *      Example:
 *          Input: head = [1,2,3,4,5], k = 2
 *          Output: [2,1,4,3,5]
 *
 * @param head The head of the list
 * @param k the number of elems in each group for reversing
 * @return ListNode*
 */
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr)
    {
        return new ListNode();
    }

    ListNode *result = new ListNode();
    ListNode *ref_result = result;
    stack<ListNode *> node_stack;
    ListNode *temp_run = head;
    int n = k;

    do
    {
        // Pushing elements on stack
        node_stack.push(temp_run);

        // Reducing the number of k
        n--;

        // If node numbers == k then pushing into the result
        if (n == 0)
        {
            // Travelling through the node_stack
            while (!node_stack.empty())
            {
                // Making new node on result list;
                ref_result->next = new ListNode(node_stack.top()->val);
                ref_result = ref_result->next;

                // Reference to the next elemet (for the rest of list when the list is not enough k elem)
                ref_result->next = temp_run->next;
                // Delete the node
                node_stack.pop();
            }

            // Reset k-group
            n = k;
        }

        // next elem of head
        temp_run = temp_run->next;
    } while (temp_run != nullptr);

    return result->next;
}

int main()
{
    return 0;
}
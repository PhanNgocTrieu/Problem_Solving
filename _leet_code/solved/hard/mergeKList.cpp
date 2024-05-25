#include <bits/stdc++.h>
#include <vector>
#include "common.h"
using namespace std;

/**
 * @brief
 *          You are given an array of k linked-lists lists, each linked-list is sorted
 *          in ascending order. Merge all the linked-lists into one sorted linked-list
 *          and return it.
 *
 *          Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *          Output: [1,1,2,3,4,4,5,6]
 *
 *          Explanation: The linked-lists are:
 *          [
 *              1->4->5,
 *              1->3->4,
 *              2->6
 *          ]
 *          merging them into one sorted list: 1->1->2->3->4->4->5->6
*
* @param lists
* @return ListNode*
*/
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *result = nullptr;
    ListNode *lastNode = nullptr;
    int sizeOflists = lists.size();
    while (true)
    {
        int min = 9999;
        int countOfNull = 0;
        int rememberIndex = -1;
        for (int index = 0; index < sizeOflists; ++index)
        {
            if (lists[index] != nullptr)
            {
                if (lists[index]->val < min)
                {
                    min = lists[index]->val;
                    rememberIndex = index;
                }
            }
            else
            {
                countOfNull++;
            }
        }

        // When all of lists on container are null -> we do not need to check any more
        if (countOfNull == sizeOflists)
        {
            break;
        }

        // Concanate val in list
        if (rememberIndex > -1)
        {
            if (result == nullptr)
            {
                result = lists[rememberIndex];
                lists[rememberIndex] = lists[rememberIndex]->next;
                lastNode = result;
            }
            else
            {
                ListNode *new_node = new ListNode(lists[rememberIndex]->val);
                lastNode->next = new_node;
                lastNode = new_node;
                lists[rememberIndex] = lists[rememberIndex]->next;
            }
        }
        else
        {
            break;
        }
    }

    // ======================= Another way -> faster ===================== //
    /*
    priority_queue<int> pq;
    for (auto it : lists)
    {
        while (it)
        {
            pq.push(-it->val);
            it = it->next;
        }
    }
    ListNode *dummy = new ListNode();
    ListNode *ans = dummy;
    while (!pq.empty())
    {
        ans->next = new ListNode(-pq.top());
        pq.pop();
        ans = ans->next;
    }
    return dummy->next;
    */

    return result;
}
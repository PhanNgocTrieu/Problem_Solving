#ifndef HARD_LEETCODE_H
#define HARD_LEETCODE_H

#include "common.h"

namespace leetcode
{
    class hardLevel
    {
    public:
        /**
         * **********************************************************************************
         *                       @brief Problems of Hard Levels                             *
         * **********************************************************************************
         */
        /**
         * @brief
         *      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
         *      The overall run time complexity should be O(log (m+n)).
         *
         * @param nums1
         * @param nums2
         * @return double
         */
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);

        /**
         * @brief
         *
         * @param s
         * @param p
         * @return true
         * @return false
         */
        bool isMatch(string s, string p);

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
                    [
                        1->4->5,
                        1->3->4,
                        2->6
                    ]
                    merging them into one sorted list:
                    1->1->2->3->4->4->5->6
            * 
            * @param lists 
            * @return ListNode* 
            */
        ListNode* mergeKLists(vector<ListNode*>& lists);

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
        ListNode* reverseKGroup(ListNode* head, int k);

        /**
         * @brief Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
         * 
         * @example 
         *      Input: n = 13, Output: n = 6
         *      Input: n = 0, Output: n = 0
         *      Input: n = 100, Output: n = 21
         * 
         * @param n 
         * @return int 
         */
        int countDigitOne(int n);
    };
};

#endif // HARD_LEETCODE_H
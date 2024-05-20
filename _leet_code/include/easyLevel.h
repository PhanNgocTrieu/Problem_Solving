#ifndef __LEETCODE_H
#define __LEETCODE_H

#include "common.h"

namespace leetcode
{
    typedef enum
    {
        easy,
        medium,
        hard
    } LevelOfProblems;

    class easyLevel : public ProblemSolving
    {
        /**
         * **********************************************************************************
         *                       @brief Problems of Easy Levels                             *
         * **********************************************************************************
         */
    public:
        /*
            Given two binary strings a and b, return their sum as a binary string.

            Example 1:
            Input: a = "11", b = "1"
            Output: "100"
            Example 2:

            Input: a = "1010", b = "1011"
            Output: "10101"

        */
        string addBinary(string a, string b);

        /**
         * Write a function to find the longest common prefix string amongst an array of strings.
         *
         * If there is no common prefix, return an empty string "".
         *
         * Example 1:
         *
         * Input: strs = ["flower", "flow", "flight"]
         * Output : "fl"
         *
         * Example 2 :
         *
         * Input : strs = ["dog", "racecar", "car"]
         * Output : ""
         *
         * Explanation : There is no common prefix among the input strings.
         */
        string longestCommonPrefix(vector<string> &strs);

        /*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

        You may assume that each input would have exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.

        Example 1:

        Input: nums = [2, 7, 11, 15], target = 9
        Output : [0, 1]
        Because nums[0] + nums[1] == 9, we return[0, 1].

        */
        vector<int> twoSum(vector<int> &nums, int target);

        /*
            Implement strStr().

            Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

            Clarification:

            What should we return when needle is an empty string ? This is a great question to ask during an interview.

            For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().



            Example 1:

            Input: haystack = "hello", needle = "ll"
            Output : 2
            Example 2 :

                Input : haystack = "aaaaa", needle = "bba"
                Output : -1
                Example 3 :

                Input : haystack = "", needle = ""
            Output :0

        */

        int strStr(string haystack, string needle);

        /*

            Given the root of a binary tree, return the postorder traversal of its nodes' values.

            Input: root = [1,null,2,3]
            Output: [3,2,1]
            Example 2:

            Input: root = []
            Output: []
            Example 3:

            Input: root = [1]
            Output: [1]

        */
        vector<int> postorderTraversal(TreeNode *root);

        /*
            Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

            Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

            Clarification:

            Confused why the returned value is an integer but your answer is an array?

            Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

            Internally you can think of this:

            // nums is passed in by reference. (i.e., without making a copy)
            int len = removeDuplicates(nums);

            // any modification to nums in your function would be known by the caller.
            // using the length returned by your function, it prints the first len elements.
            for (int i = 0; i < len; i++) {
                print(nums[i]);
            }


            Example 1:

            Input: nums = [1,1,2]
            Output: 2, nums = [1,2]
            Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
            It doesn't matter what you leave beyond the returned length.
            Example 2:

            Input: nums = [0,0,1,1,1,2,2,3,3,4]
            Output: 5, nums = [0,1,2,3,4]
            Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
            It doesn't matter what values are set beyond the returned length.
        */
        int removeDuplicates(vector<int> &nums);

        /*
            Given a sorted array of distinct integers and a target value,
            return the index if the target is found. If not,
            return the index where it would be if it were inserted in order.
            You must write an algorithm with O(log n) runtime complexity.

            Example 1:
            Input: nums = [1,3,5,6], target = 5
            Output: 2
            Example 2:

            Input: nums = [1,3,5,6], target = 2
            Output: 1
            Example 3:

            Input: nums = [1,3,5,6], target = 7
            Output: 4
            Example 4:

            Input: nums = [1,3,5,6], target = 0
            Output: 0
            Example 5:

            Input: nums = [1], target = 0
            Output: 0
        */

        int findPos(vector<int> &nums, int target);
        int searchInsert(vector<int> &nums, int target);

        /*
            Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

            You must implement a solution with a linear runtime complexity and use only constant extra space.

            Example 1:

            Input: nums = [2,2,1]
            Output: 1
            Example 2:

            Input: nums = [4,1,2,1,2]
            Output: 4
            Example 3:

            Input: nums = [1]
            Output: 1
        */

        int singleNumber(vector<int> &nums);

        /**
         * @brief
         *          Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
         *          Return the linked list sorted as well.
         *
         * @param head
         * @return ListNode*
         */
        ListNode *deleteDuplicates(ListNode *head);

        /**
         * @brief
         *          You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
         *          and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
         *
         *          Merge nums1 and nums2 into a single array sorted in non-decreasing order.
         *
         *          The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
         *          To accommodate this, nums1 has a length of m + n,
         *          where the first m elements denote the elements that should be merged,
         *          and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
         *
         * @param nums1
         * @param m
         * @param nums2
         * @param n
         */
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

        /**
         * @brief Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
         *
         * @param columnTitle
         * @return int
         */
        int titleToNumber(string columnTitle);

        /**
         * @brief Given the roots of two binary trees p and q, write a function to check if they are the same or not.
         * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
         *
         * @param p
         * @param q
         * @return true
         * @return false
         */
        bool isSameTree(TreeNode *p, TreeNode *q);

        /**
         * @brief Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
         *
         *
         *          1
         *      /       \
         *     2         2
         *   /   \      /  \
         *  3    4     4    3
         * Input: root = [1,2,2,3,4,4,3]
         * Output: true
         *
         * @param root
         * @return true or false
         */
        bool isSymmetric(TreeNode *root);

        /**
         * @brief A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
         *
         *              3
         *           /     \
         *         9        20
         *       /   \     /   \
         *    null  null  15    7
         *
         * Input: root = [3,9,20,null,null,15,7]
         * Output: 3
         * @param root
         * @return int
         */
        int maxDepth(TreeNode *root);

        /**
         * @brief   Given a binary tree, determine if it is height-balanced.
         *          For this problem, a height-balanced binary tree is defined as:
         *              a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
         *
         * @param root
         * @return true
         * @return false
         */
        bool isBalanced(TreeNode *root);
        int dfsHeight(TreeNode *node);

        /**
         * @brief
         *      International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
         *              'a' maps to ".-",
         *              'b' maps to "-...",
         *              'c' maps to "-.-.", and so on.
         *
         * @param words
         * @return int
         */
        int uniqueMorseRepresentations(vector<string> &words);

        /**
         * @brief
         *           Given a string s, reverse the order of characters in each word within a
         *           sentence while still preserving whitespace and initial word order.
         *
         *           Input: s = "Let's take LeetCode contest"
         *           Output: "s'teL ekat edoCteeL tsetnoc"
         *
         * @param s
         * @return string
         */
        string reverseWords(string s);

        /**
         * @brief
         *          Given the root of a binary tree and an integer targetSum, return true if the
         *          tree has a root-to-leaf path such that adding up all the values along the path
         *          equals targetSum.
         *
         *          A leaf is a node with no children.
         *
         * @param root a tree which invoke searching
         * @param targetSum target sum value for finding
         * @return result of finding target Sum
         */
        bool hasPathSum(TreeNode *root, int targetSum);

        /*
            Given a binary tree, find its minimum depth.
            The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

            Note: A leaf is a node with no children.
        */
        int minDepth(TreeNode* root);

        /**
         * @brief 
         *          Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
         *          You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
         *          You must also not convert the inputs to integers directly.
         * 
         *          Example:
         *              Input: num1 = "11", num2 = "123"
         *              Output: "134"
         *          
         *          Example: 
         *              Input: num1 = "456", num2 = "77"
         *              Output: "533"
         * @param num1 
         * @param num2 
         * @return string 
         */
        string addStrings(string num1, string num2);

        /**
         * @brief 141. Linked List Cycle
         * 
         *      Given head, the head of a linked list, determine if the linked list has a cycle in it.
         *      There is a cycle in a linked list if there is some node in the list that can be reached again 
         *      by continuously following the next pointer. 
         * 
         *      Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
         *      Note that pos is not passed as a parameter.
         * 
         * 
         *      Return true if there is a cycle in the linked list. Otherwise, return false.
         * 
         * @param head 
         * @return true 
         * @return false 
         */
        bool hasCycle(ListNode *head);


        /**
         * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
         * If the two linked lists have no intersection at all, return null.
         * 
         * The intersected node is the node that two list point to the same location in memory
        */
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

        /**
         * @brief Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
         * 
         *  Example:
         *      A   ->  1
         *      B   ->  2
         *      C   ->  3
         *      .....
         *      Z   ->  26
         *      AA  ->  27
         * 
         * @param columnNumber 
         * @return string 
         */
        string convertToTitle(int columnNumber);

        /*
            The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
            You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
            For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
            If there is no next greater element, then the answer for this query is -1.
            Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

            Example 1:
            Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
            Output: [-1,3,-1]
            Explanation: The next greater element for each value of nums1 is as follows:
            - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
            - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
            - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
        */
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);

        /**
         * You are given an n x n integer matrix grid. 
         * Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
         *      maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
         *      In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
         * 
         * Return the generated matrix.
        */
        vector<vector<int>> largestLocal(vector<vector<int>>& grid);

        /*
            You are given the root of a full binary tree with the following properties:
                Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
                Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
            The evaluation of a node is as follows:
                If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
                Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
                Return the boolean result of evaluating the root node.

            A full binary tree is a binary tree where each node has either 0 or 2 children.
            A leaf node is a node that has zero children.

            Example:
                   OR               =>             OR               =>          Truew
                  /  \                            /  \
                /     \                          /    \
              true    And                      True   False
                     /  \
                    /    \
                 False  True
        */
        bool evaluateTree(TreeNode* root);

        /*
            Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). 
            If the character ch does not exist in word, do nothing.
            
            For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). 
            The resulting string will be "dcbaefd".
            Return the resulting string.

            Input: word = "abcdefd", ch = "d"
            Output: "dcbaefd"
            Explanation: The first occurrence of "d" is at index 3. 
            Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
        */
        string reversePrefix(string word, char ch);

        /*
            The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
            For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
            Given an array nums, return the sum of all XOR totals for every subset of nums. 
            Note: Subsets with the same elements should be counted multiple times.
            An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

            Example
                Input: nums = [5,1,6]
                Output: 28
                Explanation: The 8 subsets of [5,1,6] are:
                - The empty subset has an XOR total of 0.
                - [5] has an XOR total of 5.
                - [1] has an XOR total of 1.
                - [6] has an XOR total of 6.
                - [5,1] has an XOR total of 5 XOR 1 = 4.
                - [5,6] has an XOR total of 5 XOR 6 = 3.
                - [1,6] has an XOR total of 1 XOR 6 = 7.
                - [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
                => 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
        */
        int subsetXORSum(vector<int>& nums);
        /* Supported function */
        int XORSum(vector<int>& nums, int index, int currentXOR);
    };
};

#endif

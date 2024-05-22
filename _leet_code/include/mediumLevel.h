#ifndef _MEDIUM_LEETCODE_H_
#define _MEDIUM_LEETCODE_H_

#include "common.h"

namespace leetcode
{

    class mediumLevel : public ProblemSolving
    {

    public:
        enum VAR_TYPE
        {
            CHAR = 0,
            INT,
            LONG,
            LONGLONG,
            FLOAT,
            DOUBLE,
            STRING
        };

        mediumLevel()
        {
            ios::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
        }

    public:
        /**
         * **********************************************************************************
         *                       @brief Problems of Medium Levels                           *
         * **********************************************************************************
         */

        /*
            Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

            An input string is valid if:

            Open brackets must be closed by the same type of brackets.
            Open brackets must be closed in the correct order.


            Example 1:

            Input: s = "()"
            Output : true
            Example 2 :

                Input : s = "()[]{}"
                Output : true
                Example 3 :

                Input : s = "(]"
                Output : false
                Example 4 :

                Input : s = "([)]"
                Output : false
                Example 5 :

                Input : s = "{[]}"
                Output : true
        */
        bool isValid(string s);

        /*
            Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

            The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

            It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

            Example 1:

            Input: candidates = [2,3,6,7], target = 7
            Output: [[2,2,3],[7]]
            Explanation:
            2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
            7 is a candidate, and 7 = 7.
            These are the only two combinations.
            Example 2:

            Input: candidates = [2,3,5], target = 8
            Output: [[2,2,2,2],[2,3,3],[3,5]]
            Example 3:

            Input: candidates = [2], target = 1
            Output: []
            Example 4:

            Input: candidates = [1], target = 1
            Output: [[1]]
            Example 5:

            Input: candidates = [1], target = 2
            Output: [[1,1]]
        */
        vector<vector<int>> combinationSum(vector<int> &candidates, int target);

        /*
            Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

            Symbol       Value
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
            For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

            Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

            I can be placed before V (5) and X (10) to make 4 and 9.
            X can be placed before L (50) and C (100) to make 40 and 90.
            C can be placed before D (500) and M (1000) to make 400 and 900.
            Given an integer, convert it to a roman numeral.

            Example 1:

            Input: num = 3
            Output: "III"
            Example 2:

            Input: num = 4
            Output: "IV"
            Example 3:

            Input: num = 9
            Output: "IX"
            Example 4:

            Input: num = 58
            Output: "LVIII"
            Explanation: L = 50, V = 5, III = 3.
            Example 5:

            Input: num = 1994
            Output: "MCMXCIV"
            Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
        */
        string intToRoman(int num);

        /*
            Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

            The algorithm for myAtoi(string s) is as follows:

            Read in and ignore any leading whitespace.
            Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
            Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
            Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
            If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
            Return the integer as the final result.
            Note:

            Only the space character ' ' is considered a whitespace character.
            Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
        */
        // First way:
        int myAtoi(string s);

        /*
            Given a string s, return the longest palindromic substring in s.
            Example 1:
            Input: s = "babad"
            Output: "bab"
            Note: "aba" is also a valid answer.
            Example 2:
            Input: s = "cbbd"
            Output: "bb"

        */
        int pallindromeLength(int &l, int &r, string &s);
        string longestPalindrome(string s);

        /**
         * @brief
         *
         *  Given a string s, find the length of the longest substring without repeating characters.
         *  Input: s = "abcabcbb"
         *  Output: 3
         *  Explanation: The answer is "abc", with the length of 3.

         * @param s
         * @return int
         */
        int lengthOfLongestSubstring(string s);

        /**
         * @brief
         *      Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
         *
         *      Input: nums = [0,1]
         *      Output: 2
         *      Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
         *
         *      Input: nums = [0,1,0]
         *      Output: 2
         *      Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
         *
         * @param nums
         * @return int
         */
        int findMaxLength(vector<int> &nums);

        /**
         * @brief Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c]] such that:
         * 0 <= a, b, c < n
         * a, b and c are distinct.
         * nums[a] + nums[b] + nums[c] == 0
         *
         * @param nums
         * @return vector<vector<int>>
         */
        vector<vector<int>> threeSum(vector<int> &nums);

        /**
         * @brief Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
         * 0 <= a, b, c, d < n
         * a, b, c, and d are distinct.
         * nums[a] + nums[b] + nums[c] + nums[d] == target
         *
         * You may return the answer in any order.
         *
         * @param nums
         * @param target
         * @return vector<vector<int>>
         */
        vector<vector<int>> fourSum(vector<int> &nums, int target);

        /**
         * @brief Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
         *
         * @example
         *          Input: x = 2.00000, n = 10
         *          Output: 1024.00000
         *
         *          Input: x = 2.10000, n = 3
         *          Output: 9.26100
         *
         *
         *          Input: x = 2.00000, n = -2
         *          Output: 0.25000
         *          Explanation: 2-2 = 1/2^2 = 1/4 = 0.25
         *
         *
         * @param x
         * @param n
         * @return double
         */
        double myPow(double x, int n);

        /**
         * @brief Container with Most Water - problem
         *
         * @param height Array of the height of water
         * @return int Result of the max area
         */
        int maxArea(const vector<int> &height);

        /**
         * @brief Given the head of a linked list, remove the nth node from the end of the list and return its head.
         *
         * @param head
         * @param n
         * @return ListNode*
         */
        ListNode *removeNthFromEnd(ListNode *head, int n);

        /**
         * @brief   Given an integer array nums of length n and an integer target,
         *          find three integers in nums such that the sum is closest to target.
         *          Return the sum of the three integers.
         *
         *          You may assume that each input would have exactly one solution.
         *
         * @param nums
         * @param target
         * @return int
         */
        int threeSumClosest(std::vector<int> &nums, int target);

        /**
         * @brief   Given a linked list, swap every two adjacent nodes and return its head.
         *          You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
         *
         */
        ListNode *swapPairs(ListNode *head);

        /**
         * @brief
         *
         *          Given an integer n,
         *          return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.
         *
         *
         *          Input: n = 1
         *          Output: 1
         *          Explanation: "1" in binary corresponds to the decimal value 1.
         *
         *          Input: n = 3
         *          Output: 27
         *          Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
         *          After concatenating them, we have "11011", which corresponds to the decimal value 27.
         *
         * @param n
         * @return int
         */
        int concatenatedBinary(int n);

        /**
         * @brief
                    There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
                    After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
                    When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
                    For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

                    You are given a string dominoes representing the initial state where:
                    dominoes[i] = 'L', if the ith domino has been pushed to the left,
                    dominoes[i] = 'R', if the ith domino has been pushed to the right, and
                    dominoes[i] = '.', if the ith domino has not been pushed.
                    Return a string representing the final state.
         *
         * @param dominoes
         * @return string
         */
        string pushDominoes(string dominoes);

        /*
            Given the root of a binary tree, flatten the tree into a "linked list":
            The "linked list" should use the same TreeNode class where
            the right child pointer points to the next node in the list and the left child pointer is always null.

            The "linked list" should be in the same order as a pre-order traversal of the binary tree.
        */
        void flatten(TreeNode *root);

        /**
            There is an integer array nums sorted in ascending order (with distinct values).

            Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

            Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

            You must write an algorithm with O(log n) runtime complexity.

            Example 1:
                Input: nums = [4,5,6,7,0,1,2], target = 0
                Output: 4
        */
        int searchRotatedSortedArray(vector<int> &nums, int target);

        /**
            Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

            If target is not found in the array, return [-1, -1].

            You must write an algorithm with O(log n) runtime complexity.

            Example:
                Input: nums = [5,7,7,8,8,10], target = 8
                Output: [3,4]

            You must write an algorithm with O(log n) runtime complexity.
        */
        vector<int> searchRange(vector<int> &nums, int target);

        /**
         * Given two non-negative integers num1 and num2 represented as strings,
         * return the product of num1 and num2, also represented as a string.
         *
         * Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
         *
         * Example:
         *      Input: num1 = "56", num2 = "21"
         *      Output: "1176"
         */
        string multiply(string num1, string num2);

        /**
         * @brief
         *
         *          Given an integer array nums,
         *          return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
         *          If no such indices exists, return false.
         *
         *          Example 1:
         *              Input: nums = [1,2,3,4,5]
         *              Output: true
         *          Explanation: Any triplet where i < j < k is valid.
         * @param nums
         * @return true
         * @return false
         */
        bool increasingTriplet(vector<int> &nums);

        /**
         * @brief
         *
         *      Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
         *      Each row must contain the digits 1-9 without repetition.
         *      Each column must contain the digits 1-9 without repetition.
         *      Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
         *
         *      Note:
         *          A Sudoku board (partially filled) could be valid but is not necessarily solvable.
         *          Only the filled cells need to be validated according to the mentioned rules.
         *
         * @param board
         * @return true
         * @return false
         */
        bool isValidSudoku(vector<vector<char>> &board);

        /**
         * @brief
         *
         * @param head
         * @return ListNode*
         */
        ListNode *detectCycle(ListNode *head);

        /**
         *
         * @brief
         *
         *    Given an array of strings strs, group the anagrams together. You can return the answer in any order.
         *    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
         *    typically using all the original letters exactly once.
         *
         */
        vector<vector<string>> groupAnagrams(vector<string> &strs);

        /**
         * @brief
         *
         * @param n
         * @return string
         */
        string countAndSay(int n);

        /**
         * @brief
         *          Given the root of a binary tree and an integer targetSum,
         *          return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
         *          Each path should be returned as a list of the node values, not node references.
         *
         * @param root the root of tree
         * @param targetSum the target
         * @return vector<vector<int>> Array of paths
         */
        vector<vector<int>> pathSum(TreeNode *root, int targetSum);

        /**
         * @brief   Given an integer array nums of unique elements, return all possible subsets (the power set).
                    The solution set must not contain duplicate subsets. Return the solution in any order.


                    Input: nums = [1,2,3]
                    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
         *
         * @param nums
         * @return vector<vector<int>>
         */
        vector<vector<int>> subsets(vector<int> &nums);

        /**
         * @brief
         *          This problems is the same of subests problems
         *          but making sure that no duplicated caser in output
         */
        vector<vector<int>> subsetsWithDup(vector<int> &nums);

        /**
         * @brief
         *          You are given two string arrays words1 and words2.
         *          A string b is a subset of string a if every letter in b occurs in a including multiplicity.
         *
         *          For example, "wrr" is a subset of "warrior" but is not a subset of "world".
         *
         *          A string a from words1 is universal if for every string b in words2, b is a subset of a.
         *          Return an array of all the universal strings in words1. You may return the answer in any order.
         */
        vector<string> wordSubsets(const vector<string> &words1, const vector<string> &words2);

        /**
         * @brief
         *      Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
         *      In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.
         *      For this problem, any other format of periods such as '...' are treated as file/directory names.
         *
         *      The canonical path should have the following format:
         *          The path starts with a single slash '/'.
         *          Any two directories are separated by a single slash '/'.
         *          The path does not end with a trailing '/'.
         *          The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
         *
         *      Return the simplified canonical path.
         *
         * @example:
         *      ---------
         *      @param Input: path = "/home/"
         *      @param Output: "/home"
         *      ---------
         *      @param Input: path = "/../"
         *      @param Output: "/"
         *      ---------
         *      @param Input: "/home//foo/"
         *      @param Output: "/home/foo"
         *
         * @param path the input path which was provided
         * @return std::string the result after involked the command as the path
         */
        std::string simplifyPath(std::string path);

        /*
            Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
            with the colors in the order red, white, and blue.

            We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

            You must solve this problem without using the library's sort function.

            Example:
                Input: nums = [2,0,2,1,1,0]
                Output: [0,0,1,1,2,2]
        */
        void sortColors(vector<int> &nums);

        /*
            A wonderful string is a string where at most one letter appears an odd number of times.
            For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
            Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.
            A substring is a contiguous sequence of characters in a string.

            Example 1:
                Input: word = "aba"
                Output: 4
                Explanation: The four wonderful substrings are underlined below:
                - "aba" -> "a"
                - "aba" -> "b"
                - "aba" -> "a"
                - "aba" -> "aba"

            Example 2:
                Input: word = "aabb"
                Output: 9
                Explanation: The nine wonderful substrings are underlined below:
                - "aabb" -> "a"
                - "aabb" -> "aa"
                - "aabb" -> "aab"
                - "aabb" -> "aabb"
                - "aabb" -> "a"
                - "aabb" -> "abb"
                - "aabb" -> "b"
                - "aabb" -> "bb"
                - "aabb" -> "b"
        */
        long long wonderfulSubstrings(string word);

        ListNode *removeNodes(ListNode *head);

        /*
            You are given the head of a linked list with n nodes.
            For each node in the list, find the value of the next greater node.
            That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

            Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed).
            If the ith node does not have a next greater node, set answer[i] = 0.

            Example:
                Input: head = [2,7,4,3,5]
                Output: [7,0,5,5,0]
        */
        vector<int> nextLargerNodes(ListNode *head);

        /*
            In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
            Return the maximum amount of gold you can collect under the conditions:
            Every time you are located in a cell you will collect all the gold in that cell.
            From your position, you can walk one step to the left, right, up, or down.
            You can't visit the same cell more than once.
            Never visit a cell with 0 gold.
            You can start and stop collecting gold from any position in the grid that has some gold.
            Example 1:
                Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
                Output: 24
                Explanation:
                [[0,6,0],
                [5,8,7],
                [0,9,0]]
                Path to get the maximum gold, 9 -> 8 -> 7.
        */
        int getMaximumGold(vector<vector<int>> &grid);

        int maximumSafenessFactor(vector<vector<int>> &grid);

        /*
            Given a binary tree root and an integer target, delete all the leaf nodes with value target.
            Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
            it should also be deleted (you need to continue doing that until you cannot).

            Example: (root, 3)                    =>                 [Result]
                        1                                               1 
                      /   \                                               \
                    3      2                                               2

            Example 2:
                    (root, 2)                    =>                  [Result]
                        1                                                1
                      /   \                                            /   \
                     2     3                                          2     3
                   /   \                                               \
                  2     1                                               1
        */
        TreeNode* removeLeafNodes(TreeNode* root, int target);

        /*
            Given an integer array nums of unique elements, return all possible subsets (the power set).
            The solution set must not contain duplicate subsets. Return the solution in any order.

            Example 1:
                Input: nums = [1,2,3]
                Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
            Example 2:
                Input: nums = [0]
                Output: [[],[0]]
        */
        vector<vector<int>> subsets(vector<int>& nums);
        // Supported function
        void generate_subset(const vector<int>& nums, int index = 0);

        /*
            Given a string s, partition s such that every substring of the partition is a palindrome. 
            Return all possible palindrome partitioning of s.

            Input: s = "aab"
            Output: [["a","a","b"],["aa","b"]]

            Input: s = "a"
            Output: [["a"]]
        */
        vector<vector<string>> partition(string s);
        void backtrack_partition(const string& s, int start, vector<string>& path, vector<vector<string>>& result);
    protected:
        // int m_dx[4] = {1, -1, 0, 0};
        // int m_dy[4] = {0, 0, 1, -1};
        vector<int> roww = {0, 0, -1, 1};
        vector<int> coll = {-1, 1, 0, 0};

        /**
         * @brief result to return with interger value
         */
        int m_res = 0;
        /**
         * @brief size of rows in 2D matrix
         */
        int m;
        /**
         * @brief size of cols in 2D matrix
         */
        int n;

        vector<vector<int>> m_2DVecRes;
        vector<int> m_1DVecTmp = {};

    private:
        /* ===================== These functions for supporting ============================= */
        std::unordered_map<int, int> getMapping(const std::vector<int> &vec)
        {
            std::unordered_map<int, int> res;
            for (auto elem : vec)
            {
                res[elem]++;
            }
            return res;
        }

        bool isFoundOnVec2D(const std::vector<vector<int>> &vec2D,
                            const std::vector<int> &vec)
        {
            for (auto elem : vec2D)
            {
                if (elem.size() == vec.size())
                {
                    std::unordered_map<int, int> firMap = getMapping(elem);
                    std::unordered_map<int, int> secMap = getMapping(vec);
                    if (firMap == secMap)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        bool isSame(vector<int> h1, vector<int> h2)
        {
            for (int i = 0; i < 26; i++)
            {
                if (h1[i] > h2[i])
                    return false;
            }
            return true;
        }

        vector<string> split(string path, char lim)
        {
            vector<string> res;
            string temp = "";
            for (char c : path)
            {
                do
                {
                    if (c == lim)
                    {
                        if (temp == "")
                        {
                            break;
                        }
                        res.push_back(temp);
                        temp = "";
                        break;
                    }
                    temp += c;
                } while (0);
            }
            if (temp != "")
            {
                res.push_back(temp);
            }
            return res;
        }

        std::string remove(std::string &str)
        {
            bool nextReturn = false;
            while (1)
            {
                if (str[str.length() - 1] == '/')
                {
                    if (nextReturn)
                    {
                        break;
                    }
                    nextReturn = true;
                }
                str.erase(str.length() - 1);
            }
            return str;
        }

        pair<ListNode *, int> reverse(ListNode *head)
        {
            if (!head || !head->next)
                return {head, (bool)head};

            ListNode *prev, *curr, *next;
            prev = nullptr;
            curr = head;
            int len = 0;

            while (curr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                len++;
            }
            return {prev, len};
        }

        void travel_around(vector<vector<int>> &grid, int r, int c, int sum)
        {
            if (r < 0 || r >= m || c < 0 || c >= n)
            {
                return;
            }
            if (grid[r][c])
            {
                int tmp = grid[r][c];
                grid[r][c] = 0;
                sum += tmp;
                m_res = std::max(m_res, sum);

                travel_around(grid, r + 1, c, sum);
                travel_around(grid, r - 1, c, sum);
                travel_around(grid, r, c + 1, sum);
                travel_around(grid, r, c - 1, sum);

                grid[r][c] = tmp;
            }
        }

        void back_tracking(vector<vector<int>> &grid, int r, int c, int t)
        {
            int k, l, x, y;
            k = grid[r][c];
            grid[r][c] = 0;
            t += k;
            if (t > m_res)
            {
                m_res = t;
            }

            for (int p = 0; p < 4; p++)
            {
                x = r + m_dx[p];
                y = c + m_dy[p];
                if (x < 0 || x == m || y < 0 || y == n)
                    continue;
                if (grid[x][y] > 0)
                {
                    back_tracking(grid, x, y, t);
                }
            }
            grid[r][c] = k;
        }

        void bfs(vector<vector<int>> &grid, vector<vector<int>> &score, int n)
        {
            queue<pair<int, int>> q;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j])
                    {
                        score[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }

            while (!q.empty())
            {
                auto t = q.front();
                q.pop();

                int x = t.first, y = t.second;
                int s = score[x][y];

                for (int i = 0; i < 4; i++)
                {
                    int newX = x + roww[i];
                    int newY = y + coll[i];

                    if (newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s)
                    {

                        score[newX][newY] = 1 + s;
                        q.push({newX, newY});
                    }
                }
            }
        }

        bool isPalindrome(const string& s, int left, int right) {
            while (left < right) {
                if (s[left++] != s[right--]) {
                    return false;
                }
            }
            return true;
        }
    };
};

#endif // _MEDIUM_LEETCODE_H_

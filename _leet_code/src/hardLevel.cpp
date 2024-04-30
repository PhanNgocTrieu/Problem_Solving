#include "hardLevel.h"

namespace leetcode
{
    /**
     * **********************************************************************************
     *                       @brief Problems of Hard Levels                             *
     * **********************************************************************************
     */
    double hardLevel::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /*  Frist way */
        const int m = nums1.size();
        const int n = nums2.size();
        bool isEven = (m + n) % 2 == 0 ? true : false;
        int medianPos = isEven ? (m + n - 1) / 2 : (m + n) / 2;
        double _result = 0;
        vector<int> _res;
        vector<int>::iterator _itrNums1 = nums1.begin();
        vector<int>::iterator _itrNums2 = nums2.begin();

        while (_itrNums1 != nums1.end() && _itrNums2 != nums2.end())
        {
            if (*_itrNums1 < *_itrNums2)
            {
                _res.push_back(*_itrNums1);
                _itrNums1++;
            }
            else
            {
                _res.push_back(*_itrNums2);
                _itrNums2++;
            }
        }

        // pushing the rest of elems in vector1
        while (_itrNums1 != nums1.end())
        {
            _res.push_back(*_itrNums1);
            _itrNums1++;
        }

        // pushing the rest of elems in vector2
        while (_itrNums2 != nums2.end())
        {
            _res.push_back(*_itrNums2);
            _itrNums2++;
        }

        _result = isEven ? (_res[medianPos + 1] + _res[medianPos]) / 2.0 : _res[medianPos] / 1.0;
        return _result;
    }

    bool hardLevel::isMatch(string s, string p)
    {
        int len_s = s.length();
        int len_p = p.length();

        uint32_t _table[35][35];

        /**
         * Filling all of data to 0
         */
        for (int idex; idex <= len_p; idex++)
        {
            for (int jdex; jdex <= len_s; jdex++)
            {
                _table[idex][jdex] = 0;
            }
        }

        // for (uint32_t idex; idex < len_s; idex++) {
        //     _table[0][idex] = 0;
        // }

        _table[0][0] = 1;

        for (int index = 1; index <= len_p; index++)
        {
            if (p[index - 1] == '*')
            {
                if (index == 1)
                {
                    _table[1][0] = 1;
                }
                else if (_table[index - 2][0])
                {
                    _table[index][0] = 1;
                }
                else
                {
                    _table[index][0] = 0;
                }
            }
            else
            {
                _table[index][0] = 0;
            }
        }

        int idex;
        int jdex;
        for (idex = 1; idex <= len_p; idex++)
        {
            for (jdex = 1; jdex <= len_s; jdex++)
            {
                if ((p[idex - 1] == s[jdex - 1]) || p[idex - 1] == '.')
                {
                    _table[idex][jdex] = _table[idex - 1][jdex - 1];
                }
                else
                {
                    if (p[idex - 1] == '*')
                    {
                        if (s[jdex - 1] == p[idex - 2] || p[idex - 2] == '.')
                        {
                            _table[idex][jdex] = (_table[idex - 2][jdex] || _table[idex][jdex - 1]);
                        }
                        else
                        {
                            _table[idex][jdex] = _table[idex - 2][jdex];
                        }
                    }
                    else
                    {
                        _table[idex][jdex] = 0;
                    }
                }
            }
        }

        return _table[idex][jdex];
    }

    ListNode *hardLevel::mergeKLists(vector<ListNode *> &lists)
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


    ListNode* hardLevel::reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
        {
            return new ListNode();
        }

        ListNode* result = new ListNode();
        ListNode* ref_result = result;
        stack<ListNode*> node_stack;
        ListNode* temp_run = head;
        int n = k;
        
        do {
            // Pushing elements on stack
            node_stack.push(temp_run);

            // Reducing the number of k
            n--;


            // If node numbers == k then pushing into the result
            if (n == 0)
            {
                // Travelling through the node_stack
                while(!node_stack.empty()) {
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
        } while(temp_run != nullptr);
        

        return result->next;
    }

    int hardLevel::countDigitOne(int n) {
        if(n == 0)
            return 0;
        unsigned int curr = n % 10;
        unsigned int left = n / 10;
        unsigned int right = 0;
        unsigned int base = 1;
        unsigned int sum = 0;
        while(curr != 0 || left != 0)
        {   
            if(curr > 1)
                sum = sum + (left+1)*base;
            else if(curr == 1)
                sum = sum + left*base + right + 1;
            else 
                sum = sum + left * base;
            if(base == 1)
                right = curr;
            else 
                right =  base*curr + right;
            curr = left%10;
            left = left/10;
            base = base * 10;
        }
        return sum;
    }
};
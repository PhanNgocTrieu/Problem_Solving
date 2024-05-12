#include "easyLevel.h"
#include "data.h"

namespace leetcode
{
    /**
     * **********************************************************************************
     *                       @brief Problems of Easy Levels                             *
     * **********************************************************************************
     */

    /**
     * @brief Solving the problems of addBinary
     *
     */
    string easyLevel::addBinary(string a, string b)
    {
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        string res = "";

        while ((m >= 0 || n >= 0) || carry)
        {
            int d1 = (m >= 0) ? a[m--] - '0' : 0;
            int d2 = (n >= 0) ? b[n--] - '0' : 0;
            int sum = d1 + d2 + carry;

            if (sum == 2)
            { // case of 1 1 0 or 1 0 1 or 0 1 1
                sum = 0;
                carry = 1;
            }
            else if (sum == 3)
            { // case  when a[i]=1,b[i]=1, carry=1;
                sum = 1;
                carry = 1;
            }
            else
                carry = 0;
            res.insert(0, to_string(sum));
        }

        return res;
    }

    /**
     * @brief Solving the problems of longestCommonPrefix
     *
     * Algorithm:
     *
     * from above example we can see:
     * taking the first element is standard:
     * strs[0] ------ f ------- l ------- o
     * checking:
     * strs[1] ------ ^ ------- ^ ------- ^
     * strs[2] ------ ^ ------- ^ ------- x -> resturn res
     * --------------------------------------
     * res =          f        fl        return
     *
     *
     */
    string easyLevel::longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        string res = "";
        int size = strs.size();
        int len = strs[0].length();

        for (int i = 0; i < len; i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < size; j++)
            {
                if (strs[j][i] != c)
                {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }

    /**
     * @brief Solving the problems of twoSum
     *
     */
    vector<int> easyLevel::twoSum(vector<int> &nums, int target)
    {
        vector<int> res;

        int len = nums.size();

        for (int index = 0; index < len; index++)
        {
            // target = num_1 + num_2 => num_2 = target - num_1
            int num_2 = target - nums[index];
            int start = index + 1;
            while (start < len)
            {
                if (nums[start] == num_2)
                {
                    res.push_back(index);
                    res.push_back(start);
                    return res;
                }
                start++;
            }
        }
        return res;
    }

    int easyLevel::strStr(string haystack, string needle)
    {
        int _lengthOfStack = haystack.length();
        int _lengthOfNeedle = needle.length();
        if (_lengthOfStack == 0 && _lengthOfNeedle == 0)
            return 0;

        for (int index = 0; index < _lengthOfStack; index++)
        {
            string temp = haystack.substr(index, _lengthOfNeedle);
            if (temp == needle)
                return index;
        }

        return -1;
    }

    /**
     * @brief Solving the problems of postorderTraversel
     *
     *
     */
    vector<int> easyLevel::postorderTraversal(TreeNode *root)
    {
        vector<int> res{};
        if (root == NULL)
            return res;
        else
        {
            vector<int> temp = postorderTraversal(root->left);
            std::copy(temp.begin(), temp.end(), std::back_inserter(res));

            temp = postorderTraversal(root->right);
            std::copy(temp.begin(), temp.end(), std::back_inserter(res));

            res.push_back(root->val);
        }
        return res;
    }

    /**
     * @brief Solving the problems of removeDuplicates
     *
     * @param nums
     * @return int
     */
    int easyLevel::removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        vector<int>::iterator ip;
        ip = std::unique(nums.begin(), nums.end());
        // Resizing the vector so as to remove the undefined terms
        nums.resize(std::distance(nums.begin(), ip));

        return nums.size();
    }

    /**
     * @brief Solving the problems of searchInsert
     *
     * @param nums
     * @param target
     * @return int
     */
    int easyLevel::searchInsert(vector<int> &nums, int target)
    {
        if (target <= nums[0])
            return 0;
        int len = nums.size();
        if (target > nums[len - 1])
            return len;
        if (target == nums[len - 1])
        {
            return len - 1;
        }
        return findPos(nums, target);
    }

    int easyLevel::findPos(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size();
        int middle = (start + end) / 2;
        while (!(nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target) || (nums[middle] < target && target < nums[middle + 1])))
        {
            middle = (start + end) / 2;

            if (nums[middle] < target)
                start = middle;
            if (nums[middle] > target)
                end = middle;
        }

        if (nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target))
            return middle;
        if (nums[middle] < target && target < nums[middle + 1])
            return middle + 1;

        return middle;
    }

    /**
     * @brief Solving the problems of singleNumber
     *
     */
    int easyLevel::singleNumber(vector<int> &nums)
    {
        int res = {0};
        for (int i : nums)
        {
            res ^= i;
        }
        return res;
    }

    /**
     * @brief Solving the problems of deleteDuplicates
     *
     */
    ListNode *easyLevel::deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *currList = head;
        ListNode *nextList = nullptr;

        if (head->next != nullptr)
            nextList = head->next;

        while (nextList != nullptr)
        {
            if (currList->val != nextList->val)
            {
                currList = nextList;
                nextList = nextList->next;
            }
            else
            {
                currList->next = nextList->next;
                ListNode *temp = nextList;
                nextList = currList->next;

                delete temp;
                temp = nullptr;
            }
        }

        currList = nullptr;
        nextList = nullptr;

        return head;
    }

    /**
     * @brief Solving the problems of merge
     *
     */
    void easyLevel::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Don't you this way -> because you don't know the algorithm - even though this solution is very fast
        std::merge(nums2.rbegin() + (nums2.size() - n),
                   nums2.rend(),
                   nums1.rbegin() + (nums1.size() - m),
                   nums1.rend(), nums1.rbegin(),
                   [](const int l, const int r)
                   { return l >= r; });
    }

    int easyLevel::titleToNumber(string columnTitle)
    {
        int _size = columnTitle.length();
        int _res = 0;
        for (int i = 0; i < _size; i++)
        {
            if (i != 0)
            {

                _res = (_res * 26) + ((int)columnTitle[i] - 64);
            }
            else
            {
                _res += (int)columnTitle[i] - 64;
            }
        }
        return _res;
    }

    /**
     * @brief
     */
    bool easyLevel::isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    /**
     * @brief Supported function
     *
     */
    bool compareNode(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left != nullptr && right != nullptr)
        {
            if (left->val == right->val)
            {
                return compareNode(left->right, right->left) && compareNode(left->left, right->right);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool easyLevel::isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return compareNode(root->left, root->right);
        }
    }

    int easyLevel::maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }

    /**
     * @brief
     *
     * @param root
     * @return true
     * @return false
     */
    bool easyLevel::isBalanced(TreeNode *root)
    {
        return dfsHeight(root) == -1 ? false : true;
    }

    int easyLevel::dfsHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftH = dfsHeight(node->left);
        if (leftH == -1)
            return -1;

        int rightH = dfsHeight(node->right);
        if (rightH == -1)
            return -1;

        if (abs(leftH - rightH) > 1)
            return -1;

        return max(leftH, rightH) + 1;
    }

    /**
     * @brief
     *
     * @param words
     * @return int
     */
    int easyLevel::uniqueMorseRepresentations(vector<string> &words)
    {
        std::vector<std::string> MorseTable = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                                               "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                                               "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                               "-.--", "--.."};

        std::unordered_map<std::string, int> _listWords;

        for (int i = 0; i < words.size(); i++)
        {
            std::string _morseWord = "";
            for (int j = 0; j < words[i].size(); j++)
                _morseWord += MorseTable[words[i][j] - 'a'];
            _listWords[_morseWord] = 1;
        }
        return _listWords.size();
    }

    /**
     * @brief
     *
     */
    string easyLevel::reverseWords(string s)
    {
        stringstream ss(s);
        string t, ans;

        while (getline(ss, t, ' '))
        {
            reverse(t.begin(), t.end());
            ans += t + ' ';
        }
        // We will take substring of one less size as there will be space after last
        // word which is not required.
        return ans.substr(0, ans.size() - 1);
    }


    bool checkTarget(TreeNode *root, int target, int &result)
    {
        if (root == nullptr)
        {
            return false;
        }
        result += root->val;
        std::cout << "Cur node: " << root->val << " - result: " << result << std::endl;
        if (result == target && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }

        std::cout << "Calling left! -> ";
        if (checkTarget(root->left, target, result))
        {
            return true;
        }
        else
        {
            result -= root->left ? root->left->val : 0;
        }
        std::cout << std::endl;
        std::cout << "Calling right! -> ";
        if (checkTarget(root->right, target, result))
        {
            return true;
        }
        else
        {
            result -= root->right ? root->right->val : 0;
        }
        std::cout << std::endl;
        return false;
    }

    /**
     * @brief
     *
     */
    bool easyLevel::hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        int result = 0;
        if (checkTarget(root, targetSum, result))
        {
            return true;
        }

        return false;
    }

    /**
     * @brief
     *
     */
    int easyLevel::minDepth(TreeNode *root)
    {
        int l = 100000, r = 100000;
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
        {
            if (root->left != NULL)
                l = minDepth(root->left);
            if (root->right != NULL)
                r = minDepth(root->right);
        }
        return l < r ? l + 1 : r + 1;
    }

    string easyLevel::addStrings(string num1, string num2)
    {
        if (num1 == "0")
        {
            return num2;
        }
        if (num2 == "0")
        {
            return num1;
        }

        vector<int> ans(num1.size() + num2.size(), 0);
        int num1Run = num1.size() - 1;
        int num2Run = num2.size() - 1;
        while (num1Run >= 0 && num2Run >= 0) {
            int total = (num1[num1Run] - '0') + (num2[num2Run] - '0');
            if (total > 10) {
                ans[num1Run + num2Run + 1] = total % 10;
                ans[num1Run + num2Run] = total / 10;
            }
        }
    }

    bool easyLevel::hasCycle(ListNode *head)
    {
        // This way need n nodes of spaces
        if ((head == nullptr) || (head != nullptr && head->next == nullptr))
        {
            return false;
        }
        map<ListNode*, bool> isTravellingTable;
        ListNode* temp = head;
        do
        {
            if (isTravellingTable[temp] == true)
            {
                return true;
            }

            isTravellingTable[temp] = true;

            temp = temp->next;
        } while (temp != nullptr);
        return false;


        /**
         * @brief Fast and slow methods
         * 
         */

        // // if head is NULL then return false;
        // if(head == NULL)
        //     return false;
        
		// // making two pointers fast and slow and assignning them to head
        // ListNode *fast = head;
        // ListNode *slow = head;
        
		// // till fast and fast-> next not reaches NULL
		// // we will increment fast by 2 step and slow by 1 step
        // while(fast != NULL && fast ->next != NULL)
        // {
        //     fast = fast->next->next;
        //     slow = slow->next;
            
			
		// 	// At the point if fast and slow are at same address
		// 	// this means linked list has a cycle in it.
        //     if(fast == slow)
        //         return true;
        // }
        
		// // if traversal reaches to NULL this means no cycle.
        // return false;
    }


    ListNode *easyLevel::getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        map<ListNode*, bool> mem_mapping;

        ListNode* temp = headA;
        while (temp != nullptr)
        {
            mem_mapping[temp] = true;
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr)
        {
            if (mem_mapping.find(temp) != mem_mapping.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }



    string reverse(string s){
        int l=0 ;
        int h=s.length()-1 ;
        while(l<h){
            swap(s[l],s[h]) ;
            l++ ;
            h-- ;
        }
        return s ;
    }

    string easyLevel::convertToTitle(int columnNumber)
    {
        string  s="" ;
        while(columnNumber>0)
        {
            char letter=(columnNumber-1) % 26+'A' ;
            s.push_back(letter);
            columnNumber=(columnNumber-1)/26 ;
        }        
        return reverse(s);
    }

    vector<int> easyLevel::nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            auto _found = std::find(nums2.begin(), nums2.end(), nums1[i]);
            if ( _found == nums2.end() ) {
                result.push_back(-1);
            } else {
                int _val = -1;
                for (; _found != nums2.end(); _found++) {
                    if ( (*_found) > nums1[i] ) {
                        _val = (*_found);
                        break;
                    }
                }
                result.push_back(_val);
            }
        }
        return result;
    }

    vector<vector<int>> easyLevel::largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = max(temp, grid[k][l]);
                    }
                }

                res[i - 1][j - 1] = temp;
            }
        }
    }
};  
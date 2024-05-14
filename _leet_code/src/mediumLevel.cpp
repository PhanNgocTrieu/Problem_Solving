#include "mediumLevel.h"

namespace leetcode
{

    /**
     * **********************************************************************************
     *                       @brief Problems of Medium Levels                           *
     * **********************************************************************************
     */

    /**
     * @brief Solving the problems of isValid
     *
     */
    bool mediumLevel::isValid(string s)
    {
        if (s.length() == 1)
            return false;
        if (s[0] == '}' || s[0] == ']' || s[0] == ')')
            return false;

        stack<char> check;
        map<char, char> brackets{
            {')', '('},
            {'}', '{'},
            {']', '['}};

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                check.push(c);
            else
            {
                if (check.empty())
                    return false;
                if (check.top() == brackets[c])
                    check.pop();
                else
                    return false;
            }
        }
        return check.size() == 0 ? true : false;
    }

    /**
     * @brief Solving the problems of combinationSum
     */
    vector<vector<int>> mediumLevel::combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        int _numberOfCadidates = candidates.size();
        for (int i = 0; i < _numberOfCadidates; i++)
        {
            vector<Combination> stack;
            struct Combination com;

            // check single value
            if (candidates[i] == target)
            {
                vector<int> okay;
                okay.push_back(candidates[i]);
                res.push_back(okay);
                continue;
            }

            // push i vao stack
            com.arr.push_back(candidates[i]);
            com.sum += candidates[i];
            com.idx = i;
            stack.push_back(com);

            // duyet stack
            while (stack.size() != 0)
            {
                // lay ra phan tu cuoi cung
                struct Combination temp;
                temp = stack[stack.size() - 1];
                stack.pop_back();
                int _numOfCandidate = candidates.size();
                for (int j = temp.idx; j < _numOfCandidate; j++)
                {
                    struct Combination temp2;
                    temp2 = temp;
                    if (temp.sum + candidates[j] <= target)
                    {
                        temp2.arr.push_back(candidates[j]);
                        temp2.sum += candidates[j];
                        temp2.idx = j;
                        stack.push_back(temp2);
                        if (temp.sum + candidates[j] == target)
                        {
                            res.push_back(temp2.arr);
                            stack.pop_back();
                        }
                    }
                }
            }
        }
        return res;
    }

    /**
     * @brief Solving the problems of intToRoman
     */
    string mediumLevel::intToRoman(int num)
    {
        map<int, string> romanList{
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};
        string res = "";
        int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        while (num > 0)
        {
            if (num < arr[i])
            {
                i++;
                continue;
            }
            else
            {
                int temp = num / arr[i];
                // adding numbers of words
                for (int j = 0; j < temp; j++)
                {
                    res += romanList[arr[i]];
                }
                num = num % arr[i];
                i++;
            }
        }

        return res;
    }

    /**
     * @brief Solving the problems of myAtoi
     */
    int mediumLevel::myAtoi(string s)
    {
        const int n = s.length();
        // 1.passing leading space
        int start = 0;
        while (start < n && s[start] == ' ')
        {
            start++;
        }
        if (start == n)
            return 0;
        // 2. sign
        bool positive = true;
        if (s[start] == '-' || s[start] == '+')
        {
            positive = s[start] == '+';
            start++;
        }
        // 3. convert string to number
        if (!isdigit(s[start]))
            return 0;
        int ans = 0;
        int max_unit = INT_MAX % 10;
        int min_unit = INT_MIN % 10;
        while (start < n && isdigit(s[start]))
        {
            int unit = (s[start++] - '0');
            if (!positive)
            {
                unit = -unit;
            }
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && unit > max_unit))
                return INT_MAX;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && unit < min_unit))
                return INT_MIN;
            ans = ans * 10 + unit;
        }

        return ans;

        /*  //  Second way
        {
            int i = 0;
            while(s[i] == ' ') ++i;
            int sig = 1;
            if(s[i] == '-')
            {
                sig = -1;
                ++i;
            }
            else if(s[i] == '+')
            {
                ++i;
            }
            if(s[i] < '0' || s[i] > '9') return 0;
            ll ans = 0;
            while(s[i] >= '0' && s[i] <= '9' && i < s.size())
            {
                ans *= 10;
                ans += (s[i++] - '0');
                if(ans*sig >= INT_MAX) return INT_MAX;
                if(ans*sig <= INT_MIN) return INT_MIN;
            }
            return (int) ans*sig;
        }
        */
    }

    /**
     * @brief Solving the problems of longestPalindrome
     *
     */
    string mediumLevel::longestPalindrome(string s)
    {
        string ans = "";
        int len = 0, maxLen = 0, idx = 0;
        int _sizeOfString = s.size();
        for (int i = 0; i < _sizeOfString; ++i)
        {
            int left = i - 1, right = i + 1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);

            left = i;
            right = i + 1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);
        }

        if (maxLen)
            ans = s.substr(idx, maxLen);
        return ans;
    }

    /**
     * @brief Supporting function -> finding out the pallindrome string
     *
     */
    int mediumLevel::pallindromeLength(int &l, int &r, string &s)
    {
        int _sizeOfStr = s.size();
        while (l >= 0 && r < _sizeOfStr && s[l] == s[r])
        {
            l--;
            r++;
        }
        l++;
        r--;
        return (r - l + 1);
    }

    int mediumLevel::lengthOfLongestSubstring(string s)
    {
        int n = s.size(), result = 0;
        // creating hashmap for storing unique character and their index
        map<char, int> sm;
        int start = 0, end = 0;
        for (end = 0; end < n; end++)
        {

            if (sm.find(s[end]) != sm.end()) // if element is present in map then we have to find the previous substring size
            {
                // Update the result for the substring in the current window before we found duplicate character
                result = max(result, end - start);
                int duplicateIndex = sm[s[end]];
                //  Remove all characters before the new
                for (int i = start; i <= duplicateIndex; i++)
                {
                    sm.erase(s[i]);
                }
                // Slide the window since we have found a duplicate character
                start = duplicateIndex + 1;
            }
            // Add the current character to hashmap
            sm[s[end]] = end;
        }

        return max(result, n - start);
    }

    int mediumLevel::findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int _max = INT_MIN;
        int _sum = 0;
        int _idex = 0;
        for (auto elems : nums)
        {
            _sum += elems == 0 ? -1 : 1;

            if (_sum == 0)
            {
                _max = _idex + 1;
            }
            else
            {
                if (map.find(_sum) == map.end())
                {
                    map[_sum] = _idex;
                }
                else
                {
                    _max = max(_max, _idex - map[_sum]);
                }
            }

            _idex++;
        }

        return _max == INT_MIN ? 0 : _max;
    }

    /**
     * @brief
     *
     * @param nums
     * @return vector<vector<int>>
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        const size_t len = nums.size();
        if (len < 3)
            return {};

        std::sort(nums.begin(), nums.end());

        std::set<vector<int>> unique_results;

        for (size_t i = 0; i < len - 2; i++)
        {

            int j = i + 1;
            int k = len - 1;

            while (j < k)
            {
                const int sum = nums[i] + nums[j] + nums[k];
                if (0 == sum)
                {
                    unique_results.insert({nums[i], nums[j++], nums[k--]});
                }
                else if (0 > sum)
                    j++;
                else if (0 < sum)
                    k--;
            }
        }

        vector<vector<int>> results;

        std::copy(
            unique_results.begin(), unique_results.end(),
            std::back_inserter(results));

        return results;
    }

    /**
     * @brief
     *
     * @param nums
     * @param target
     * @return vector<vector<int>>
     */
    vector<vector<int>> mediumLevel::fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                for (size_t k = j + 1; k < nums.size(); k++)
                {
                    int x = (long long)target - (long long)nums[j] - (long long)nums[k] - (long long)nums[i];
                    if (binary_search(nums.begin() + k + 1, nums.end(), x))
                    {
                        vector<int> ans{nums[i], nums[j], nums[k], x};

                        int track = 0;
                        for (size_t m = 0; m < solution.size(); m++)
                        {

                            for (size_t n = 0; n < ans.size(); n++)
                            {
                                if (solution[m][n] == ans[n])
                                {
                                    track++;
                                }
                            }
                            if ((size_t)track == ans.size())
                            {
                                break;
                            }
                            track = 0;
                        }

                        if ((size_t)track != ans.size())
                        {
                            solution.push_back(ans);
                        }
                    }
                }
            }
        }
        return solution;
    }

    // 3 ^ 5 => 3 ^ 2 -> 3 ^ 1 => 3 ^ 0
    // 9 * 9 * 3
    /**
     * @brief
     */
    double mediumLevel::myPow(double x, int n)
    {
        if (n == -1)
            return 1 / x;
        if (n == 0)
            return 1;

        double tmp = myPow(x, n / 2);

        if (n % 2 == 0)
        {
            return tmp * tmp;
        }

        if (n < 0)
            return tmp * tmp * (1 / x);

        return tmp * tmp * x;
    }

    /**
     * @brief
     */
    int mediumLevel::maxArea(const vector<int> &height)
    {
        int water = 0;
        int left = 0, right = height.size() - 1;
        int minHeight = INT_MIN;

        while (left < right)
        {

            while (height[left] <= minHeight && left < right)
                left++;
            while (height[right] <= minHeight && left < right)
                right--;

            minHeight = min(height[left], height[right]);
            water = max(water, (right - left) * minHeight);
        }
        return water;
    }

    /**
     * @brief
     */
    ListNode *mediumLevel::removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        int _count = 0;
        ListNode *runNode = head;
        ListNode *result = nullptr;
        std::vector<int> _valueOfNode;

        while (runNode != nullptr)
        {
            _count++;
            _valueOfNode.push_back(runNode->val);
            runNode = runNode->next;
        }
        runNode = nullptr;
        for (auto val : _valueOfNode)
        {
            _count--;
            std::cout << "_Count: " << _count << std::endl;
            do
            {
                if (_count == n - 1)
                {
                    std::cout << "Break!" << std::endl;
                    break;
                }

                if (result == nullptr)
                {
                    result = new ListNode(val);
                    runNode = result;
                }
                else
                {
                    runNode->next = new ListNode(val);
                    runNode = runNode->next;
                }
            } while (0);
        }

        // for (auto run = result; run != nullptr; run = run->next) {
        //     std::cout << "Val: " << run->val << " ";
        // }

        return result;
    }

    /**
     * @brief
     *
     */
    int mediumLevel::threeSumClosest(std::vector<int> &nums, int target)
    {
        int rest = INT_MAX, r_start = nums.size() - 1, lim = nums.size() - 2, answer;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < lim; i++)
        {
            int l = i + 1, r = r_start;

            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                int dif = abs(target - s);

                if (dif < rest)
                {
                    if (dif)
                    {
                        rest = dif, answer = s;
                    }
                    else
                    {
                        return s;
                    }
                }

                if (s < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        return answer;
    }

    /**
     * @brief Solving the problems of swapping pairs of nodes in list
     *
     */
    ListNode *mediumLevel::swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *root = head;

        do
        {

            if (root->next == nullptr)
            {
                break;
            }

            if (root != nullptr)
            {
                ListNode *temp = root->next;
                int tempVal = root->val;
                root->val = temp->val;
                temp->val = tempVal;

                if (temp->next != nullptr)
                {
                    root = temp->next;
                }
                else
                {
                    break;
                }
            }
        } while (true);
        return head;
    }

    int mediumLevel::concatenatedBinary(int n)
    {
        return 0;
    }

    string mediumLevel::pushDominoes(string dominoes)
    {
        int N = dominoes.size(), right = -1;
        for (int i = 0; i < N; ++i)
        {
            if (dominoes[i] == 'L')
            {
                if (right == -1)
                {
                    // Step 2
                    for (int j = i - 1; j >= 0 && dominoes[j] == '.'; --j)
                    {
                        dominoes[j] = 'L';
                    }
                }
                else
                {
                    // Step 8
                    for (int j = right + 1, k = i - 1; j < k; ++j, --k)
                    {
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                    }
                    right = -1;
                }
            }
            else if (dominoes[i] == 'R')
            {
                if (right != -1)
                {
                    for (int j = right + 1; j < i; ++j)
                        dominoes[j] = 'R';
                }
                right = i;
            }
        }
        if (right != -1)
        {
            for (int j = right + 1; j < N; ++j)
                dominoes[j] = 'R';
        }
        return dominoes;
    }

    void mediumLevel::flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }

    int mediumLevel::searchRotatedSortedArray(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int midElem = nums[mid];

            if (midElem == target)
            {
                return mid;
            }

            int leftElem = nums[l];
            int rightElem = nums[r];

            if (leftElem == target)
            { // Similar to check above
                return l;
            }
            else if (rightElem == target)
            {
                return r;
            }

            if (midElem < rightElem)
            { // Soft inquiry to the right portion of mid
                if (midElem < target && target <= rightElem)
                { // Intial inquiry was correct! & this portion is not rotated
                    l = mid + 1;
                }
                else
                { // Upon further examination, we'll look into the left portion of mid instead
                    r = mid - 1;
                }
            }
            else
            { // Soft inquiry to the left portion of mid
                if (midElem > target && target >= leftElem)
                { // Inquiry was correct! We'll further investigate the left portion of mid & this portion is not rotated
                    r = mid - 1;
                }
                else
                { // Initial inquiry was incorrect, instead we will investigate the right portion of mid
                    l = mid + 1;
                }
            }
        }
        return -1;
    }

    vector<int> mediumLevel::searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        int firstfind = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == target)
            {
                if (firstfind == 0)
                {
                    firstfind = 1;
                    ans[0] = i;
                    ans[1] = i;
                }
                else
                {
                    ans[1] = i;
                }
            }
        }
        return ans;
    }

    string mediumLevel::multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        vector<int> res(num1.size() + num2.size(), 0);

        for (int idex = num1.size() - 1; idex >= 0; --idex)
        {
            for (int jdex = num2.size() - 1; jdex >= 0; --jdex)
            {
                // Multiple 2 number from right to left as multiple calculating
                res[idex + jdex + 1] += (num1[idex] - '0') * (num2[jdex] - '0');

                // Storing the first number
                res[idex + jdex] += res[idex + jdex + 1] / 10;

                // Taking the second number
                res[idex + jdex + 1] = res[idex + jdex + 1] % 10;
            }
        }

        int idex = 0;
        string ans = "";

        // Removing 0 number on array
        while (res[idex] == 0)
        {
            idex++;
        }

        // Concatenating strng
        while (idex < res.size())
        {
            ans += to_string(res[idex++]);
        }

        return ans;
    }

    bool mediumLevel::increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;

        for (const int num : nums)
        {
            if (num <= first)
                first = num;
            else if (num <= second) // First < num <= second
                second = num;
            else
                return true; // First < second < num (third)
        }

        return false;
    }

    /**
     * @brief
     *
     * Input: board =
     *          [["5","3",".",".","7",".",".",".","."]
     *          ,["6",".",".","1","9","5",".",".","."]
     *          ,[".","9","8",".",".",".",".","6","."]
     *          ,["8",".",".",".","6",".",".",".","3"]
     *          ,["4",".",".","8",".","3",".",".","1"]
     *          ,["7",".",".",".","2",".",".",".","6"]
     *          ,[".","6",".",".",".",".","2","8","."]
     *          ,[".",".",".","4","1","9",".",".","5"]
     *          ,[".",".",".",".","8",".",".","7","9"]]
     *
     *
     * Output: true
     *
     */
    bool mediumLevel::isValidSudoku(vector<vector<char>> &board)
    {
        map<char, bool> map_sudoku;

        // Checking every rows
        for (int iRow = 0; iRow < 9; iRow++)
        {
            map_sudoku = {
                {'1', false},
                {'2', false},
                {'3', false},
                {'4', false},
                {'5', false},
                {'6', false},
                {'7', false},
                {'8', false},
                {'9', false},
            };
            for (int iCol = 0; iCol < 9; iCol++)
            {
                if (map_sudoku[board[iRow][iCol]] == true)
                {
                    return false;
                }
                // Making already when passing
                if (board[iRow][iCol] != '.')
                    map_sudoku[board[iRow][iCol]] = true;
            }
        }

        // Checking every colums
        for (int idex = 0; idex < 9; ++idex)
        {
            map_sudoku = {
                {'1', false},
                {'2', false},
                {'3', false},
                {'4', false},
                {'5', false},
                {'6', false},
                {'7', false},
                {'8', false},
                {'9', false},
            };

            for (int jdex = 0; jdex < 9; ++jdex)
            {
                if (map_sudoku[board[jdex][idex]] == true)
                {
                    return false;
                }

                if (board[jdex][idex] != '.')
                    map_sudoku[board[jdex][idex]] = true;
            }
        }

        // Travelling a matrix of 3x3
        int step = 0;
        int size = 3;
        do
        {

            do
            {
                // Checking the first matrix
                map_sudoku = {
                    {'1', false},
                    {'2', false},
                    {'3', false},
                    {'4', false},
                    {'5', false},
                    {'6', false},
                    {'7', false},
                    {'8', false},
                    {'9', false},
                };

                for (int iRow = step; iRow < size; ++iRow)
                {
                    for (int iCol = 0; iCol < 3; ++iCol)
                    {
                        if (map_sudoku[board[iRow][iCol]] == true)
                        {
                            return false;
                        }
                        if (board[iRow][iCol] != '.')
                            map_sudoku[board[iRow][iCol]] = true;
                    }
                }
            } while (0);

            do
            {
                // Checking the second matrix
                map_sudoku = {
                    {'1', false},
                    {'2', false},
                    {'3', false},
                    {'4', false},
                    {'5', false},
                    {'6', false},
                    {'7', false},
                    {'8', false},
                    {'9', false},
                };

                for (int iRow = step; iRow < size; ++iRow)
                {
                    for (int iCol = 3; iCol < 6; ++iCol)
                    {
                        if (map_sudoku[board[iRow][iCol]] == true)
                        {
                            return false;
                        }
                        if (board[iRow][iCol] != '.')
                            map_sudoku[board[iRow][iCol]] = true;
                    }
                }
            } while (0);

            do
            {
                // Checking the third matrix
                map_sudoku = {
                    {'1', false},
                    {'2', false},
                    {'3', false},
                    {'4', false},
                    {'5', false},
                    {'6', false},
                    {'7', false},
                    {'8', false},
                    {'9', false},
                };

                for (int iRow = step; iRow < size; ++iRow)
                {
                    for (int iCol = 6; iCol < 9; ++iCol)
                    {
                        if (map_sudoku[board[iRow][iCol]] == true)
                        {
                            return false;
                        }
                        if (board[iRow][iCol] != '.')
                            map_sudoku[board[iRow][iCol]] = true;
                    }
                }
            } while (0);

            step += 3;
            size += 3;
        } while (size <= 9);

        return true;
    }

    ListNode *mediumLevel::detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                fast = head;
                // Findind the node that the tail point to from the head
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }

#if 0
    bool checking_word(const string& ref, const string& word)
    {
        if (ref.length() != word.length()) {
            return false;
        }
        sort(ref.begin(),ref.end());
        sort(word.begin(),word.end());
        char * letter_find = &((char)ref[0]);
        char * letter_dest = &((char)word[0]);
        do {
            if (*letter_dest != *letter_find) {
                return false;
            }
            if (letter_dest == nullptr) {
                break;
            }
            letter_dest++;
            letter_find++;
        } while (1);
        return true;
    }
#endif
    vector<vector<string>> mediumLevel::groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;

        if (strs.empty())
        {
            return result;
        }

        for (auto &word : strs)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;

        return result;
    }

    std::string transform(std::string s)
    {
        // First character
        char curr = s[0];
        // frequency
        int curr_freq = 1;

        // Result
        string ans = "";

        for (int i = 1; i < s.length(); ++i)
        {
            // Checking sequence of character
            if (s[i] == curr)
            {
                curr_freq++;
            }
            else
            {
                // Concatenating string with number of digit
                ans += (char)(curr_freq + '0');
                // Concatenating string with digit
                ans += (char)(curr);

                // Set the new digit and reset frequency
                curr = s[i];
                curr_freq = 1;
            }
        }

        /*
            Adding the number of digit and digital number while exit loop
            Because when catching the condition they did not add it yet.
        */

        // Concatenating string with number of digit
        ans += (char)(curr_freq + '0');
        // Concatenating string with digit
        ans += (char)(curr);
        return ans;
    }

    std::string mediumLevel::countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        return transform(countAndSay(n - 1));
    }

    bool checkingPath(TreeNode *root, int targetSum, std::vector<int> &vector)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->val > targetSum)
        {
            return false;
        }
        else if (root->val == targetSum)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return true;
            }
        }

        vector.push_back(root->val);
        bool res;
        res = checkingPath(root->left, targetSum - root->val, vector);
        res = checkingPath(root->right, targetSum - root->val, vector);

        return res;
    }

    vector<vector<int>> mediumLevel::pathSum(TreeNode *root, int targetSum)
    {
        return vector<vector<int>>();
    }

    /**
     *  [1,2,3]
     *      [{}]
     *      [{},{1}]
     *      [{},{1},{1,2},{2}]
     *      [{},{1},{1,2},{2}] + {3}
     *      [{},{1},{1,2},{2},{1,3},{1,2,3},{2,3},{3}]
     */
    vector<vector<int>> mediumLevel::subsets(vector<int> &nums)
    {
        // creating the vector of result which contains the empty vector<int> firstly
        vector<vector<int>> result{vector<int>{}};
        // In constrains: nums.length > 0
        result.push_back(vector<int>{nums[0]});
        int size = nums.size();
        for (int i = 1; i < size; ++i)
        {
            int getVal = nums[i];
            int size_of_result = result.size();
            for (int j = 1; j < size_of_result; ++j)
            {
                vector<int> temp = result[j];
                temp.push_back(getVal);
                result.push_back(temp);
            }
            result.push_back(vector<int>{nums[i]});
        }
        return result;
    }

    vector<vector<int>> mediumLevel::subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result{vector<int>{}};
        result.push_back(vector<int>{nums[0]});

        int size = nums.size();
        for (int i = 1; i < size; ++i)
        {
            int getVal = nums[i];
            int size_of_result = result.size();
            for (int j = 1; j < size_of_result; ++j)
            {
                vector<int> temp = result[j];
                temp.push_back(getVal);
                if (!isFoundOnVec2D(result, temp))
                {
                    result.push_back(temp);
                }
            }
            vector<int> temp{nums[i]};
            if (!isFoundOnVec2D(result, temp))
            {
                result.push_back(temp);
            }
        }
        return result;
    }

    unordered_map<char, int> templateMapping(string container)
    {
        unordered_map<char, int> map;
        for (auto elem : container)
        {
            map[elem]++;
        }
        return map;
    }

    bool isContain(string word, string subword)
    {
        auto word_mapping = templateMapping(word);
        auto subword_mapping = templateMapping(subword);
        for (auto itr = subword_mapping.begin(); itr != subword_mapping.end(); itr++)
        {
            if (word_mapping[itr->first] < itr->second)
            {
                return false;
            }
        }
        return true;
    }

    unordered_map<char, int> mapping(const string input)
    {
        unordered_map<char, int> map;
        for (auto c : input)
        {
            map[c]++;
        }
        return map;
    }

    /**
     *  input:
     *      word1: ["amazon","apple","facebook","google","leetcode"]
     *      word2: ["el", "eo"]
     *
     *          map[amazon] :
     *              -> map[el] -> false
     *                  break;
     *          map[apple]:
     *              -> map["el"] -> true
     *              -> map["el"] -> false
     *                  break;
     *          map[]
     *
     *
     */
    vector<string> mediumLevel::wordSubsets(const vector<string> &words1, const vector<string> &words2)
    {
        vector<string> res;
        vector<int> hash1(26, 0);

        for (int i = 0; i < words2.size(); i++)
        {
            vector<int> temp(26, 0);
            for (int j = 0; j < words2[i].length(); j++)
            {
                temp[words2[i][j] - 97]++;
            }

            for (int j = 0; j < 26; j++)
            {
                hash1[j] = max(hash1[j], temp[j]);
            }
        }

        for (int i = 0; i < words1.size(); i++)
        {
            vector<int> hash2(26, 0);
            string temp = words1[i];
            for (int j = 0; j < temp.length(); j++)
            {
                hash2[temp[j] - 97]++;
            }
            if (isSame(hash1, hash2))
                res.push_back(temp);
        }
        return res;
    }

    // Fixme for completed this one
    // Badcase:
    //      @Input: "/.///NWtm/KBp/TQdj/a/v/rsJ/n/j/../../lsw/./j/../Gh/////gNBxM/./"
    //      @Output: "/NWtm/KBp/TQdj/a/v/rsJ/lsw/Gh/gNBxM"
    std::string mediumLevel::simplifyPath(std::string path)
    {
        string res = "/";
        vector<string> splitString = split(path, '/');
        for (auto idex = 0; idex < splitString.size(); ++idex)
        {
            do
            {
                if (splitString[idex] == ".")
                {
                    break;
                }

                if (splitString[idex] == "..")
                {
                    if (res.length() <= 1)
                    {
                        break;
                    }
                    remove(res);
                    break;
                }

                if (res[res.length() - 1] != '/')
                {
                    res += "/";
                }
                res += splitString[idex];
                res += "/";
            } while (0);
        }

        if (res.length() > 1)
        {
            res.erase(res.end() - 1);
        }

        return res;
    }

    void mediumLevel::sortColors(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, i = 0;
        while (i <= high)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[low]);
                ++low;
                ++i;
            }
            else if (nums[i] == 2)
            {
                std::swap(nums[i], nums[high]);
                --high;
            }
            else
            {
                ++i;
            }
        }
    }

    long long mediumLevel::wonderfulSubstrings(string word)
    {
    }

    ListNode *mediumLevel::removeNodes(ListNode *head)
    {
    }

    vector<int> mediumLevel::nextLargerNodes(ListNode *head)
    {
        auto _pair = reverse(head);
        int _len = _pair.second;
        auto _reverse = _pair.first;

        /* Initialize res - array with 0 values */
        vector<int> result(_len, 0);
        stack<int> stack;
        while (_reverse != nullptr)
        {
            while (
                stack.size() &&
                stack.top() <= _reverse->val)
            {
                /* pop out every value less than current value to get the greater one */
                stack.pop();
            }
            /* decreasing index to get the index references to the current list */
            _len--;
            /* if stack is exist, then we have the greater value than current value */
            if (stack.size())
            {
                /* so we assign the greater value to the positon of current value */
                result[_len] = stack.top();
            }

            stack.push(_reverse->val);
            _reverse = _reverse->next;
        }
        return result;

#if 0
        vector<int> result;
        ListNode* ref_head = head;
        while (ref_head != nullptr) {
            if (head != nullptr && head->next == nullptr) {
                result.push_back(0);
            }

            bool _f_flags = false;
            while (head != nullptr) {
                if (ref_head->val < head->val) {
                    result.push_back(head->val);
                    _f_flags = true;
                    break;
                }
                head = head->next;
            }

            if (!_f_flags) {
                result.push_back(0);
            }

            ref_head = ref_head->next;
            head = ref_head;
        }
        return result;
#endif
    }

    int mediumLevel::getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    int sum = 0;
                    travel_around(grid, r, c, sum);
                }
#if 0
                if (grid[r][c]) {
                    back_tracking(grid, r, c, 0);
                }
#endif
            }
        }
        return m_res;
    }
}

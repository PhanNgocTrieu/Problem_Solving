#ifndef COMMON_LEETCODE_H
#define COMMON_LEETCODE_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <sstream>
#include <queue>
#include "data.h"

namespace leetcode
{
    typedef enum
    {
        EASY = 0,
        MEDI,
        HARD
    } levels;


    /**
     * @brief Function support for easy-"hasPathSum" problem!
     *
     */
    bool checkTarget(TreeNode *root, int target, int &result);

    class ProblemSolving 
    {
        public:
            virtual ~ProblemSolving() {}
        protected:
            int m_dx[4] = {1, -1, 0, 0};
            int m_dy[4] = {0, 0, 1, -1};
            vector<int> roww = {0, 0, -1, 1};
            vector<int> coll = {-1, 1, 0, 0};
    };
}

using namespace std;

#endif // COMMON_LEETCODE_H
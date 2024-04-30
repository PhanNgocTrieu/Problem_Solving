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
}

using namespace std;

#endif // COMMON_LEETCODE_H
#ifndef COMMON_H__
#define COMMON_H__

#include <bits/stdc++.h>
#include <vector>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif // COMMON_H__
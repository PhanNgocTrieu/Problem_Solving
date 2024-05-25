#include "common.h"
/**
 * @brief There exists an undirected tree with n nodes numbered 0 to n - 1.
 *  You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree.
 *  You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.
 *
 *  Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:
 *      Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
 *          nums[u] = nums[u] XOR k
 *          nums[v] = nums[v] XOR k
 *      Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.
 *
 * @param nums
 * @param k
 * @param edges
 * @return long long
 */
long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
{
    long long totalSum = 0;
    int count = 0;
    int positiveMin = INT_MAX;
    int negativeMax = INT_MIN;

    for (int nodeValue : nums)
    {
        int nodeValAfterOperation = nodeValue ^ k;
        totalSum += nodeValue;
        int netChange = nodeValAfterOperation - nodeValue;

        if (netChange > 0)
        {
            positiveMin = min(positiveMin, netChange);
            totalSum += netChange;
            count += 1;
        }
        else
        {
            negativeMax = max(negativeMax, netChange);
        }
    }

    if (count % 2 == 0)
    {
        return totalSum;
    }
    return max(totalSum - positiveMin, totalSum + negativeMax);

#if 0 
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        function<pair<long long, long long>(int, int)> dfs = [&](int node, int parent) {
            long long orig_sum = nums[node];
            long long xor_sum = nums[node] ^ k;
            
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    auto [child_orig, child_xor] = dfs(neighbor, node);
                    orig_sum += max(child_orig, child_xor);
                    xor_sum += max(child_orig ^ k, child_xor ^ k);
                }
            }
            
            return make_pair(orig_sum, xor_sum);
        };
        
        auto [total_orig, total_xor] = dfs(0, -1);
        return max(total_orig, total_xor);
#endif
}
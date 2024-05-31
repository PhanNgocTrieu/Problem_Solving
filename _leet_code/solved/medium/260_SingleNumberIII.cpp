/*
    Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
    Find the two elements that appear only once. 
    You can return the answer in any order.
    You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

    Input: nums = [1,2,1,3,2,5]
    Output: [3,5]
    Explanation:  [5, 3] is also a valid answer.

    Input: nums = [-1,0]
    Output: [-1,0]  
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int getBit(int x, int k) {
        return (x >> k) & 1;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int xorXY = 0;
        for (int num : nums)
            xorXY ^= num;

        int pos = 0;
        while (!getBit(xorXY, pos)) pos++;

        int x = 0;
        for (int num : nums)
            if (getBit(num, pos))
                x ^= num;

        int y = xorXY ^ x;
        return {x, y};
    }
};

int main() {
    Solution s;
    vector<int> ip = { 1, 2, 3, 4, 2, 1 };
    for (auto elem : s.singleNumber(ip)) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
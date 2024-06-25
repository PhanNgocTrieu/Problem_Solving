/*
    3194. Minimum Average of Smallest and Largest Elements - Easy

    You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
    You repeat the following procedure n / 2 times:
        Remove the smallest element, minElement, and the largest element maxElement, from nums.
        Add (minElement + maxElement) / 2 to averages.
    Return the minimum element in averages.

    Example:
        Input: nums = [7,8,3,4,15,13,4,1]
        Output: 5.5
            0	[7,8,3,4,15,13,4,1]	    []
            1	[7,8,3,4,13,4]	        [8]
            2	[7,8,4,4]	            [8,8]
            3	[7,4]	                [8,8,6]
            4	[]	                    [8,8,6,5.5]

*/

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double res = 9999;
        std::sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            auto value = (double)(nums[start] + nums[end]) / 2;
            if (value < res) {
                res = value;
            }
            start++;
            end--;
        }
        return res;
    }
};

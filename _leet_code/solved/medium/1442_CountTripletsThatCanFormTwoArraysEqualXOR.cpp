/*
    Given an array of integers arr.
    We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
    
    Let's define a and b as follows:
        a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
        b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
        
    Note that ^ denotes the bitwise-xor operation.
    Return the number of triplets (i, j and k) Where a == b.

    Example 1:
        Input: arr = [2,3,1,6,7]
        Output: 4
        Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

    Example 2:
        Input: arr = [1,1,1,1,1]
        Output: 10

    Constraints:
        1 <= arr.length <= 300
        1 <= arr[i] <= 108
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;

        // Iterate over each possible starting index i
        for (int start = 0; start < arr.size() - 1; ++start) {
            // Initialize XOR value for the subarray from start to mid-1
            int xorA = 0;

            // Iterate over each possible middle index j
            for (int mid = start + 1; mid < arr.size(); ++mid) {
                // Update xorA to include arr[mid - 1]
                xorA ^= arr[mid - 1];

                // Initialize XOR value for the subarray from mid to end
                int xorB = 0;

                // Iterate over each possible ending index k (starting from mid)
                for (int end = mid; end < arr.size(); ++end) {
                    // Update xorB to include arr[end]
                    xorB ^= arr[end];

                    // found a valid triplet (start, mid, end)
                    if (xorA == xorB) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};
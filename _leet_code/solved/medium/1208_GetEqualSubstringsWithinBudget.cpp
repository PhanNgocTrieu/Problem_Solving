/*
	You are given two strings s and t of the same length and an integer maxCost.
	You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| 
	(i.e., the absolute difference between the ASCII values of the characters).

	Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t
	with a cost less than or equal to maxCost. 
	If there is no substring from s that can be changed to its corresponding substring from t, return 0.

	Example 1:
	Input: s = "abcd", t = "bcdf", maxCost = 3
	Output: 3
	Explanation: "abc" of s can change to "bcd".
	That costs 3, so the maximum length is 3.

	Example 2:
	Input: s = "abcd", t = "cdef", maxCost = 3
	Output: 1
	Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.

	Example 3:
	Input: s = "abcd", t = "acde", maxCost = 0
	Output: 1
	Explanation: You cannot make any change, so the maximum length is 1.
*/


#include <iostream>
using namespace std;

class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int N = s.size();

		int maxLen = 0;
		// Starting index of the current substring
		int start = 0;
		// Cost of converting the current substring in s to t
		int currCost = 0;

		for (int i = 0; i < N; i++) {
			// Add the current index to the substring
			currCost += abs(s[i] - t[i]);

			// Remove the indices from the left end till the cost becomes less than allowed
			while (currCost > maxCost) {
				currCost -= abs(s[start] - t[start]);
				start++;
			}

			maxLen = max(maxLen, i - start + 1);
		}

		return maxLen;
	}
};

int main() {
	// testing
	auto res = Solution().equalSubstring("abcd", "bcdf", 2);
	cout << res << endl;
	auto res = Solution().equalSubstring("hgzs", "acsw", 30);
	cout << res << endl;
	return 0;
}
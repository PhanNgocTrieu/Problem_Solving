/*
    3200. Maximum Height of a Triangle - Easy
    
    You are given two integers red and blue representing the count of red and blue colored balls. 
    You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.
    All the balls in a particular row should be the same color, and adjacent rows should have different colors.
    
    Return the maximum height of the triangle that can be achieved.

    Example 1:
        Input: red = 2, blue = 4
        Output: 3

    Explanation: The only possible arrangement is shown above.

    Example 2:
        Input: red = 2, blue = 1
        Output: 2
        Explanation:
        The only possible arrangement is shown above.

    Example 3:
        Input: red = 1, blue = 1
        Output: 1

    Example 4:
        Input: red = 10, blue = 1
        Output: 2
        Explanation: The only possible arrangement is shown above.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int red, int blue) {
        int h = 0;
        int i = 1;

        while (true) {
            if (i % 2 == 1) { // If current is old -> get the red one! (default for left (red) - but this can be red or blue)
                if (red >= i) {
                    red -= 1;
                } else {
                    break;
                }
            } else {
                if (blue >= i) { // If current is even -> get the blue one (default for right (blue) - but this can be red or blue)
                    blue -= 1;
                }
                else {
                    break;
                }
            }
            h++;
            i++;
        }

        return h;
    }
    public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red));
    }
};

int main() {
    cout << Solution{}.maxHeightOfTriangle(2 , 4) << endl;
    cout << Solution{}.maxHeightOfTriangle(2 , 1) << endl;
    cout << Solution{}.maxHeightOfTriangle(1 , 1) << endl;
    cout << Solution{}.maxHeightOfTriangle(10 , 1) << endl;
    return 0;
}

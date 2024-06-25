/*
    3195. Find the Minimum Area to Cover All Ones I  -  Medium

    You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
    Return the minimum possible area of the rectangle.

    Example:
        Input: grid = [[0,1,0],[1,0,1]]
        Output: 6

        Input: grid = [[1,0],[0,0]]
        Output: 1
*/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        int l = INT_MAX, u = INT_MAX;
        int r = INT_MIN, d = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    u = min(u, i);
                    r = max(r, j);
                    d = max(d, i);
                }
            }
        }

        return (r - l + 1) * (d - u + 1);
    }
};

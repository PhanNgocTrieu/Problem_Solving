/*
    Given an integer array hours representing times in hours,
    return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.
    A complete day is defined as a time duration that is an "exact multiple" of 24 hours.
    For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

    Example 1:
        Input: hours = [12,12,30,24,24]
        Output: 2
        Explanation: The pairs of indices that form a complete day are (0, 1) and (3, 4).

    Example 2:
        Input: hours = [72,48,24,3]
        Output: 3
        Explanation: The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).
*/
#include "../common.h"

class Solution
{
public:
    long long countCompleteDayPairs(const vector<int> &hours)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = hours.size();
        long long ans = 0;
        vector<int> cnt(24);
        for (int i = 0, r; i < n;)
        {
            cout << "hours[" << i << "]: " << hours[i] << "-->";
            r = hours[i++] % 24;
            ans += cnt[(24 - r) % 24];
            ++cnt[r];
            cout << " r = " << r << "\t - cnt[(24 - r) % 24]: " << "cnt[" << (24 - r) % 24 << "]" << "\t -> cnt[" << r <<"]: " << cnt[r] << " - res: " << ans << endl;
        }
        return ans;
    }
};

int main()
{
    Solution{}.countCompleteDayPairs({12,12,30,24,24,72,18,12});
    return 0;
}

/**
 * https://leetcode.com/contest/weekly-contest-405/problems/find-the-encrypted-string/description/
 */

class Solution {
public:
    string getEncryptedString(string s, int k) {
        unordered_map<int, char> mapping;
        for (int i = 0; i < s.length(); ++i) {
            auto idx = (i + k) % s.length();
            mapping[i] = s[idx];
        }
        for (int i = 0; i < s.length(); ++i) {
            s[i] = mapping[i];
        }
        return s;
    }
};
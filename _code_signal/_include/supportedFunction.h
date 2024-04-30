#ifndef __SUPPORT_H
#define __SUPPORT_H

#include "common.h"

using namespace std;

namespace supportedFunctions
{
    struct runner
    {
        int mPos;
        int mV;
    };

    typedef enum
    {
        CornerOf0sAnd1s = 0,
        Eruption_of_Light
    } nameOfProblems;

    typedef enum
    {
        easy = 0,
        medium,
        hard,
        expert
    } problemsLevels;

    void seperate(int &sum, int n)
    {
        while (n > 0)
        {
            sum += n % 10;
            n = n / 10;
        }
    }

    void __deleteLetter(string &question, int pos)
    {
        int last_element = question.length() - 1;
        for (int i = pos; i <= last_element; i++)
        {
            int j = i + 1;
            question[i] = question[j];
        }
        question.pop_back();
        // return question;
    }

    void __addingLetter(string &question, int pos)
    {
        int max = question.length() - 1;
        question.push_back(question[max]);
        for (int i = max; i >= pos; --i)
        {
            int j = i - 1;
            if (i == pos)
            {
                question[i] = ' ';
            }
            else
            {
                question[i] = question[j];
            }
        }
    }

    void sumOfnInStack(stack<int> &s, int n)
    {
        while (n != 0)
        {
            int temp = n % 2;
            s.push(temp);
            n = n / 2;
        }
    }

    int sumOfn(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            int temp = n % 2;
            sum += temp;
            n = n / 2;
        }
        return sum;
    }

    bool Palindrome(std::string st)
    {
        int len = st.length();
        for (int i = 0; i < len; i++)
        {
            int j = len - i - 1;
            if (st[i] != st[j])
            {
                return false;
            }
        }
        return true;
    }

    int findValue(vector<int> vec, int _value)
    {
        int len = vec.size();
        for (int idex = 0; idex < len; idex++)
        {
            if (vec[idex] == _value)
                return idex;
        }
        return -1;
    }

    int int_cell(std::string cell)
    {
        int n = cell.length();
        int int_cell_res = 0;
        for (int i = 0; i < n; i++)
        {
            int_cell_res += (int)cell[i];
        }
        return int_cell_res;
    }

    std::vector<int> get_numbers(const std::string &s)
    {
        // create a variable of stream:
        std::stringstream stream(s);
        std::string cur;
        std::vector<int> res;
        while (std::getline(stream, cur, '.')) // push all string except '.' in current
        {
            if (cur.size() > 1 && cur[0] == '0')
            {
                return std::vector<int>();
            }
            if (cur.size() > 3)
            {
                return std::vector<int>();
            }
            res.push_back(std::stoi(cur)); // convert from string to numbers and push in res
        }

        return res;
    }

    std::string Encode(int top_left, int top_right, int bot_left, int bot_right)
    {
        std::cout << "Top Left: " << top_left << ", Top Right: " << top_right << ", Bot Left: " << bot_left << ", Bot Right: " << bot_right << "\n";

        std::cout << (to_string(top_left) + to_string(top_right) + to_string(bot_left) + to_string(bot_right)) << "\n";
        return (to_string(top_left) + to_string(top_right) + to_string(bot_left) + to_string(bot_right));
    }

    std::string get2x2Window(std::vector<vector<int>> matrix, int xPos, int yPos)
    {
        return Encode(matrix[xPos][yPos], matrix[xPos + 1][yPos], matrix[xPos][yPos + 1], matrix[xPos + 1][yPos + 1]);
    }

    void Find(std::vector<int> &track, int &product)
    {
        std::cout << "running this! \n";

        for (int i = 9; i > 1; i--)
        {
            while (product % i == 0)
            {
                track.push_back(i);
                std::cout << "i" << i << "\n";
                product = product / i;
                std::cout << "product " << product << '\n';
            }
        }
    }

    void splitString(vector<string> &vs, string s)
    {
        if (s == "")
        {
            return;
        }
        int len = s.length();
        string str = "";
        bool digit = false;
        for (int idex = 0; idex < len; idex++)
        {
            if (s[idex] >= '0' && s[idex] <= '9')
            {
                str += s[idex];
                digit = true;
            }
            else
            {
                if (digit)
                {
                    vs.push_back(str);
                    str = "";
                    digit = false;
                }
                str += s[idex];
                vs.push_back(str);
                str = "";
            }
        }
        if (digit == true)
            vs.push_back(str);
    }

    bool checkZeros(string numberString, int &_countZeros)
    {
        int len = numberString.size();
        for (auto idex = 0; idex < len; idex++)
        {
            if (!(numberString[idex] >= '0' && numberString[idex] <= '9'))
            {
                return false;
            }
            if (numberString[idex] == '0')
                _countZeros++;
        }
        return true;
    }

    int calFields(string ver)
    {
        int sum = 0;
        for (char c : ver)
        {
            sum += (int)c;
        }
        return sum;
    }

    char digitCipher(char c)
    {
        return char((int)c - 48 + 97);
    }

    char letterCipher(char c)
    {
        return char((int)c - 97 + 48);
    }

    int d(int x)
    {
        if (x == 1)
            return 1;
        int count = 0;
        for (int i = 1; i < x; i++)
        {
            if (x % i == 0)
            {
                count++;
            }
        }
        return count + 1;
    }

    int weak(int x)
    {
        int d_max = 0;
        for (int i = 1; i < x; i++)
        {
            if (d(i) > d(x))
                d_max++;
        }
        return d_max;
    }

    bool checking(string base, string presentation)
    {
        int digitCount = 0;
        if (presentation == "")
        {
            return false;
        }
        char letterBelowLimit;
        char letterUpponLimit = 'A';
        if (stoi(base) > 10)
        {
            letterBelowLimit = 'A';
            letterUpponLimit += (stoi(base) - 10) - 1; // base 13: -> limit = A + 3 = ABCD -> D
            cout << "base: " << base << endl;
            for (char c : presentation)
            {
                cout << "C : " << c << endl;
                if (!((c >= '0' && c <= '9') || (c >= letterBelowLimit && c <= letterUpponLimit) || (c >= letterBelowLimit + 32 && c <= letterUpponLimit + 32) || c == '_'))
                {
                    return false;
                }
                if ((c >= '0' && c <= '9') || (c >= letterBelowLimit && c <= letterUpponLimit) || (c >= letterBelowLimit + 32 && c <= letterUpponLimit + 32))
                    digitCount++;
            }

            if (digitCount == 0)
            {
                return false;
            }
            return true;
        }
        else
        {
            letterBelowLimit = '0';
            letterUpponLimit = '0' + stoi(base) - 1;
            for (char c : presentation)
            {
                cout << "C : " << c << endl;
                if (!((c >= letterBelowLimit && c <= letterUpponLimit) || c == '_'))
                {
                    return false;
                }
                if ((c >= '0' && c <= '9'))
                    digitCount++;
            }
            if (digitCount == 0)
            {
                return false;
            }
            return true;
        }
    }

    bool noHastag(char c)
    {
        if (!((c >= '0' && c <= '9') || c == '_'))
        {
            return false;
        }
        return true;
    }

    int countDigit(const string &_line)
    {
        int count = 0;
        for (char c : _line)
        {
            if (c >= '0' && c <= '9')
                count++;
        }
        return count;
    }

    string convertBase(string base)
    {
        string base_result = "";
        for (char c : base)
        {
            if (c == '_')
                continue;
            base_result += c;
        }
        return base_result;
    }

    int mPow(const int &_value, int base)
    {
        int res = 1;
        while (base > 0)
        {
            res *= _value;
            base--;
        }
        return res;
    }

    int splitNumber(int _number, int width, int &count)
    {
        int res = 0;
        while (_number > 0 && count < width)
        {
            int temp = _number % 10;
            res = mPow(10, count) * temp + res;
            _number = _number / 10;
            count++;
        }
        // 1234
        // 10^0 = 1*4 = 4 - count = 1
        // 10^1 = 10*3 + 4 = 34 = count = 2
        // 10^2 = 100*2 + 34 = 234 - count = 3
        // 10^3 = 1000*1 + 234 = 1234 - count = 4
        return res;
    }

    void opposited(vector<int> &vec)
    {
        if (vec.empty())
            return;
        int sz = vec.size();
        for (int index = 0; index < sz; index++)
        {
            vec[index] = (vec[index] == 1) ? 0 : 1;
        }
    }

    int calculate_sum_array(vector<int> a, int size)
    {
        int sum = 0;
        for (int idex = 0; idex < size; idex++)
        {
            sum += a[idex];
        }

        return sum;
    }

    void rmFirst(string &s)
    {
        if (s.length() == 0)
            return;
        while (s[0] < 65 || (s[0] > 90 && s[0] < 97) || s[0] > 122)
        {
            if (s.length() != 0)
                s.erase(0, 1);
            else
                return;
        }
    }

    void rmLast(string &s)
    {
        if (s.length() == 0)
            return;
        int len = s.length() - 1;
        while (s[len] < 65 || (s[len] > 90 && s[len] < 97) || s[len] > 122)
        {
            if (s.length() != 0)
            {
                s.pop_back();
                len = s.length() - 1;
            }
            else
                return;
        }
    }

    void Print(vector<string> inputArray)
    {
        for (string s : inputArray)
        {
            std::cout << s << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> format(std::string s)
    {
        map<char, int> mapping;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (mapping.find(ch) == mapping.end())
            {
                mapping[ch] = 0;
            }
            mapping[ch]++;
        }
        vector<int> res;
        for (auto it : mapping)
        {
            res.push_back(it.second);
        }
        sort(res.begin(), res.end());

        for (auto it : res)
        {
            cout << res[it] << " ";
        }
        cout << "\n";
        return res;
    }

    struct CipherValue
    {
        char key;
        char value;
    };

    int s(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += x % 10;
            x = x / 10;
        }
        return res;
    }

    vector<int> step(int x)
    {
        vector<int> output;

        while (x > 0)
        {
            output.push_back(x - s(x));
            x = x - s(x);
        }
        // output:
        // 88, 72, 63, 54, 45, 36, 27, 18, 9, 0
        return output;
    }

    int findMax(map<int, int> mp)
    {
        // find the max frequency
        int max_count = 0;
        int output = 0;
        for (auto i : mp)
        {

            if (max_count < i.second)
            {
                max_count = i.second;
                output = i.first;
            }

            if (max_count == i.second)
            {
                if (output < i.first)
                {
                    output = i.first;
                }
            }
        }

        return output;
    }
};

#endif
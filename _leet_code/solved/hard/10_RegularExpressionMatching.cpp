#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isMatch(string s, string p)
{
    int len_s = s.length();
    int len_p = p.length();

    uint32_t _table[35][35];

    /**
     * Filling all of data to 0
     */
    for (int idex; idex <= len_p; idex++)
    {
        for (int jdex; jdex <= len_s; jdex++)
        {
            _table[idex][jdex] = 0;
        }
    }

    _table[0][0] = 1;

    for (int index = 1; index <= len_p; index++)
    {
        if (p[index - 1] == '*')
        {
            if (index == 1)
            {
                _table[1][0] = 1;
            }
            else if (_table[index - 2][0])
            {
                _table[index][0] = 1;
            }
            else
            {
                _table[index][0] = 0;
            }
        }
        else
        {
            _table[index][0] = 0;
        }
    }

    int idex;
    int jdex;
    for (idex = 1; idex <= len_p; idex++)
    {
        for (jdex = 1; jdex <= len_s; jdex++)
        {
            if ((p[idex - 1] == s[jdex - 1]) || p[idex - 1] == '.')
            {
                _table[idex][jdex] = _table[idex - 1][jdex - 1];
            }
            else
            {
                if (p[idex - 1] == '*')
                {
                    if (s[jdex - 1] == p[idex - 2] || p[idex - 2] == '.')
                    {
                        _table[idex][jdex] = (_table[idex - 2][jdex] || _table[idex][jdex - 1]);
                    }
                    else
                    {
                        _table[idex][jdex] = _table[idex - 2][jdex];
                    }
                }
                else
                {
                    _table[idex][jdex] = 0;
                }
            }
        }
    }

    return _table[idex][jdex];
}

int main() {
    return 0;
}
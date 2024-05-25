#include "common.h"

int countDigitOne(int n)
{
    if (n == 0)
        return 0;
    unsigned int curr = n % 10;
    unsigned int left = n / 10;
    unsigned int right = 0;
    unsigned int base = 1;
    unsigned int sum = 0;
    while (curr != 0 || left != 0)
    {
        if (curr > 1)
            sum = sum + (left + 1) * base;
        else if (curr == 1)
            sum = sum + left * base + right + 1;
        else
            sum = sum + left * base;
        if (base == 1)
            right = curr;
        else
            right = base * curr + right;
        curr = left % 10;
        left = left / 10;
        base = base * 10;
    }
    return sum;
}

int main()
{
}
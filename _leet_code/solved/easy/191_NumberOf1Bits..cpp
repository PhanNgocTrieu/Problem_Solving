/*
    191. Number of 1 Bits - Easy
    Write a function that takes the binary representation of a positive integer and 
    returns the number of set bits it has (also known as the Hamming weight).
    
    Example 1:
        Input: n = 11
        Output: 3
        Explanation:
            The input binary string 1011 has a total of three set bits.
    
    Example 2:
        Input: n = 128
        Output: 1
        Explanation:
            The input binary string 10000000 has a total of one set bit.
    
    Example 3:
        Input: n = 2147483645
        Output: 30
        Explanation:
            The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
*/
class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> bit_(n);
        int res = 0;
        for (int i = 0 ; i < 32; i++) {
            if (bit_[i] & 1) {
                res++;
            }
        }

        return res;
    }
};

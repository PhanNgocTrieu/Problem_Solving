#ifndef __CORE_H
#define __CORE_H

#include "supportedFunction.h"

using namespace std;

#define ll long long

#define range pow(10, 4)

namespace codeSignalProblems
{
    class Core
    {

    public:
        /**
         * @brief Construct a new Core object
         *
         */
        Core();

        /**
         * @brief Destroy the Core object
         *
         */
        ~Core();

        /**
         * @brief Struct for problems belongs to Corner Of 0s and 1s
         *
         */
        struct CornerOf0sAnd1s
        {
        public:
            /**
             * @brief
             * You are given an array of up to four non-negative integers, each less than 256.Your task is to pack these integers into one number M in the following way:
             *
             * The first element of the array occupies the first 8 bits of M;
             * The second element occupies next 8 bits, and so on.
             * Return the obtained integer M.
             *
             * Note: the phrase "first bits of M" refers to the least significant bits of M - the right-most bits of an integer. For further clarification see the following example.
             *
             * Example
             *
             *      For a = [24, 85, 0], the output should be arrayPacking(a) = 21784.
             *
             * An array [24, 85, 0] looks like [00011000, 01010101, 00000000] in binary.
             * After packing these into one number we get 00000000 01010101 00011000 (spaces are placed for convenience), which equals to 21784.
             *
             * @param a
             * @return int
             */
            int arrayPacking(vector<int> a);

            /**
             * @brief
             * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * You're given two integers, n and m. Find position of the rightmost bit in which they differ in their binary representations (it is guaranteed that such a bit exists), counting from right to left.
             *
             * Return the value of 2^position_of_the_found_bit (0-based).
             *
             * Example
             *
             * For n = 11 and m = 13, the output should be
             * differentRightmostBit(n, m) = 2.
             *
             * 1110 = 10112, 1310 = 11012, the rightmost bit in which they differ is the bit at position 1 (0-based) from the right in the binary representations.
             * So the answer is 2^1 = 2.
             *
             * For n = 7 and m = 23, the output should be differentRightmostBit(n, m) = 16.
             *
             * 710 = 1112, 2310 = 101112, i.e.
             *
             * 00111
             * 10111
             * So the answer is 2^4 = 16.
             *
             * @param n
             * @param m
             * @return int
             */
            int differentRightmostBit(int n, int m);

            /**
             * @brief Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * You're given two integers, n and m. Find position of the rightmost pair of equal bits in their binary representations (it is guaranteed that such a pair exists), counting from right to left.
             *
             * Return the value of 2position_of_the_found_pair (0-based).
             *
             * Example
             *  For n = 10 and m = 11, the output should be
             *  equalPairOfBits(n, m) = 2.
             *
             * 1010 = 10102, 1110 = 10112, the position of the rightmost pair of equal bits is the bit at position 1 (0-based) from the right in the binary representations
             * So the answer is 2^1 = 2.
             *
             * @param n
             * @param m
             * @return int
             */
            int equalPairOfBits(int n, int m);

            /*

            */

            /**
            * @brief
            * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
            * In order to stop the Mad Coder evil genius you need to decipher the encrypted message he sent to his minions.
            * The message contains several numbers that, when typed into a supercomputer,
            * will launch a missile into the sky blocking out the sun, and making all the people on Earth grumpy and sad.
            *
            * You figured out that some numbers have a modified single digit in their binary representation
            * More specifically, in the given number n the kth bit from the right was initially set to 0,
            * but its current value might be different. It's now up to you to write a function that will change the kth bit of n back to 0.
            *
            * Example
            *       For n = 37 and k = 3, the output should be
            *       killKthBit(n, k) = 33.
            *
            *       3710 = 1001012 ~> 1000012 = 3310.
            *
            *       For n = 37 and k = 4, the output should be
            *       killKthBit(n, k) = 37.
            *
            * The 4th bit is 0 already (looks like the Mad Coder forgot to encrypt this number), so the answer is still 37.
            *
            *
            *   Algorithm:
            *   - Example: we have n = 30 ==> n_bit = 11110 and k-th = 3
            *   - we have to put the position that we wanna change equal to 1 => 1 << (k-th - 1):
            *   1 = 00001 => 1 << (k-th - 1) = 2  == 00100
            *   - Reverse bit of (k_th - 1) => 00100-> 11011
            *   - Using AND logic to change value of k_th
                11110                     1 & 1 = 1   <==> 0 & 0 = 1
                &                         1 & 0 = 0   <==> 0 & 1 = 0
                11011
                -------
                11010
            *
            *
            *
            *
            * @param n
            * @param k
            * @return int
            */
            int killKthBit(int n, int k);

            /**
             * @brief
             * Reverse the order of the bits in a given integer.
             *
             * Example:
             *
             * For a = 97, the output should be
             * mirrorBits(a) = 67.
             *
             * 97 equals to 1100001 in binary, which is 1000011 after mirroring, and that is 67 in base 10.
             *
             * For a = 8, the output should be
             * mirrorBits(a) = 1.
             *
             * @param a
             * @return int
             */
            int mirrorBits(int a);

            /**
             * @brief
             *
             * @param a
             * @param b
             * @return int
             */
            int rangeBitCount(int a, int b);

            /**
             * @brief
             *
             * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * Presented with the integer n,
             * find the 0-based position of the second rightmost zero bit in its binary representation (it is guaranteed that such a bit exists),
             * counting from right to left.
             *
             * Return the value of 2position_of_the_found_bit.
             *
             * Example
             *
             * For n = 37, the output should be
             * secondRightmostZeroBit(n) = 8.
             *
             * 3710 = 1001012. The second rightmost zero bit is at position 3 (0-based) from the right in the binary representation of n.
             * Thus, the answer is 23 = 8.
             *
             *
             * @param n
             * @return int
             */
            int secondRightmostZeroBit(int n);

            /**
             * @brief
             * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * You're given an arbitrary 32-bit integer n. Take its binary representation,
             * split bits into it in pairs (bit number 0 and 1, bit number 2 and 3, etc.) and swap bits in each pair.
             * Then return the result as a decimal number.
             *
             *  Example
             *
             * For n = 13, the output should be
             * swapAdjacentBits(n) = 14.
             *
             * 1310 = 11012 ~> {11}{01}2 ~> 11102 = 1410.
             *
             * For n = 74, the output should be
             * swapAdjacentBits(n) = 133.
             *
             * 7410 = 010010102 ~> {01}{00}{10}{10}2 ~> 100001012 = 13310.
             *
             *  Note the preceding zero written in front of the initial number: since both numbers are 32-bit integers,
             * they have 32 bits in their binary representation. The preceding zeros in other cases don't matter,
             * so they are omitted. Here, however, it does make a difference.
             *
             * @param n
             * @return int
             */
            int swapAdjacentBits(int n);
        };

        /**
         * @brief Struct for problems belongs to beautiful String
         *
         */
        struct Eruption_of_Light
        {
            /**
             * @brief
             * A string is said to be beautiful
             * if each letter in the string appears at most as many times as the previous letter in the alphabet within the string;
             *
             * ie: b occurs no more times than a; c occurs no more times than b; etc.
             *
             * Given a string, check whether it is beautiful.
             *
             * Example
             *
             * For inputString = "bbbaacdafe", the output should be isBeautifulString(inputString) = true.
             *
             * This string contains 3 as, 3 bs, 1 c, 1 d, 1 e, and 1 f(and 0 of every other letter),
             * so since there aren't any letters that appear more frequently than the previous letter, this string qualifies as beautiful.
             *
             * For inputString = "aabbb", the output should be isBeautifulString(inputString) = false.
             *
             * Since there are more bs than as, this string is not beautiful.
             *
             * For inputString = "bbc", the output should be isBeautifulString(inputString) = false.
             *
             * Although there are more bs than cs, this string is not beautiful because there are no as, so therefore there are more bs than as.
             *
             * @param inputString
             * @return true
             * @return false
             */
            bool isBeautifulString(std::string inputString);

            /**
             * @brief
             *
             * @param st
             * @return std::string
             */
            std::string buildPalindrome(std::string st);

            /*
            Elections are in progress!
            Given an array of the numbers of votes given to each of the candidates so far,
            and an integer k equal to the number of voters who haven't cast their vote yet,
            find the number of candidates who still have a chance to win the election.

            The winner of the election must secure strictly more votes than any other candidate.
            If two or more candidates receive the same(maximum) number of votes, assume there is no winner at all.

            Example

            For votes = [2, 3, 5, 2] and k = 3, the output should be
            electionsWinners(votes, k) = 2.

            The first candidate got 2 votes.Even if all of the remaining 3 candidates vote for him,
            he will still have only 5 votes, i.e.the same number as the third candidate, so there will be no winner.
            The second candidate can win if all the remaining candidates vote for him(3 + 3 = 6 > 5).
            The third candidate can win even if none of the remaining candidates vote for him.For example,
            if each of the remaining voters cast their votes for each of his opponents,
            he will still be the winner(the votes array will thus be[3, 4, 5, 3]).
            The last candidate can't win no matter what (for the same reason as the first candidate).
            Thus, only 2 candidates can win(the second and the third), which is the answer.
            */
            int electionsWinners(std::vector<int> votes, int k);

            /**
             * @brief
             * An email address such as "John.Smith@example.com" is made up of a local part("John.Smith"),
             * an "@" symbol, then a domain part("example.com").
             * The domain name part of an email address may only consist of letters, digits, hyphensand dots.The local part,
             * however, also allows a lot of different special characters.
             * Here you can look at several examples of correctand incorrect email addresses.
             *
             * Given a valid email address, find its domain part.
             *
             * Example
             *
             * For address = "prettyandsimple@example.com", the output should be
             * findEmailDomain(address) = "example.com";
             * For address = "fully-qualified-domain@codesignal.com", the output should be
             * findEmailDomain(address) = "codesignal.com".
             *
             * @param address
             * @return std::string
             */
            std::string findEmailDomain(std::string address);

            /**
             * @brief
             * A media access control address(MAC address) is a unique identifier assigned to network interfaces
             * for communications on the physical network segment.
             *
             * The standard(IEEE 802) format for printing MAC - 48 addresses in human -
             * friendly form is six groups of two hexadecimal digits(0 to 9 or A to F), separated by hyphens(e.g. 01 - 23 - 45 - 67 - 89 - AB).
             *
             * Your task is to check by given string inputString whether it corresponds to MAC - 48 address or not.
             *
             * Example
             * For inputString = "00-1B-63-84-45-E6", the output should be
             * isMAC48Address(inputString) = true;
             * For inputString = "Z1-1B-63-84-45-E6", the output should be
             * isMAC48Address(inputString) = false;
             * For inputString = "not a MAC-48 address", the output should be
             * isMAC48Address(inputString) = false.
             *
             * @param inputString
             * @return true
             * @return false
             */
            bool isMAC48Address(std::string inputString);
        };

        struct IntroGates
        {
            /**
             * @brief
             * You are given a two-digit integer n. Return the sum of its digits.
             *
             * Example
             *
             * For n = 29, the output should be
             * addTwoDigits(n) = 11.
             *
             * @param n
             * @return int
             */
            int addTwoDigits(int n);

            /**
             * @brief
             * n children have got m pieces of candy.
             *
             * They want to eat as much candy as they can, but each child must eat exactly the same amount of candy as any other child.
             *
             * Determine how many pieces of candy will be eaten by all the children together. Individual pieces of candy cannot be split.
             *
             * Example
             *
             * For n = 3 and m = 10, the output should be
             * candies(n, m) = 9.
             *
             * Each child will eat 3 pieces. So the answer is 9.
             * @param n
             * @param m
             * @return int
             */
            int candies(int n, int m);

            /**
             * @brief
             * Consider integer numbers from 0 to n - 1 written down along the circle in such a way
             * That the distance between any two neighboring numbers is equal (note that 0 and n - 1 are neighboring, too).
             *
             * Given n and firstNumber, find the number which is written in the radially opposite position to firstNumber.
             *
             * Example:
             * For n = 10 and firstNumber = 2, the output should be
             * circleOfNumbers(n, firstNumber) = 7.
             *
             * @param n
             * @param firstNumber
             * @return int
             */
            int circleOfNumbers(int n, int firstNumber);

            /**
             * @brief
             * Given an integer n, return the largest number that contains exactly n digits.
             *
             * Example
             * For n = 2, the output should be
             * largestNumber(n) = 99.
             *
             * @param n
             * @return int
             */
            int largestNumber(int n);

            /**
             * @brief
             * One night you go for a ride on your motorcycle. At 00:00 you start your engine,
             * and the built-in timer automatically begins counting the length of your ride, in minutes. Off you go to explore the neighborhood.
             *
             * When you finally decide to head back, you realize there's a chance the bridges on your route home are up,
             * leaving you stranded! Unfortunately, you don't have your watch on you and don't know what time it is.
             *
             * All you know thanks to the bike's timer is that n minutes have passed since 00:00.
             *
             * Using the bike's timer, calculate the current time.
             * Return an answer as the sum of digits that the digital timer in the format hh:mm would show.
             *
             * Example
             *
             * For n = 240, the output should be
             * lateRide(n) = 4.
             *
             * Since 240 minutes have passed, the current time is 04:00.
             * The digits sum up to 0 + 4 + 0 + 0 = 4, which is the answer.
             *
             * For n = 808, the output should be
             * lateRide(n) = 14.
             *
             * 808 minutes mean that it's 13:28 now, so the answer should be 1 + 3 + 2 + 8 = 14.
             *
             * @param n
             * @return int
             */
            int lateRide(int n);

            /**
             * @brief
             * Given a divisor and a bound, find the largest integer N such that:
             *
             * N is divisible by divisor.
             * N is less than or equal to bound.
             * N is greater than 0.
             *
             * It is guaranteed that such a number exists.
             * Example
             *
             * For divisor = 3 and bound = 10, the output should be
             * maxMultiple(divisor, bound) = 9.
             *
             * The largest integer divisible by 3 and not larger than 10 is 9.
             *
             * @param divisor
             * @param bound
             * @return int
             */
            int maxMultiple(int divisor, int bound);

            /**
             * @brief
             * Some phone usage rate may be described as follows:
             *
             * first minute of a call costs min1 cents,
             * each minute from the 2nd up to 10th (inclusive) costs min2_10 cents
             * each minute after 10th costs min11 cents.
             *
             * You have s cents on your account before the call.
             * What is the duration of the longest call (in minutes rounded down to the nearest integer) you can have?
             *
             * Example
             *
             * For min1 = 3, min2_10 = 1, min11 = 2, and s = 20, the output should be
             * phoneCall(min1, min2_10, min11, s) = 14.
             *
             * Here's why:
             *
             * the first minute costs 3 cents, which leaves you with 20 - 3 = 17 cents;
             * the total cost of minutes 2 through 10 is 1 * 9 = 9, so you can talk 9 more minutes and still have 17 - 9 = 8 cents;
             * each next minute costs 2 cents, which means that you can talk 8 / 2 = 4 more minutes.
             * Thus, the longest call you can make is 1 + 9 + 4 = 14 minutes long.
             *
             * @param min1
             * @param min2_10
             * @param min11
             * @param s
             * @return int
             */
            int phoneCall(int min1, int min2_10, int min11, int s);

            /**
             * @brief
             * When a user asks a question on Quora,
             * the system automatically tries to improve the question's formatting before showing it to more users.
             * Given a question as an input string, perform formatting corrections according to the following rules:
             *
             * Strip excessive whitespaces:
             * Remove whitespaces at the start and end, as well as multiple spaces in a row
             *
             * Fix spacing around punctuation:
             * Each comma should have a trailing space, but no space preceding it
             * Questions should start with a capital letter
             * Questions should end with a single question mark (not 0 or more than one).
             *
             * Example
             * For question = " this isn't a relevant question , is it??? ", the output should be
             * questionCorrectionBot(question) = "This isn't a relevant question, is it?";
             * For question = "Is this answer correct?", the output should be
             * questionCorrectionBot(question) = "Is this answer correct?".
             *
             * @param question the input question
             * @return string the correct input question
             *
             *
             * testcases:
             *      cout << questionCorrectionBot("      this  isn't   a     relevant question , is it???          ") << "\n";
             *      cout << questionCorrectionBot("  Is,it    correct    ,    question") << "\n";
             *      cout << questionCorrectionBot("where is F.A.Q.?") << endl;
             *      cout << questionCorrectionBot("a,b,c,d,e ") << endl;
             *      cout << questionCorrectionBot("im,tti") << endl;
             *      cout << questionCorrectionBot("z") << endl;
             *      cout << questionCorrectionBot("questionword ,anotherquestionword,") << endl;
             */
            string questionCorrectionBot(string question);

            /**
             * @brief
             * Your friend advised you to see a new performance in the most popular theater in the city.
             * He knows a lot about art and his advice is usually good, but not this time:
             * the performance turned out to be awfully dull. It's so bad you want to sneak out,
             * which is quite simple, especially since the exit is located right behind your row to the left.
             * All you need to do is climb over your seat and make your way to the exit.
             *
             * The main problem is your shyness:
             * you're afraid that you'll end up blocking the view (even if only for a couple of seconds) of all the people
             * who sit behind you and in your column or the columns to your left. To gain some courage,
             * you decide to calculate the number of such people and see if you can possibly make it to the exit
             * without disturbing too many people.
             *
             * Given the total number of rows and columns in the theater (nRows and nCols, respectively),
             * and the row and column you're sitting in,
             * return the number of people who sit strictly behind you and in your column or to the left, assuming all seats are occupied.
             *
             * Example
             *      For nCols = 16, nRows = 11, col = 5, and row = 3, the output should be
             *      seatsInTheater(nCols, nRows, col, row) = 96.
             *
             * @param nCols
             * @param nRows
             * @param col
             * @param row
             * @return int
             */
            int seatsInTheater(int nCols, int nRows, int col, int row);
        };

        /**
         * @brief 
         * 
         */
        struct SpringOfIntegration
        {
            /**
             * @brief
             * Some people run along a straight line in the same direction.
             * They start simultaneously at pairwise distinct positions and run with constant speed (which may differ from person to person).
             * If two or more people are at the same point at some moment we call that a meeting.
             * The number of people gathered at the same point is called meeting cardinality.
             *
             * For the given starting positions and speeds of runners find the maximum meeting cardinality assuming that people run infinitely long.
             * If there will be no meetings, return -1 instead.
             *
             * @param startPosition array of startPos of participants
             * @param speed arr of speed mapping with participants by idex
             * @return int
             */
            int runnersMeeting(vector<int> startPosition, vector<int> speed);

            /*
                Given an array of 2k integers (for some integer k),
                perform the following operations until the array contains only one element:

                    On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
                    On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.

                After the algorithm has finished, there will be a single element left in the array. Return that element.

                Example

                For inputArray = [1, 2, 3, 4, 5, 6, 7, 8], the output should be
                arrayConversion(inputArray) = 186.

                We have [1, 2, 3, 4, 5, 6, 7, 8] -> [3, 7, 11, 15] -> [21, 165] -> [186], so the answer is 186.
            */
            int arrayConversion(vector<int> inputArray);

            /*
                Given array of integers, for each position i,
                search among the previous positions for the last (from the left) position that contains a smaller value.
                Store this value at position i in the answer. If no such value can be found, store -1 instead.

                Example

                For items = [3, 5, 2, 4, 5], the output should be
                solution(items) = [-1, 3, -1, 2, 4].
            */
            vector<int> arrayPreviousLess(vector<int> items);

            /*
                Consider a string containing only letters and whitespaces.
                It is allowed to replace some (possibly, none) whitespaces with newline symbols
                to obtain a multiline text.

                Call a multiline text beautiful if and only if each of its lines
                (i.e. substrings delimited by a newline character) contains an equal number of characters
                (only letters and whitespaces should be taken into account when counting the total
                while newline characters shouldn't). Call the length of the line the text width.

                Given a string and some integers l and r (l ≤ r),
                check if it's possible to obtain a beautiful text from the string with a text width that's
                within the range [l, r].

                Example:

                For inputString = "Look at this example of a correct text", l = 5, and r = 15, the output should be
                beautifulText(inputString, l, r) = true.

                We can replace 13th and 26th characters with '\n', and obtain the following multiline text of width 12:

                Look at this example of a correct text
                For inputString = "abc def ghi", l = 4, and r = 10, the output should be
                beautifulText(inputString, l, r) = false.

                There are two ways to obtain a text with lines of equal length from this input,
                one has width = 3 and another has width = 11 (this is a one-liner).
                Both of these values are not within our bounds.
            */
            bool beautifulText(string inputString, int l, int r);

            /*
                Miss X has only two combs in her possession, both of which are old and miss a tooth or two.
                he also has many purses of different length, in which she carries the combs.
                The only way they fit is horizontally and without overlapping. Given teeth' positions on both combs,
                find the minimum length of the purse she needs to take them with her.

                It is guaranteed that there is at least one tooth at each end of the comb.
                It is also guaranteed that the total length of two strings is smaller than 32.
                Note, that the combs can not be rotated/reversed.

                Example

                For comb1 = "*..*" and comb2 = "*.*", the output should be
                combs(comb1, comb2) = 5.

                Although it is possible to place the combs like on the first picture, the best way to do this is either picture 2 or picture 3.



                For comb1 = "*...*" and comb2 = "*.*", the output should be
                combs(comb1,comb2) = 5;

                For comb1 = "*..*..*" and comb2 = "*.*", the output should be
                combs(comb1,comb2) = 5;
            */
            int combs(string comb1, string comb2);

            /*
                You're given a substring s of some cyclic string.
                What's the length of the smallest possible string that can be concatenated to itself many times to obtain this cyclic string?

                Example

                For s = "cabca", the output should be
                cyclicString(s) = 3.

                "cabca" is a substring of a cycle string "abcabcabcabc..." that can be obtained by concatenating "abc" to itself.
                Thus, the answer is 3.
            */
            int cyclicString(string s);

            /*
                Yesterday you found some shoes in the back of your closet. Each shoe is described by two values:

                    type indicates if it's a left or a right shoe;
                    size is the size of the shoe.

                Your task is to check whether it is possible to pair the shoes you found in such a way that
                each pair consists of a right and a left shoe of an equal size.

                Example

                    For

                    shoes = {0, 21},
                            {1, 23},
                            {1, 21},
                            {0, 23}}

                    the output should be
                    pairOfShoes(shoes) = true;

                    For

                    shoes = {{0, 21},
                            {1, 23},
                            {1, 21},
                            {1, 23}}

                    the output should be
                    pairOfShoes(shoes) = false
            */
            bool pairOfShoes(vector<vector<int>> shoes);

            /*
                Define crossover operation over two equal-length strings A and B as follows:

                the result of that operation is a string of the same length as the input strings
                result[i] is either A[i] or B[i], chosen at random
                Given array of strings inputArray and a string result,
                find for how many pairs of strings from inputArray the result of the crossover operation over them may be equal to result.

                Note that (A, B) and (B, A) are the same pair.
                Also note that the pair cannot include the same element of the array twice
                (however, if there are two equal elements in the array, they can form a pair).

                Example

                For inputArray = ["abc", "aaa", "aba", "bab"] and result = "bbb", the output should be
                stringsCrossover(inputArray, result) = 2.
            */
            int stringsCrossover(vector<string> inputArray, string result);
        };

        std::string alphabeticShift(std::string inputString)
        {
            std::string res = "";

            for (auto c : inputString)
            {
                if (c == 'z' || c == 'Z')
                {
                    c = 'a';
                    res += c;
                }
                else
                {
                    c = c + 1;
                    res += c;
                }
            }

            return res;
        }

        struct Lab_Of_Transformation
        {
            bool alphanumericLess(string s1, string s2)
            {
                vector<string> tokens1;
                vector<string> tokens2;
                int countZeros1 = 0;
                int countZeros2 = 0;
                supportedFunctions::splitString(tokens1, s1);
                supportedFunctions::splitString(tokens2, s2);

                if (supportedFunctions::checkZeros(s1, countZeros1) && supportedFunctions::checkZeros(s2, countZeros2))
                {
                    if (countZeros1 > countZeros2)
                        return true;
                    if (countZeros1 < countZeros2)
                        return false;
                }

                int limt = tokens1.size() < tokens2.size() ? tokens1.size() : tokens2.size();

                for (int idex = 0; idex < limt; idex++)
                {
                    string _s1 = tokens1[idex];
                    string _s2 = tokens2[idex];
                    if (_s1[0] >= '0' && _s1[0] <= '9' && _s2[0] >= '0' && _s2[0] <= '9')
                    {
                        if (stoi(_s1) < stoi(_s2))
                            return true;
                        if (stoi(_s1) > stoi(_s2))
                            return false;

                        if (supportedFunctions::checkZeros(_s1, countZeros1) && supportedFunctions::checkZeros(_s2, countZeros2))
                        {
                            if (countZeros1 > countZeros2)
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        if (_s1 < _s2)
                            return true;
                        if (_s1 > _s2)
                            return false;
                    }
                }

                if (tokens1.size() < tokens2.size())
                    return true;
                return false;
            }

            string characterParity(char symbol)
            {
                if (symbol >= '0' && symbol <= '9')
                {
                    if ((int)symbol % 2 == 0)
                    {
                        return string("even");
                    }
                    return string("odd");
                }
                return string("not a digit");
            }

            string cipher26(string message)
            {
                string res = "";
                // take first letter
                res += message[0];

                int len = message.length();

                // sum of first number
                int sum = (int)message[0] - 'a';

                for (int idex = 1; idex < len; idex++)
                {
                    // take next letter - encrypted
                    int encryptedletter = (int)message[idex] - 'a';

                    // take reference letter - unencrypted
                    int unencryptedLetter = 26 + encryptedletter - sum;

                    // checking whether letter is larger than 26 or not
                    if (unencryptedLetter >= 26)
                    {
                        unencryptedLetter = unencryptedLetter - 26;
                    }

                    res += (char)('a' + unencryptedLetter);

                    sum = sum + unencryptedLetter;

                    // checking whether sum is larger than 26 or not
                    if (sum > 26)
                    {
                        sum = sum - 26;
                    }
                    cout << "res: " << res << endl;
                }

                return res;
            }

            string decipher(string cipher)
            {
                string res = "";
                int sum = 0;
                int i = 0;
                for (char c : cipher)
                {
                    sum = sum * 10 + ((int)c - '0');

                    if (sum >= 97 && sum <= 122)
                    {
                        char letter = (char)sum;
                        res += letter;
                        sum = 0;
                    }
                }
                return res;
            }

            bool higherVersion(string ver1, string ver2)
            {
                if (ver1 == ver2)
                {
                    return false;
                }
                stringstream ss(ver1);
                vector<string> version1;
                string words;
                while (getline(ss, words, '.'))
                {
                    version1.push_back(words);
                }
                stringstream ss2(ver2);
                vector<string> version2;
                while (getline(ss2, words, '.'))
                {
                    version2.push_back(words);
                }

                for (int idex = 0; idex < version1.size(); idex++)
                {
                    int ver1Field = supportedFunctions::calFields(version1[idex]);
                    int ver2Field = supportedFunctions::calFields(version2[idex]);
                    if (ver1Field > ver2Field)
                    {
                        return true;
                    }
                    if (ver2Field > ver1Field)
                    {
                        return false;
                    }
                }
                return false;
            }

            vector<string> newNumeralSystem(char number)
            {
                vector<string> res;
                char a = 'A';
                while (a <= number)
                {
                    string s = "";
                    s += a;
                    s += " + ";
                    s += number;
                    res.push_back(s);
                    a++;
                    number--;
                }
                return res;
            }

            string reflectString(string inputString)
            {
                string res = "";
                for (char c : inputString)
                {
                    res += (122 + 97 - (int)c);
                }
                return res;
            }

            string stolenLunch(string note)
            {
                if (note == "")
                    return note;
                string res = "";
                for (char c : note)
                {
                    if (c >= '0' && c <= '9')
                    {
                        res += supportedFunctions::digitCipher(c);
                    }
                    else
                    {
                        if (c >= 'a' && c <= 'j')
                        {
                            res += supportedFunctions::letterCipher(c);
                        }
                        else
                        {
                            res += c;
                        }
                    }
                }
                return res;
            }

            int comfortableNumbers(int l, int r)
            {
                std::cout << "Range(l,r): [" << l << ";" << r << "]: \n";
                if (l == r)
                    return 0;
                int pairsNum = 0;
                std::vector<std::pair<int, int>> pairs;

                for (int i = l; i <= r; i++)
                {
                    int S = 0;
                    int temp = i;
                    while (temp > 0)
                    {
                        S += temp % 10;
                        temp /= 10;
                    }
                    for (int j = i - S; j < i + S; j++)
                    {
                        if ((j >= l) && (j <= r))
                        {
                            if (j > i)
                            {
                                pairs.push_back(std::make_pair(i, j));
                            }

                            if (j < i)
                            {
                                if (std::find(pairs.begin(), pairs.end(), std::make_pair(j, i)) != pairs.end())
                                {
                                    pairsNum++;
                                }
                            }
                        }
                    }
                }
                return pairsNum;
            }

            vector<int> weakNumbers(int n)
            {
                vector<int> result;
                int weakness_level = 0;
                int weakness_level_numbers = 1;
                for (int i = 2; i <= n; i++)
                {
                    if (supportedFunctions::weak(i) == weakness_level)
                        weakness_level_numbers++;
                    if (supportedFunctions::weak(i) > weakness_level)
                    {
                        weakness_level = supportedFunctions::weak(i);
                        weakness_level_numbers = 1;
                    }
                }
                result.push_back(weakness_level);
                result.push_back(weakness_level_numbers);
                return result;
            }

            /*
                Consider two following representations of a non-negative integer:
                A simple decimal integer, constructed of a non-empty sequence of digits from 0 to 9;
                An integer with at least one digit in a base from 2 to 16 (inclusive), enclosed between # characters, and preceded by the base,
                which can only be a number between 2 and 16 in the first representation.
                For digits from 10 to 15 characters a, b, ..., f and A, B, ..., F are used.

                Additionally, both representations may contain underscore (_) characters;
                they are used only as separators for improving legibility of numbers and can be ignored while processing a number.

                Your task is to determine whether the given string is a valid integer representation.

                Note: this is how integer numbers are represented in the programming language Ada.

                Example

                For line = "123_456_789", the output should be
                adaNumber(line) = true;
                For line = "16#123abc#", the output should be
                adaNumber(line) = true;
                For line = "10#123abc#", the output should be
                adaNumber(line) = false;
                For line = "10#10#123ABC#", the output should be
                adaNumber(line) = false;
                For line = "10#0#", the output should be
                adaNumber(line) = true;
                For line = "10##", the output should be
                adaNumber(line) = false.
            */
            bool adaNumber(string line)
            {

                if (line[0] == '#')
                {
                    return false;
                }

                int count_hastag = count(line.begin(), line.end(), '#');
                int existUnderscore = count(line.begin(), line.end(), '_');

                if (count_hastag >= 3 || count_hastag == 1)
                {
                    return false;
                }

                if (supportedFunctions::countDigit(line) == 0)
                {
                    return false;
                }

                if (count_hastag == 0)
                {
                    // checking for underscore
                    for (char c : line)
                    {
                        if (!supportedFunctions::noHastag(c))
                        {
                            return false;
                        }
                    }
                    return true;
                }

                int iPushing = 0;
                string base;
                string presentation;

                stringstream ss(line);
                string word;
                while (getline(ss, word, '#'))
                {
                    if (iPushing == 0)
                    {
                        base = word;
                    }
                    else
                    {
                        presentation = word;
                    }
                    iPushing++;
                }

                base = supportedFunctions::convertBase(base);

                cout << "Base: " << base << endl;
                cout << "Presentation: " << presentation << endl;

                if (stoi(base) > 16 || stoi(base) < 2)
                {
                    return false;
                }
                return supportedFunctions::checking(base, presentation);
            }

            /*
                Given a rectangular matrix of characters, add a border of asterisks(*) to it.
                Example
                    For
                    picture = ["abc",
                            "ded"]
                    the output should be

                    addBorder(picture) = ["*****",
                                        "*abc*",
                                        "*ded*",
                                        "*****"]
            */
            vector<string> addBorder(vector<string> picture)
            {
                vector<string> res;
                int size = picture.size() + 2; // 2
                int len_max = picture[0].length() + 2;

                for (int index = 0; index < size; index++)
                {
                    cout << index << endl;
                    if (index == 0 || index == size - 1)
                    {
                        string s = "";
                        for (int rlen = 0; rlen < len_max; rlen++)
                        {
                            s += "*";
                        }
                        res.push_back(s);
                    }
                    else
                    {
                        string s = "*";
                        s += picture[index - 1];
                        s += "*";
                        res.push_back(s);
                    }
                }
                return res;
            }

            /*
                Given an array of strings, return another array containing all of its longest strings.
                Example
                    For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
                    allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
            */
            vector<string> allLongestStrings(vector<string> inputArray)
            {
                vector<string> list{};
                int max_len = inputArray[0].length();
                for (string str : inputArray)
                {
                    if (str.length() > max_len)
                    {
                        max_len = str.length();
                        list = {};
                        list.push_back(str);
                    }
                    else
                    {
                        if (str.length() == max_len)
                        {
                            list.push_back(str);
                        }
                    }
                }
                return list;
            }

            /*
                Check whether the given string is a subsequence of the plaintext alphabet.
                Example
                    For s = "effg", the output should be
                        alphabetSubsequence(s) = false;
                    For s = "cdce", the output should be
                        alphabetSubsequence(s) = false;
                    For s = "ace", the output should be
                        alphabetSubsequence(s) = true;
                    For s = "bxz", the output should be
                     alphabetSubsequence(s) = true.
            */
            bool alphabetSubsequence(string s)
            {
                char prev = 'a';
                for (char c : s)
                {
                    if (s[0] == 'a')
                        continue;
                    if (c <= prev)
                        return false;
                    prev = c;
                }

                return true;
            }

            /*
                Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

                Given two arrays a and b, check whether they are similar.

                Example

                For a = [1, 2, 3] and b = [1, 2, 3], the output should be
                areSimilar(a, b) = true.

                The arrays are equal, no need to swap any elements.

                For a = [1, 2, 3] and b = [2, 1, 3], the output should be
                areSimilar(a, b) = true.

                We can obtain b from a by swapping 2 and 1 in b.

                For a = [1, 2, 2] and b = [2, 1, 1], the output should be
                areSimilar(a, b) = false.

                Any swap of any two elements either in a or in b won't make a and b equal.
            */
            bool areSimilar(vector<int> a, vector<int> b)
            {
                if (a.size() != b.size())
                    return false;
                int len = a.size();
                int diff = 0;
                int saveA_1;
                int saveA_2;
                int saveB_1;
                int saveB_2;
                int i = 0;
                for (int iRun = 0; iRun < len; iRun++)
                {
                    if (a[iRun] != b[iRun])
                    {
                        diff++;
                        cout << "diff: " << diff << endl;
                        if (diff == 1)
                        {
                            saveA_1 = a[iRun];
                            saveB_1 = b[iRun];
                        }
                    }

                    if (diff >= 2)
                    {

                        if (i == 0)
                        {
                            if (diff == 2)
                            {
                                saveA_2 = a[iRun];
                                saveB_2 = b[iRun];
                            }
                            i++;
                        }
                        else
                        {
                            if (diff > 2)
                            {
                                return false;
                            }
                        }
                    }
                }
                if (diff == 1)
                {
                    return false;
                }
                if (diff == 2)
                {
                    if (saveA_1 != saveB_2 || saveB_1 != saveA_2)
                    {
                        return false;
                    }
                }
                return true;
            }

            /*
                Elections are in progress!
                Given an array of the numbers of votes given to each of the candidates so far, and an integer k equal to the number of voters who haven't cast their vote yet,
                find the number of candidates who still have a chance to win the election.
                The winner of the election must secure strictly more votes than any other candidate.
                If two or more candidates receive the same (maximum) number of votes, assume there is no winner at all.

                Example:
                    For votes = [2, 3, 5, 2] and k = 3, the output should be
                    electionsWinners(votes, k) = 2.

                    The first candidate got 2 votes. Even if all of the remaining 3 candidates vote for him, he will still have only 5 votes, i.e. the same number as the third candidate,
                    so there will be no winner.
                    The second candidate can win if all the remaining candidates vote for him (3 + 3 = 6 > 5).
                    The third candidate can win even if none of the remaining candidates vote for him. For example,
                    if each of the remaining voters cast their votes for each of his opponents, he will still be the winner (the votes array will thus be [3, 4, 5, 3]).

                    The last candidate can't win no matter what (for the same reason as the first candidate).
                    Thus, only 2 candidates can win (the second and the third), which is the answer.
            */
            int electionsWinners(vector<int> votes, int k)
            {
                int count = 0;
                for (int iRun = 0; iRun < votes.size(); iRun++)
                {
                    int winner = votes[iRun] + k;
                    bool win = true;
                    for (int jRun = 0; jRun < votes.size(); jRun++)
                    {
                        if (jRun == iRun)
                        {
                            continue;
                        }
                        if (winner <= votes[jRun])
                        {
                            win = false;
                            break;
                        }
                    }
                    if (win)
                    {
                        count++;
                    }
                }
                return count;
            }

            /*
                A boy is walking a long way from school to his home.To make the walk more fun he decides to add up all the numbers of the houses
                that he passes by during his walk.Unfortunately, not all of the houses have numbers written on them,
                and on top of that the boy is regularly taking turns to change streets, so the numbers don't appear to him in any particular order.

                At some point during the walk the boy encounters a house with number 0 written on it, which surprises him so much that he stops adding numbers to his total right after seeing that house.

                For the given sequence of houses determine the sum that the boy will get.It is guaranteed that there will always be at least one 0 house on the path.

                Example
                    For inputArray = [5, 1, 2, 3, 0, 1, 5, 0, 2], the output should be
                    houseNumbersSum(inputArray) = 11.
                    The answer was obtained as 5 + 1 + 2 + 3 = 11.
            */
            int houseNumbersSum(vector<int> inputArray)
            {
                int res = 0;
                for (int i : inputArray)
                {
                    if (i == 0)
                        return res;
                    res += i;
                }
                return res;
            }

            /*
                There are some people and cats in a house.
                You are given the number of legs they have all together.
                Your task is to return an array containing every possible number of people
                that could be in the house sorted in ascending order.
                It's guaranteed that each person has 2 legs and each cat has 4 legs.

                Example

                For legs = 6, the output should be
                houseOfCats(legs) = [1, 3].

                There could be either 1 cat and 1 person (4 + 2 = 6) or 3 people (2 * 3 = 6).

                For legs = 2, the output should be
                houseOfCats(legs) = [1].

                There can be only 1 person.
            */
            vector<int> houseOfCats(int legs)
            {
                vector<int> res;
                if (legs % 2 != 0)
                    return res;
                if (legs == 0)
                {
                    res.push_back(0);
                    return res;
                }

                int maxPeo = legs / 2;
                int maxCat = legs / 4;
                int minPeo = (legs - maxCat * 4) / 2;

                while (minPeo <= maxPeo)
                {
                    res.push_back(minPeo);
                    minPeo += 2;
                }
                return res;
            }

            /*
                Given a positive integer number and a certain length, we need to modify the given number to have a specified length.
                We are allowed to do that either by cutting out leading digits
                (if the number needs to be shortened) or by adding 0s in front of the original number.

                Example:
                    For number = 1234 and width = 2, the output should be
                    integerToStringOfFixedWidth(number, width) = "34";
                    For number = 1234 and width = 4, the output should be
                    integerToStringOfFixedWidth(number, width) = "1234";
                    For number = 1234 and width = 5, the output should be
                    integerToStringOfFixedWidth(number, width) = "01234".
            */
            string integerToStringOfFixedWidth(int number, int width)
            {
                string res = "";
                int countWidth = 0;
                if (number == 0)
                {
                    while (countWidth < width)
                    {
                        res.append("0");
                        countWidth++;
                    }
                    return res;
                }
                int _number = number;
                int _splitValue = supportedFunctions::splitNumber(_number, width, countWidth); // 34

                if (countWidth < width)
                {
                    while (countWidth < width)
                    {
                        res.append("0");
                        countWidth++;
                    }
                    res.append(to_string(number));
                    return res;
                }
                res.append(to_string(_splitValue));

                return res;
            }

            /*
                You find yourself in Bananaland trying to buy a banana.
                You are super rich so you have an unlimited supply of banana-coins, but you are trying to use as few coins as possible.
                The coin values available in Bananaland are stored in a sorted array coins. coins[0] = 1,
                and for each i (0 < i < coins.length) coins[i] is divisible by coins[i - 1].
                Find the minimal number of banana-coins you'll have to spend to buy a banana given the banana's price.

                Example

                For coins = [1, 2, 10] and price = 28, the output should be
                minimalNumberOfCoins(coins, price) = 6.
                You have to use 10 twice, and 2 four times.
            */
            int minimalNumberOfCoins(vector<int> coins, int price)
            {
                int count = 0;
                for (int index = coins.size() - 1; index >= 0; index--)
                {
                    if (price == 0)
                        return count;

                    while (coins[index] <= price)
                    {
                        price = price - coins[index];
                        count++;
                    }
                }
                return count;
            }

            vector<int> switchLights(vector<int> a)
            {
                vector<int> res;
                int size = a.size();
                for (int index = 0; index < size; index++)
                {
                    if (a[index] == 1)
                    {
                        supportedFunctions::opposited(res);
                        res.push_back(0);
                    }
                    else
                    {
                        res.push_back(0);
                    }
                }
                return res;
            }

            /*
                You have a long strip of paper with integers written on it in a single line from left to right.
                You wish to cut the paper into exactly three pieces such
                that each piece contains at least one integer and the sum of the integers in each piece is the same.
                You cannot cut through a number, i.e. each initiRunl number will unambiguously belong to one of the pieces after cutting.
                How many ways can you do it?

                It is guaranteed that the sum of all elements in the array is divisible by 3.

                Example

                For a = [0, -1, 0, -1, 0, -1], the output should be
                threeSplit(a) = 4.

                Here are all possible ways:

                [0, -1] [0, -1] [0, -1]
                [0, -1] [0, -1, 0] [-1]
                [0, -1, 0] [-1, 0] [-1]
                [0, -1, 0] [-1] [0, -1]
            */
            int threeSplit(vector<int> a)
            {
                int ways = 0;
                int first_part = 0;
                int second_part;
                int size = a.size();
                int sum = supportedFunctions::calculate_sum_array(a, size);

                for (int i = 0; i < size - 2; i++)
                {
                    first_part += a[i];
                    second_part = 0;
                    for (int j = i + 1; j < size - 1; j++)
                    {
                        second_part += a[j];
                        // check first_part == second_part && first_part == sum - first_part - second_part
                        if (first_part == second_part && first_part == sum - first_part - second_part)
                        {
                            ways++;
                        }
                    }
                }
                return ways;
            }

            int timedReading(int maxLength, string text)
            {
                if (maxLength == 1)
                    return 0;

                int count = 0;
                vector<string> strVec;
                stringstream ss(text);
                string word;
                while (ss >> word)
                {
                    strVec.push_back(word);
                }

                for (string s : strVec)
                {
                    supportedFunctions::rmFirst(s);
                    supportedFunctions::rmLast(s);
                    if (s.length() <= maxLength)
                        count++;
                }
                return count;
            }
        };

        struct Mirror_Lake
        {
            /*
                Given an array of strings, return another array containing all of its longest strings.
                Example
                    For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
                    allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
            */
            vector<string> allLongestStrings(vector<string> inputArray)
            {
                vector<string> list{};
                int max_len = inputArray[0].length();
                for (string str : inputArray)
                {
                    if (str.length() > max_len)
                    {
                        max_len = str.length();
                        list = {};
                        list.push_back(str);
                    }
                    else
                    {
                        if (str.length() == max_len)
                        {
                            list.push_back(str);
                        }
                    }
                }
                supportedFunctions::Print(list);
                return list;
            }

            /*
                Given a string consisting of lowercase English letters,
                find the largest square number which can be obtained
                by reordering the string's characters and replacing them with any digits you need (leading zeros are not allowed)
                where same characters always map to the same digits and different characters always map to different digits.

                If there is no solution, return -1.

                Example

                For s = "ab", the output should be
                constructSquare(s) = 81.
                The largest 2 - digit square number with different digits is 81.
                For s = "zzz", the output should be
                constructSquare(s) = -1.
                There are no 3 - digit square numbers with identical digits.
                For s = "aba", the output should be
                constructSquare(s) = 900.
                It can be obtained after reordering the initial string into "baa" and replacing "a" with 0 and "b" with 9.


                Algorithm:


                Take a look:
                1: 1 - 9                  {1 - 2 - 3} - {1, 4, 9}
                2: 10 - 99                {4 - ... - 9} - {16 - ... - 81}
                3: 100 - 999              {10 - ... - 31 }- {100 - ... - 961 }
                4: 1000 - 9999		  {32 - ... - 99 } - { 1024 - ... - 9801 }
                5: 10000 - 99999	  {100 - ... - 316 } - { 10000 - ... - 99856}
                6: 100000 - 999999	  {317 - ... - 999 } - { 100489 - ... - 998001 }
                7: 1000000 - 9999999      {1000 - ... - 3162 } - { 1000000 - .......... - 9998244}
                8: 10000000 - 99999999	  {3163 - ... - 9999 } - { 10004569 - ......... - 99980001}
                9: 100000000 - 999999999  {10000 - ... - 31622 } - { 100000000 - ........ - 999950884}

                We can se the bottom_limit of n_digits (n % 2 != 0) always equal sqrt(pow(10,n_digits - 1));

                example:
                s = "aaaabbcde" => sort(s) = "11124" (sorting by numbers of letter)
                digits of string = 9
                => top_limit = 31623 (in lone of 9 digits == ceil(sqrt(pow(10,digit_of_string)));
                ==> ceil(sqrt(1000000000)) => ceil(31622.7766017) => 31623
                => bottom_limit = 9999 (in line of 8 digits) == floor(sqrt(pow(10,digit_of_string - 1) - 1);
                ==> ceil(sqrt(100000000) - 1) => ceil(10000 - 1) = 9999



                finding square_number from top to bottom (because we find largest square number)
                loop
                {
                square_number = top_limit*top_limit;
                string sq_number = to_string(square_number);
                sort(sq_number)
                if (sort(s) == sort(sq_number)
                {
                    return square_number;
                }
                }
                return -1;
            */
            int constructSquare(std::string s)
            {
                int square_upper_limit = ceil(sqrt(pow(10, s.length())));          // 10
                int square_below_limit = floor(sqrt(pow(10, s.length() - 1) - 1)); // 99
                vector<int> vs = supportedFunctions::format(s);

                std::cout << "upper_limit: " << square_upper_limit << "\n";
                std::cout << "bottom_limit: " << square_below_limit << "\n";

                for (int num = square_upper_limit; num >= square_below_limit; num--)
                {
                    long long res = num;
                    res *= res;
                    stringstream ss;
                    ss << res;
                    string t = ss.str();
                    vector<int> vt = supportedFunctions::format(t);
                    if (vs.size() == vt.size())
                    {
                        bool equal = true;
                        for (int i = 0; i < vs.size(); i++)
                        {
                            if (vs[i] != vt[i])
                            {
                                equal = false;
                                break;
                            }
                        }
                        if (equal)
                            return res;
                    }
                }
                return -1;
            }

            /*
                You are given two strings sand t of the same length, consisting of uppercase English letters.
                Your task is to find the minimum number of "replacement operations" needed to get some anagram of the string t from the string s.
                A replacement operation is performed by picking exactly one character from the string s and replacing it by some other character.

                Example

                For s = "AABAA" and t = "BBAAA", the output should be
                createAnagram(s, t) = 1;
                For s = "OVGHK" and t = "RPGUC", the output should be
                createAnagram(s, t) = 4.



                Algorithm:
                s1: A - 4 | B - 1
                s2: A - 3 | B - 2

                we can see that if we replace B of s2 by A of s2 -> we can have a string which was built from s1 when we arrange s1.

                it means we can find the max of difference between 2 string (s1 -> s2) -- they all are the same length. so don't worry about the length of them.
                -------------------
                difference_s = [s1(A) > s2(A) ? count_s1(A) - count_s2(A) : 0) + s1(B) > s2(B) ? count_s1(B) - count_s2(B) : 0)]
            */
            int createAnagram(std::string s, std::string t)
            {
                if (s == t)
                    return 0;
                std::vector<char> saved_letter;
                int step = 0;
                int difference_s = 0;
                for (char c : s)
                {
                    if (std::find(saved_letter.begin(), saved_letter.end(), c) == saved_letter.end())
                    {
                        saved_letter.push_back(c);
                        // std::cout << "Going here!\n";
                        int count_s = std::count(s.begin(), s.end(), c);
                        int count_t = std::count(t.begin(), t.end(), c);

                        if (count_s > count_t)
                        {
                            std::cout << "step:" << step++ << " letter: " << c << " -- ";
                            std::cout << "count_s: " << count_s << " - count_t: " << count_t << "\n";
                            difference_s += count_s - count_t;
                            std::cout << "difference: " << difference_s << std::endl;
                        }
                    }
                }
                return difference_s;
            }

            /*Given a rectangular matrix containing only digits, calculate the number of different 2 × 2 squares in it.*/
            int differentSquares(vector<vector<int>> matrix)
            {
                int ROW = matrix.size() - 1;
                int COL = matrix[0].size() - 1;

                set<string> square_set;

                for (int rows = 0; rows < ROW; rows++)
                {
                    for (int cols = 0; cols < COL; cols++)
                    {
                        string temp = to_string(matrix[rows][cols]) + to_string(matrix[rows + 1][cols]) + to_string(matrix[rows][cols + 1]) + to_string(matrix[rows + 1][cols + 1]);
                        square_set.insert(temp);
                    }
                }

                return square_set.size();
            }

            /*
                A boy is walking a long way from school to his home.To make the walk more fun he decides to add up all the numbers of the houses
                that he passes by during his walk.Unfortunately, not all of the houses have numbers written on them,
                and on top of that the boy is regularly taking turns to change streets, so the numbers don't appear to him in any particular order.

                At some point during the walk the boy encounters a house with number 0 written on it,
                which surprises him so much that he stops adding numbers to his total right after seeing that house.

                For the given sequence of houses determine the sum that the boy will get.
                It is guaranteed that there will always be at least one 0 house on the path.

                Example
                    For inputArray = [5, 1, 2, 3, 0, 1, 5, 0, 2], the output should be
                    houseNumbersSum(inputArray) = 11.
                The answer was obtained as 5 + 1 + 2 + 3 = 11.
            */
            int houseNumbersSum(vector<int> inputArray)
            {
                int res = 0;
                for (int i : inputArray)
                {
                    if (i == 0)
                        return res;
                    res += i;
                }
                return res;
            }

            /*
                A ciphertext alphabet is obtained from the plaintext alphabet by means of rearranging some characters.
                For example "bacdef...xyz" will be a simple ciphertext alphabet where a and b are rearranged.

                A substitution cipher is a method of encoding where each letter of the plaintext alphabet is replaced with the corresponding
                (i.e.having the same index) letter of some ciphertext alphabet.

                Given two strings, check whether it is possible to obtain them from each other using some(possibly, different) substitution ciphers.

                Example:

                For string1 = "aacb"and string2 = "aabc", the output should be
                isSubstitutionCipher(string1, string2) = true.

                Any ciphertext alphabet that starts with acb... would make this transformation possible.

                For string1 = "aa" and string2 = "bc", the output should be
                isSubstitutionCipher(string1, string2) = false.
            */
            bool isSubstitutionCipher(string string1, string string2)
            {
                supportedFunctions::CipherValue Message_Value[26];
                if (string1 == string2)
                    return true;

                int index = 0;
                int index_Mess = 0;
                const int length = string1.length();

                for (; index < length; index++)
                {
                    int in = 0;
                    // checking reversing from string2 -> string1[index] != message_value[j] ==> return false;
                    // str1 = "aabb"
                    // str2 = "aabc"
                    // => reference from str1 to str2 => b have 2 values --> false
                    for (int j = 0; j < index_Mess; j++)
                    {
                        if (string1[index] == Message_Value[j].key)
                        {
                            in++;
                            if (Message_Value[j].value != string2[index])
                                return false;
                        }
                    }
                    if (in == 0)
                    {
                        // checking reversing from string2 -> string2[index] != message_value[j] ==> return false;
                        // str1 = "aabc"
                        // str2 = "aabb"
                        // => reference from str2 to str1 => b have 2 key --> false
                        for (int j = 0; j < index_Mess; j++)
                        {
                            if (string2[index] == Message_Value[j].value)
                            {
                                if (string1[index] != Message_Value[j].key)
                                    return false;
                            }
                        }
                        Message_Value[index_Mess].key = string1[index];
                        Message_Value[index_Mess].value = string2[index];
                        index_Mess++;
                    }
                }

                return true;
            }

            /*
             * A step(x) operation works like this: it changes a number x into x - s(x), where s(x) is the sum of x's digits.
             * You like applying functions to numbers, so given the number n, you decide to build a decreasing sequence of numbers:
             * n, step(n), step(step(n)), etc., with 0 as the last element.
             *
             * Building a single sequence isn't enough for you, so you replace all elements of the sequence with the sums of their digits (s(x)).
             * Now you're curious as to which number appears in the new sequence most often. If there are several answers, return the maximal one.
             *
             * Example
             *
             * For n = 88, the output should be mostFrequentDigitSum(n) = 9.
             *
             * Here is the first sequence you built: 88, 72, 63, 54, 45, 36, 27, 18, 9, 0;
             * And here is s(x) for each of its elements: 16, 9, 9, 9, 9, 9, 9, 9, 9, 0.
             * As you can see, the most frequent number in the second sequence is 9.
             * For n = 8, the output should be
             * mostFrequentDigitSum(n) = 8.
             * At first you built the following sequence: 8, 0
             * s(x) for each of its elements is: 8, 0
             * As you can see, the answer is 8 (it appears as often as 0, but is greater than it).
             */
            int mostFrequentDigitSum(int n)
            {
                vector<int> step_n = supportedFunctions::step(n);
                vector<int> step_sum_n;

                for (int index = 0; index < step_n.size(); index++)
                {
                    step_sum_n.push_back(supportedFunctions::s(step_n[index]));
                }

                map<int, int> mp;
                for (int i = 0; i < step_sum_n.size(); i++)
                {
                    mp[step_sum_n[i]]++;
                }
                return supportedFunctions::findMax(mp);
            }

            /*
                Let's call two integers A and B friends
                if each integer from the array divisors is either a divisor of both A and B or neither A nor B.
                If two integers are friends, they are said to be in the same clan.
                How many clans are the integers from 1 to k, inclusive, broken into?

                Example
                    For divisors = [2, 3] and k = 6, the output should be
                    numberOfClans(divisors, k) = 4.
                The numbers 1 and 5 are friends and form a clan,
                2 and 4 are friends and form a clan,
                and 3 and 6 do not have friendsand each is a clan by itself.
                So the numbers 1 through 6 are broken into 4 clans.*/
            int numberOfClans(vector<int> divisors, int k)
            {
                set<string> div_set;
                int len = divisors.size();

                for (int i = 1; i <= k; i++)
                {
                    string num_div = "1";

                    for (int j = 0; j < len; j++)
                    {
                        if (i % divisors[j] == 0)
                            num_div += to_string(divisors[j]);
                    }
                    std::cout << num_div << "\n";
                    div_set.insert(num_div);
                }

                return div_set.size();
            }

            /*
                You are given an array of integers that you want distribute between several groups.
                The first group should contain numbers from 1 to 104,
                the second should contain those from 104 + 1 to 2 * 104, ...,
                the 100th one should contain numbers from 99 * 104 + 1 to 106 and so on.

                All the numbers will then be written down in groups to the text file in such a way that:

                the groups go one after another;
                each non-empty group has a header which occupies one line;
                each number in a group occupies one line.
                Calculate how many lines the resulting text file will have.

                Example

                For a = [20000, 239, 10001, 999999, 10000, 20566, 29999], the output should be
                numbersGrouping(a) = 11.

                The numbers can be divided into 4 groups:

                239 and 10000 go to the 1st group (1 ... 104);
                10001 and 20000 go to the second 2nd (104 + 1 ... 2 * 104);
                20566 and 29999 go to the 3rd group (2 * 104 + 1 ... 3 * 104);
                groups from 4 to 99 are empty;
                999999 goes to the 100th group (99 * 104 + 1 ... 106).
                Thus, there will be 4 groups (i.e. four headers) and 7 numbers, so the file will occupy 4 + 7 = 11 lines.


                vector<int> a = {
                        629331440, 494232287, 136272236, 273050203, 434470602, 578856790, 415897234, 966510740, 460572448,
                        390601670, 656646086, 990687321, 94779681, 439389814, 621806166, 389349001, 619737138, 72112342, 943964832, 209248844,
                        410529154, 179744122, 109498075, 470133382, 384808947, 265438855, 957869901, 198106795, 369266892, 373181217, 285933178,
                        404144322, 177314269, 868322471, 966591040, 210800389, 948207480, 938683342, 508844544, 444923069, 450556727, 354970474,
                        969260313, 670387566, 199153186, 321033095, 50409663, 722374610, 578470832, 123616739, 39278224, 323213274, 908279195,
                        429594353, 563038045, 499215908, 637318359, 597941946, 925217519, 615157350, 818984131, 502451407, 951625218, 177425017,
                        614671069, 492546513, 431972731, 974981867, 438550378, 969803542, 111214977, 705287873, 697346808, 980965347, 256156127,
                        183254413, 315410288, 710199567, 1257361, 732631481, 719752645, 711132059, 773404229, 394266157, 640920785, 607172585,
                        214329305, 844989000, 880094155, 22115870, 935012242, 228822777, 16224959, 711171706, 37406857, 980125095, 246102805,
                        990976248, 474483642, 393584803
                        };

                output have to be 200
            */
            int numbersGrouping(vector<int> a)
            {
                set<int> list;

                for (auto element : a)
                    list.insert((element - 1) / range);

                return list.size() + a.size();
            }

            /*
                Given two strings a and b, both consisting only of lowercase English letters,
                your task is to calculate how many strings equal to a can be constructed using only letters from the string b?
                Each letter can be used only once and in one string only.

                Example

                For a = "abc" and b = "abccba", the output should be stringsConstruction(a, b) = 2.

                We can construct 2 strings a = "abc" using only letters from the string b.

                For a = "ab" and b = "abcbcb", the output should be stringsConstruction(a, b) = 1.

                Algorithm:
                give: s1 = "abcdd" ---- s2 = "abcddcbadcad"
                -->recorgnize:
                s1 --> a : 1 | b : 1 | c : 1 | d : 2
                s2 --> a : 3 | b : 2 | c : 3 | d : 4

                if we build first string of s1 from s2 => a : 2 | b : 1 | c : 2 | d : 2 
                => we can build the second one -s2--> a : 2 | b : 0 | c : 1 | d : 0

                ==> We can see that output of this problem is ---- min[a(s1)/a(s2);b(s1)/b(s2);c(s1)/c(s2);d(s1)/d(s2)]
                from above example:
                output = Min[3/1;2/1;3/1;4/2] = Min[3,2,3,2] => Min is 2 => we can construct 2 strings of s1 from s2;
            */
            int stringsConstruction(std::string a, std::string b)
            {
                int min = 9999;
                std::vector<char> vec_char;
                std::map<char, int> pair_ch_num_a;
                std::map<char, int> pair_ch_num_b;

                // create a vector of all letter in a
                for (char c : a)
                {
                    if (std::find(vec_char.begin(), vec_char.end(), c) == vec_char.end())
                        vec_char.push_back(c);
                }

                // Insert list of char : count_char into 2 map a and b
                // we can have min_output by this loop no need the third loop - just needing for more clearly
                for (int i = 0; i < vec_char.size(); i++)
                {
                    pair_ch_num_a.insert(std::make_pair(vec_char[i], std::count(a.begin(), a.end(), vec_char[i])));
                    pair_ch_num_b.insert(std::make_pair(vec_char[i], std::count(b.begin(), b.end(), vec_char[i])));
                }

                for (int i = 0; i < vec_char.size(); i++)
                {
                    std::cout << "#" << vec_char[i] << ":";

                    const int count_c = pair_ch_num_b[vec_char[i]] / pair_ch_num_a[vec_char[i]];
                    std::cout << pair_ch_num_a[vec_char[i]] << "--" << pair_ch_num_b[vec_char[i]] << " count = " << count_c << " \n";
                    if (count_c < min)
                        min = count_c;
                }
                std::cout << "\n";
                return min;
            }

            /**
             * @brief 
             *      It's Christmas time! To share his Christmas spirit with all his friends, 
             *      the young Christmas Elf decided to send each of them a Christmas e-mail with a nice Christmas tree. 
             *      Unfortunately, Internet traffic is very expensive in the North Pole, 
             *      so instead of sending an actual image he got creative and drew the tree using nothing but asterisks ('*' symbols). 
             *      He has given you the specs (see below) and your task is to write a program that will generate trees following the spec and some initial parameters.
             * 
             *      Each tree has a crown as follows:
             *              *
             *              *
             *            * * *
             * 
             *      Define a line as a horizontal group of asterisks and a level as a collection of levelHeight lines stacked one on top of the other.
             *      
             *      Below the crown there are levelNum levels.
             *      The tree is perfectly symmetrical so all the middle asterisks of the lines lie on the center of the tree.
             *      Each line of the same level (excluding the first one) has two more asterisks than the previous one (one added to each end);
             *      The number of asterisks in the first line of each level is chosen as follows:
             *          the first line of the first level has 5 asterisks;
             *          the first line of each consecutive level contains two more asterisks than the first line of the previous level.
             *      
             *      And finally there is the tree foot which has a height of levelNum and a width of:
             *          levelHeight asterisks if levelHeight is odd;
             *          levelHeight + 1 asterisks if levelHeight is even.
             *  
             * @param levelNum the level number of tree
             * @param levelHeight the height of level
             * @return vector<string> return the christmas tree
             */
            vector<string> solution(int levelNum, int levelHeight) {
                int start = 5;
                int levelTemp = 1;
                vector<string> result;
                // Making header
                do {
                    std::string space = std::string(levelHeight + levelNum ,' ');
                    result.push_back(space +  "*");
                    result.push_back(space +  "*");
                    space = std::string(levelHeight + levelNum - 1,' ');
                    result.push_back(space +  "***");
                } while (0);

                // Making body
                int remain = levelNum;                      // Checking how many level we will build
                do {
                    int temp = start;                               // Starting with the value of 5 asterisks 
                    int tempspace = levelHeight - 1;                // Temspace is the spacing for building line
                    for (int i = 0; i < levelHeight; ++i) {    
                        std::string space = std::string(tempspace + remain - 1, ' ');
                        std::string stuff(temp, '*');      // start of the level of body
                        std::cout << "space + stuff: " << space + stuff << std::endl;
                        result.push_back(space + stuff);

                        temp += 2;
                        tempspace--;

                    }
                    start += 2;
                    levelTemp++;
                    remain--;
                } while (levelTemp <= levelNum);
                

                // Making footer
                if (levelHeight % 2 == 0) {
                    for (int i = 0; i < levelNum; ++i) {
                        std::string spacing(levelHeight, ' ');
                        std::string stuff(levelHeight + 1, '*');
                        result.push_back(spacing + stuff);
                    }
                }
                else {
                    for (int i = 0; i < levelNum; ++i) {
                        std::string spacing(levelHeight, ' ');
                        std::string stuff(levelHeight, '*');
                        result.push_back(spacing + stuff);
                    }
                }
                return result;
            }
        };
    };
}

#endif
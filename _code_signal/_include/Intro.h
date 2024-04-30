#include "supportedFunction.h"

namespace codeSignalProblems
{
    class Intro
    {
    public:
        /**
         * @brief Construct a new Intro object
         *
         */
        Intro() {}

        /**
         * @brief Destroy the Intro object
         *
         */
        ~Intro() {}

        struct Dark_Wilderness
        {
            /**
             * @brief
             * Given the positions of a white bishopand a black pawn on the standard chess board,
             * determine whether the bishop can capture the pawn in one move.
             * The bishop has no restrictions in distance for each move,
             * but is limited to diagonal movement.Check out the example below to see how it can move :
             *
             * @param bishop
             * @param pawn
             * @return true
             * @return false
             */
            bool bishopAndPawn(std::string bishop, std::string pawn)
            {

                int Pos_Bishop = (int)(bishop[0] + (int)bishop[1]);
                int Pos_Pawn = (int)(pawn[0] + pawn[1]);
                // in the main Diagonal
                if (Pos_Bishop == Pos_Pawn)
                {
                    return true;
                }
                // in the sub-Diagonal
                Pos_Bishop = (int)(bishop[0] - bishop[1]);
                Pos_Pawn = (int)(pawn[0] - pawn[1]);
                if (Pos_Bishop == Pos_Pawn)
                    return true;
                return false;
            }

            /**
             * @brief
             * Caring for a plant can be hard work, but since you tend to it regularly, you have a plant that grows consistently.
             * Each day, its height increases by a fixed amount represented by the integer upSpeed.But due to lack of sunlight,
             * the plant decreases in height every night, by an amount represented by downSpeed.
             *
             * Since you grew the plant from a seed, it started at height 0 initially.
             * Given an integer desiredHeight, your task is to find how many days it'll take for the plant to reach this height.
             *
             * Example:
             * For upSpeed = 100, downSpeed = 10, and desiredHeight = 910, the output should be
             * growingPlant(upSpeed, downSpeed, desiredHeight) = 10.
             *
             * #		Day	Night
             * 1		100	90
             * 2		190	180
             * 3		280	270
             * 4		370	360
             * 5		460	450
             * 6		550	540
             * 7		640	630
             * 8		730	720
             * 9		820	810
             * 10	    910	900
             * The plant first reaches a height of 910 on day 10.
             *
             * @param upSpeed
             * @param downSpeed
             * @param desiredHeight
             * @return int
             */
            int growingPlant(int upSpeed, int downSpeed, int desiredHeight)
            {
                int day = 0;
                int _Day_value = 0;
                int _Night_value = 0;

                do
                {
                    day++;
                    _Day_value = upSpeed + _Night_value;
                    _Night_value = _Day_value - downSpeed;
                    std::cout << "Day: " << day << " -> _Day_value: " << _Day_value << " -> _Night_value: " << _Night_value << std::endl;
                } while (_Day_value < desiredHeight);

                return day;
            }

            /**
             * @brief
             * Let's define digit degree of some positive integer as the number of times
             * we need to replace this number with the sum of its digits until we get to a one digit number.
             *
             * Given an integer, find its digit degree.
             *
             * For n = 5, the output should be
             * digitDegree(n) = 0;
             * For n = 100, the output should be
             * digitDegree(n) = 1.
             * 1 + 0 + 0 = 1.
             * For n = 91, the output should be
             * digitDegree(n) = 2.
             * 9 + 1 = 10 -> 1 + 0 = 1.
             *
             *
             * @param n
             * @return int
             */
            int digitDegree(int n)
            {
                int count = 0;
                int sum = n;
                if (n < 10)
                {
                    return 0;
                }
                while (sum >= 10)
                {
                    int temp_sum = 0;
                    int div = sum;
                    while (div > 0)
                    {
                        int temp = div % 10;
                        temp_sum = temp_sum + temp;
                        div = div / 10;
                    }

                    count++;
                    sum = temp_sum;
                }

                return count;
            }

            /**
             * @brief
             * You found two items in a treasure chest!The first item weighs weight1and is worth value1,
             * and the second item weighs weight2and is worth value2.What is the total maximum value of the items you can take with you,
             * assuming that your max weight capacity is maxWand you can't come back for the items later?
             *
             *
             * Note that there are only two items and you can't bring more than one item of each type,
             * i.e. you can't take two first items or two second items.
             * ----------------------------------------------------------------
             * Example:
             * For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 8, the output should be
             * knapsackLight(value1, weight1, value2, weight2, maxW) = 10.
             *
             * You can only carry the first item.
             * ----------------------------------------------------------------
             * For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 9, the output should be
             * knapsackLight(value1, weight1, value2, weight2, maxW) = 16.
             *
             * You're strong enough to take both of the items with you.
             * ----------------------------------------------------------------
             * For value1 = 5, weight1 = 3, value2 = 7, weight2 = 4, and maxW = 6, the output should be
             * knapsackLight(value1, weight1, value2, weight2, maxW) = 7.
             *
             * You can't take both items, but you can take any of them.
             *
             * @param value1
             * @param weight1
             * @param value2
             * @param weight2
             * @param maxW
             * @return int
             */
            int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW)
            {
                if (maxW < weight1 && maxW < weight2)
                    return 0;

                if (maxW < (weight1 + weight2))
                {
                    if (maxW >= weight1 && maxW < weight2)
                    {
                        return value1;
                    }
                    else
                    {
                        if (maxW >= weight2 && maxW < weight1)
                        {
                            return value2;
                        }
                        else
                        {
                            return value1 > value2 ? value1 : value2;
                        }
                    }
                }

                if (maxW >= (weight1 + weight2))
                    return value1 + value2;
            }

            /**
             * @brief
             * Given a string, output its longest prefix which contains only digits.
             *
             * Example:
             * For inputString = "123aa1", the output should be
             * longestDigitsPrefix(inputString) = "123"
             *
             * @param inputString
             * @return std::string
             */
            std::string longestDigitsPrefix(std::string inputString)
            {
                std::string res;
                if (inputString[0] < 48 && inputString[0] > 57)
                {
                    return res;
                }

                int i = 0;
                while (inputString[i] >= 48 && inputString[i] <= 57)
                {
                    res.push_back(inputString[i]);
                    i++;
                }

                return res;
            }
        };

        struct Diving_Deep
        {
            int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k)
            {
                int max = 0;

                for (int i = 0; i <= inputArray.size() - k; i++)
                {
                    int index = i;
                    int j = 0;
                    int sum = 0;
                    while (j < k)
                    {
                        sum += inputArray[index];
                        j++;
                        index++;
                    }
                    if (max < sum)
                    {
                        max = sum;
                    }
                }
                return max;
            }

            int differentSymbolsNaive(std::string s)
            {
                std::vector<char> char_vec;
                int count = 0;
                for (size_t i = 0; i < s.size(); i++)
                {
                    if (std::find(char_vec.begin(), char_vec.end(), s[i]) == char_vec.end())
                    {
                        char_vec.push_back(s[i]);
                        count++;
                    }
                }
                return count;
            }

            std::vector<int> extractEachKth(std::vector<int> &inputArray, int k)
            {
                int jum = k - 1;
                while (jum < inputArray.size())
                {
                    std::cout << "We already removed this value: " << inputArray[jum] << "\n";
                    for (int i = jum; i < inputArray.size() - 1; i++)
                    {
                        int j = i + 1;
                        inputArray[i] = inputArray[j];
                    }
                    inputArray.pop_back();
                    if (inputArray.size() - 1 == 0)
                    {
                        inputArray.pop_back();
                        break;
                    }
                    jum = jum + (k - 1);
                }

                return inputArray;
            }

            char firstDigit(std::string inputString)
            {
                char numb = NULL;
                for (int i = 0; i < inputString.length(); i++)
                {
                    int value_i = inputString[i];
                    std::cout << value_i << " is letter " << inputString[i] << std::endl;
                    if (value_i >= 48 && value_i <= 57)
                    {
                        numb = inputString[i];
                        break;
                    }
                }

                return numb;
            }
        };

        struct Explore_The_Waters
        {
            /**
             * Given a rectangular matrix of characters, add a border of asterisks(*) to it.
             * Example
             * For
             *      picture =   ["abc", //size of pic = 2;
             *                  "ded"] //size of pic[i] = 3;
             *
             * the output should be:
             *      addBorder(picture) = ["*****", //size of picture = 4; if row == 0 => push all '*'
                                        "*abc*", //size of picture[i] = 5; if cols == 0 or cols == picture[i].leng() - 1 => push('*');
                                        "*ded*",
                                        "*****"] // if rows == picture.size() - 1 => string pushes all '*'
            */
            std::vector<std::string> addBorder(std::vector<std::string> picture)
            {

                std::vector<std::string> output;
                int size_push = picture.size();
                int size_pop = picture.size() + 2;
                std::vector<char> temp_char;
                int pos = 0;
                // push characters in vetor;
                for (int i = 0; i < size_push; i++)
                {
                    int len = picture[i].length();
                    for (int j = 0; j < len; j++)
                    {
                        temp_char.push_back(picture[i][j]);
                    }
                }

                // printing to check
                for (int i = 0; i < temp_char.size(); i++)
                {
                    std::cout << temp_char[i] << " ";
                }
                std::cout << std::endl;

                // assign to output:
                for (int i = 0; i < size_pop; i++)
                {
                    int len = picture[0].length() + 2; // take a length of all
                    std::string temp_str;
                    for (int j = 0; j < len; j++)
                    {
                        if (i == 0 || i == size_pop - 1)
                        {
                            temp_str.push_back('*');
                        }
                        else
                        {
                            // if j == 0 or len - 1 => strig is '*'
                            if (j == 0 || j == len - 1)
                            {
                                temp_str.push_back('*');
                            }
                            else
                            {
                                temp_str.push_back(temp_char[pos]);
                                pos++;
                            }
                        }
                    }
                    output.push_back(temp_str);
                }
                // print output to check:
                for (int i = 0; i < output.size(); i++)
                {
                    std::cout << output[i] << std::endl;
                }
                std::cout << std::endl;

                return output;
            }

            /**
             * @brief
             *
                Several people are standing in a rowand need to be divided into two teams.
                The first person goes into team 1, the second goes into team 2, the third goes into team 1 again, the fourth into team 2, and so on.
                You are given an array of positive integers - the weights of the people.
                Return an array of two integers, where the first element is the total weight of team 1, and the second element is the total weight of team 2 after the division is complete.

                Example
                    For a = [50, 60, 60, 45, 70], the output should be

                        alternatingSums(a) = [180, 105].

             * @param a
             * @return std::vector<int>
             */
            std::vector<int> alternatingSums(std::vector<int> a)
            {
                int size = a.size();
                int Team1_point = 0;
                int Team2_point = 0;
                std::vector<int> output;
                for (int i = 0; i < size; i++)
                {
                    if (i % 2 == 0)
                    {
                        Team1_point += a[i];
                    }
                    else
                    {
                        Team2_point += a[i];
                    }
                }
                output.push_back(Team1_point);
                output.push_back(Team2_point);

                return output;
            }

            /**
             * @brief
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
            bool areSimilar(std::vector<int> a, std::vector<int> b)
            {

                bool sim = false;

                // identify position with not similar elems
                std::vector<int> notSimPos;
                for (int i = 0; i < a.size(); ++i)
                {
                    if (a[i] != b[i])
                        notSimPos.push_back(i);
                }
                // if two, compare swapwise
                if (notSimPos.size() == 0)
                {
                    sim = true;
                }
                else if (notSimPos.size() == 2)
                {
                    if (a[notSimPos[0]] == b[notSimPos[1]] && b[notSimPos[0]] == a[notSimPos[1]])
                    {
                        sim = true;
                    }
                }

                return sim;
            }

            /**
             * @brief
             *      You are given an array of integers.On each move you are
                    allowed to increase exactly one of its element by one.
                    Find the minimal number of moves required to obtain a strictly increasing sequence from the input.
                    Example
                        For inputArray = [1, 1, 1], the output should be
                        arrayChange(inputArray) = 3.
             */
            int arrayChange(std::vector<int> inputArray)
            {
                int count = 0;
                int size = inputArray.size();

                for (int i = 1; i < size; i++)
                {
                    while (inputArray[i] <= inputArray[i - 1])
                    {
                        inputArray[i]++;
                        count++;
                    }
                }
                return count;
            }

            /**
             * @brief
             * Given a string, find out if its characters can be rearranged to form a palindrome.
             *      Example
             *          For inputString = "aabb", the output should be
             *          palindromeRearranging(inputString) = true.
             *          We can rearrange "aabb" to make "abba", which is a palindrome.
             *
             * Algorithm:
             *  A set of characters can form a palindrome if at most one character occurs odd number of times and all characters occur even number of times.
             *  A simple solution is to run two loops, the outer loop picks all characters one by one, the inner loop counts number of occurrences of the picked character.
             *  We keep track of odd counts. Time complexity of this solution is O(n2).
             *
             *  We can do it in O(n) time using a count array. Following are detailed steps.
             *  1) Create a count array of alphabet size which is typically 256. Initialize all values of count array as 0.
             *  2) Traverse the given string and increment count of every character.
             *  3) Traverse the count array and if the count array has more than one odd values, return false. Otherwise return true.
             */
            bool palindromeRearranging(std::string inputString)
            {
                int found_odd = 0;
                // finding count off all characters in string
                for (int i = 0; i < 25; i++)
                {
                    char c = 'a' + i;
                    auto count = std::count(inputString.begin(), inputString.end(), c);

                    if (count % 2 != 0)
                    {
                        found_odd++;
                    }
                    if (found_odd > 1)
                    {
                        return false;
                    }
                }
                return true;
            }
        };

        struct Island_Of_Knowledge
        {
            /*

            Call two arms equally strong if the heaviest weights they each are able to lift are equal.
            Call two people equally strong if their strongest arms are equally strong(the strongest arm can be both the right and the left),
            and so are their weakest arms.

            Given yourand your friend's arms' lifting capabilities find out if you two are equally strong.

            Example
                For yourLeft = 10, yourRight = 15, friendsLeft = 15, and friendsRight = 10, the output should be
                    areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true;
                For yourLeft = 15, yourRight = 10, friendsLeft = 15, and friendsRight = 10, the output should be
                    areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true;
                For yourLeft = 15, yourRight = 10, friendsLeft = 15, and friendsRight = 9, the output should be
                    areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = false.
            */
            bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight)
            {
                int my_weakest = yourLeft < yourRight ? yourLeft : yourRight;
                int my_strongest = yourLeft > yourRight ? yourLeft : yourRight;
                int myfriend_weakest = friendsLeft < friendsRight ? friendsLeft : friendsRight;
                int myfriend_strongest = friendsLeft > friendsRight ? friendsLeft : friendsRight;
                std::cout << "My Strongest Arm: " << my_strongest << std::endl;
                std::cout << "My weakest Arm: " << my_weakest << std::endl;
                std::cout << "My friend's Strongest Arm: " << myfriend_strongest << std::endl;
                std::cout << "My friend's weakest Arm: " << myfriend_weakest << std::endl;

                if (my_strongest == myfriend_strongest && my_weakest == myfriend_weakest)
                {
                    return true;
                }
                return false;
            }

            /*
                Given an array of integers, find the maximal absolute difference between any two of its adjacent elements.

                Example

                For inputArray = [2, 4, 1, 0], the output should be
                    arrayMaximalAdjacentDifference(inputArray) = 3.
            */
            int arrayMaximalAdjacentDifference(std::vector<int> inputArray)
            {
                int size = inputArray.size();
                int max = -9;
                int dems;
                for (int i = 1; i < size; i++)
                {
                    if (inputArray[i] > inputArray[i - 1])
                    {
                        dems = inputArray[i] - inputArray[i - 1];
                    }
                    else
                    {
                        dems = inputArray[i - 1] - inputArray[i];
                    }

                    if (dems > max)
                    {
                        max = dems;
                    }
                }
                return max;
            }

            /*
                You are given an array of integers representing coordinates of obstacles situated on a straight line.
                Assume that you are jumping from the point with coordinate 0 to the right.
                You are allowed only to make jumps of the same length represented by some integer.

                Find the minimal length of the jump enough to avoid all the obstacles.

                Example
                    For inputArray = [5, 3, 6, 7, 9], the output should be
                        avoidObstacles(inputArray) = 4.
            */
            int avoidObstacles(std::vector<int> inputArray)
            {
                int step = 0;
                bool isExist = true;
                int max = *max_element(inputArray.begin(), inputArray.end());
                do
                {
                    step = step + 1;
                    for (int i = 0; i <= max; i = i + step)
                    {
                        if (find(inputArray.begin(), inputArray.end(), i) != inputArray.end())
                        {
                            isExist = true;
                            break;
                        }
                        else
                        {
                            isExist = false;
                        }
                    }
                } while (isExist == true);

                if (isExist == false)
                {
                    return step;
                }
            }

            std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image)
            {
                int max_rows = image.size() - 2;
                int rows = 0;
                int max_cols = image[0].size() - 2;
                std::vector<std::vector<int>> image_output;
                while (rows < max_rows)
                {
                    int cols = 0;
                    int rows_max = rows + 3;
                    std::vector<int> temp;
                    while (cols < max_cols)
                    {
                        int sum = 0;
                        int cols_max = cols + 3;
                        int accomulation = 0;
                        for (int i = rows; i < rows_max; i++)
                        {
                            for (int j = cols; j < cols_max; j++)
                            {
                                accomulation += image[i][j];
                            }
                        }
                        sum = accomulation / 9;
                        temp.push_back(sum);
                        cols++;
                    }
                    image_output.push_back(temp);
                    rows++;
                }
                return image_output;
            }

            /*

                An IP address is a numerical label assigned to each device(e.g., computer, printer)
                participating in a computer network that uses the Internet Protocol for communication.
                There are two versions of the Internet protocol, and thus two versions of addresses. One of them is the IPv4 address.

                Given a string, find out if it satisfies the IPv4 address naming rules.

                Example
                    For inputString = "172.16.254.1", the output should be
                        isIPv4Address(inputString) = true;

                    For inputString = "172.316.254.1", the output should be
                        isIPv4Address(inputString) = false.
                        -> 316 is not in range[0, 255].

                    For inputString = ".254.255.0", the output should be
                        isIPv4Address(inputString) = false.
                        -> There is no first number.

            */
            bool isIPv4Address(std::string inputString)
            {
                for (auto c : inputString)
                { // element of strings have to get from 0 - 9 and also have dots if without it -> return false
                    if ((c < '0' || c > '9') && c != '.')
                    {
                        return false;
                    }
                }
                // IP could not be like this: .231.231.
                if (inputString[0] == '.' || inputString.back() == '.')
                {
                    return false;
                }

                // IP could not be like this: ..1232.21
                for (int i = 0; i < inputString.size() - 1; ++i)
                {
                    if (inputString[i] == '.' && inputString[i + 1] == '.')
                    {
                        return false;
                    }
                }

                auto numbers = supportedFunctions::get_numbers(inputString);
                if (numbers.size() != 4)
                {
                    return false;
                }
                for (auto n : numbers)
                {
                    if (n > 255)
                        return false;
                }
                return true;
            }

            std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix)
            {
                std::vector<std::vector<int>> matrix_output;
                for (int i = 0; i < matrix.size(); i++)
                {
                    std::vector<int> temp;
                    int i_up = i + 1;
                    int i_down = i - 1;
                    for (int j = 0; j < matrix[i].size(); j++)
                    {
                        int j_up = j + 1;
                        int j_down = j - 1;
                        int n = 0;
                        if (i == 0)
                        {
                            if (j == 0) // x = 0 && y = 0
                            {
                                if (matrix[i][j_up] == true)
                                    n++;
                                if (matrix[i_up][j] == true)
                                    n++;
                                if (matrix[i_up][j_up] == true)
                                    n++;
                            }
                            else if (j == matrix[i].size() - 1) // x = 0 && y = matrix[i].size() - 1
                            {
                                if (matrix[i][j_down] == true)
                                    n++;
                                if (matrix[i_up][j_down] == true)
                                    n++;
                                if (matrix[i_up][j] == true)
                                    n++;
                            }
                            else // x = 0 && (0 < y < matrix[i].size() - 1)
                            {
                                if (matrix[i][j_down] == true)
                                    n++;
                                if (matrix[i][j_up] == true)
                                    n++;
                                if (matrix[i_up][j_down] == true)
                                    n++;
                                if (matrix[i_up][j] == true)
                                    n++;
                                if (matrix[i_up][j_up] == true)
                                    n++;
                            }
                        }
                        else if (i == matrix.size() - 1) // x == matrix.size() - 1
                        {
                            if (j == 0) // y = 0
                            {
                                if (matrix[i_down][j] == true)
                                    n++;
                                if (matrix[i_down][j_up] == true)
                                    n++;
                                if (matrix[i][j_up] == true)
                                    n++;
                            }
                            else if (j == matrix[i].size() - 1) // y = matrix[i].size() - 1)
                            {
                                if (matrix[i][j_down] == true)
                                    n++;
                                if (matrix[i_down][j_down] == true)
                                    n++;
                                if (matrix[i_down][j] == true)
                                    n++;
                            }
                            else // y = 0 < y < matrix[i].size() - 1
                            {
                                if (matrix[i][j_down] == true)
                                    n++;
                                if (matrix[i][j_up] == true)
                                    n++;
                                if (matrix[i_down][j_down] == true)
                                    n++;
                                if (matrix[i_down][j] == true)
                                    n++;
                                if (matrix[i_down][j_up] == true)
                                    n++;
                            }
                        }
                        else // x  = 0 < x < matrix.size() - 1
                        {
                            if (j == 0) // y = 0
                            {
                                if (matrix[i_down][j] == true)
                                    n++;
                                if (matrix[i_up][j] == true)
                                    n++;
                                if (matrix[i_down][j_up] == true)
                                    n++;
                                if (matrix[i][j_up] == true)
                                    n++;
                                if (matrix[i_up][j_up] == true)
                                    n++;
                            }
                            else if (j == matrix[i].size() - 1) // y = matrix[i].size() - 1)
                            {
                                if (matrix[i_down][j] == true)
                                    n++;
                                if (matrix[i_down][j_down] == true)
                                    n++;
                                if (matrix[i][j_down] == true)
                                    n++;
                                if (matrix[i_up][j_down] == true)
                                    n++;
                                if (matrix[i_up][j] == true)
                                    n++;
                            }
                            else // y =  0 < y < matrix[i].size() - 1
                            {
                                if (matrix[i][j_down] == true)
                                    n++;
                                if (matrix[i][j_up] == true)
                                    n++;
                                if (matrix[i_down][j_down] == true)
                                    n++;
                                if (matrix[i_down][j] == true)
                                    n++;
                                if (matrix[i_down][j_up] == true)
                                    n++;
                                if (matrix[i_up][j_down] == true)
                                    n++;
                                if (matrix[i_up][j] == true)
                                    n++;
                                if (matrix[i_up][j_up] == true)
                                    n++;
                            }
                        }
                        temp.push_back(n);
                        std::cout << i << " : " << j << std::endl;
                    }
                    matrix_output.push_back(temp);
                }
                return matrix_output;
            }
        };

        struct Land_Of_Logic
        {
            /*
                Given a rectangular matrix containing only digits, calculate the number of different 2 × 2 squares in it.

                Example

                    For
                        matrix = [[1, 2, 1],
                                [2, 2, 2],
                                [2, 2, 2],
                                [1, 2, 3],
                                [2, 2, 1]]
                        the output should be
                    differentSquares(matrix) = 6.

            */
            int differentSquares(vector<vector<int>> matrix)
            {
                // 0. Create a hashset
                std::set<string> squareTracker;
                int ht = matrix.size();
                int wd = matrix[0].size();
                // 1. iterate left to right and up to down
                for (int up_to_down = 0; up_to_down < ht - 1; up_to_down++)
                {
                    for (int lef_to_rig = 0; lef_to_rig < wd - 1; lef_to_rig++)
                    {
                        squareTracker.insert(supportedFunctions::get2x2Window(matrix, up_to_down, lef_to_rig));
                    }
                }
                return squareTracker.size();
                // 2. capture 2x2 window of data from matrix -- String?
                //  2.1 encode it as a string val for adding into hashset
                // 3. Return size of harshset == number of diff sq
            }

            /*

            */
            int digitsProduct(int product)
            {
                std::vector<int> track;
                int res = 0;
                if (product == 0)
                {
                    return 10;
                }

                if (product > 0 && product < 10)
                {
                    return product;
                }

                supportedFunctions::Find(track, product);
                std::cout << "Size of track: " << track.size() << "\n";
                if (track.size() == 0)
                {
                    return -1;
                }
                else
                {
                    for (int i = track.size() - 1; i >= 0; i--)
                    {
                        std::cout << "Track: " << track[i] << "\n";
                        res = res + track[i];
                        res = res * 10;
                    }
                    res = res / 10;

                    if (product != 1)
                    {
                        return -1;
                    }
                    else
                    {
                        return res;
                    }
                }
            }

            /*
                Define a word as a sequence of consecutive English letters.Find the longest word from the given string.
                Example
                    For text = "Ready, steady, go!", the output should be
                    longestWord(text) = "steady".
            */
            std::string longestWord(std::string text)
            {
                std::string word = "";
                std::string longest = "";
                for (auto x : text)
                {
                    if (((x < 65 || x > 90) && (x < 97 || x > 122)))
                    {
                        word = "";
                    }
                    else
                    {
                        word += x;
                    }

                    if (word.length() > longest.length())
                    {
                        // std::cout << "word: " << word << std::endl;
                        longest = word;
                    }
                }
                std::cout << "longest word: " << longest << std::endl;
                return longest;
            }

            /*
                You are given an array of desired filenames in the order of their creation. Since two files cannot have equal names,
                the one which comes later will have an addition to its name in a form of (k),
                where k is the smallest positive integer such that the obtained name is not used yet.
                Return an array of names that will be given to the files.
                Example
                For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be
                fileNaming(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].

                    Algorithm:
                        1. we put a elemen of file names into a track(vector)
                        2. if track.empty() == true => put element right away!
                        if track.empty() != true => we need to check
                        3. check for how many elements has the same file_name in track
                        if they exist in track k = k + n (time exists)
                        => string = names[i] + (k)
                        continuing to check string = names[i] + (k), if exist => string = "names[i] + (k) + (g)";
                        4. return str_res;
            */
            vector<string> fileNaming(vector<string> names)
            {
                vector<string> res{};  // initializing a vector
                for (string s : names) // take element one by one
                {
                    // if vector of res is empty put string_element into vector right away!
                    if (res.empty())
                    {
                        res.push_back(s);
                    }
                    else
                    {
                        string temp_str;
                        int i = 0;
                        int k = 0;
                        while (i < res.size())
                        {
                            if (s == res[i])
                            {
                                k++;
                            }
                            i++;
                        }
                        if (find(res.begin(), res.end(), s) == res.end())
                        {
                            res.push_back(s);
                        }
                        else
                        {
                            do
                            {
                                string str = "(" + to_string(k) + ")";
                                temp_str = s + str;
                                k++;
                            } while (find(res.begin(), res.end(), temp_str) != res.end());

                            res.push_back(temp_str);
                        }
                    }
                }
                return res;
            }

            /*
                You are taking part in an Escape Room challenge designed specifically for programmers.
                In your efforts to find a clue, you've found a binary code written on the wall behind a vase,
                and realized that it must be an encrypted message.
                After some thought,
                your first guess is that each consecutive 8 bits of the code stand for the character with the corresponding extended ASCII code.

                Assuming that your hunch is correct, decode the message.
                Example
                    For code = "010010000110010101101100011011000110111100100001", the output should be
                    messageFromBinaryCode(code) = "Hello!".
                    The first 8 characters of the code are 01001000, which is 72 in the binary numeral system. 72 stands for H in the ASCII-table, so the first letter is H.
                    Other letters can be obtained in the same manner.
            */
            string messageFromBinaryCode(string code)
            {
                string res = "";
                std::bitset<8> bit;
                stringstream read(code);
                while (read >> bit)
                {
                    char c = char(bit.to_ullong());
                    res += c;
                }
                return res;
            }

            /*

            */
            vector<vector<int>> spiralNumbers(int n)
            {
                vector<vector<int>> res(n, vector<int>(n, 0));
                int pos = 0;
                int len = n;
                int num = 1;
                while (pos <= n)
                {
                    // std::cout << num << " ";
                    for (int i = pos; i < len; i++)
                    {
                        res[pos][i] = num++;
                    }

                    // std::cout << "Running this 2: \n";
                    for (int i = pos + 1; i < len; i++)
                    {
                        res[i][len - 1] = num++;
                    }

                    // std::cout << "Running this 3: \n";
                    for (int i = len - 2; i >= pos; i--)
                    {
                        // cout << num << " ";
                        res[len - 1][i] = num++;
                    }

                    // std::cout << "Running this 4: \n";
                    for (int i = len - 2; i > pos; i--)
                    {
                        res[i][pos] = num++;
                    }
                    len--;
                    pos++;
                }
                std::cout << "\nPrint!: \n"; // debug
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        std::cout << res[i][j] << " ";
                    }
                    std::cout << "\n";
                }

                return res;
            }

            /*
                Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that each column, each row,
                and each of the nine 3 × 3 sub-grids that compose the grid contains all of the digits from 1 to 9.

                This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

                Example
                    For
                    grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
                            [4, 6, 5, 8, 7, 9, 3, 2, 1],
                            [7, 9, 8, 2, 1, 3, 6, 5, 4],
                            [9, 2, 1, 4, 3, 5, 8, 7, 6],
                            [3, 5, 4, 7, 6, 8, 2, 1, 9],
                            [6, 8, 7, 1, 9, 2, 5, 4, 3],
                            [5, 7, 6, 9, 8, 1, 4, 3, 2],
                            [2, 4, 3, 6, 5, 7, 1, 9, 8],
                            [8, 1, 9, 3, 2, 4, 7, 6, 5]]
                    the output should be
                    sudoku(grid) = true;
            */
            bool checkRows(vector<vector<int>> grid)
            {
                // checking for each of rows:
                for (int i = 0; i < grid.size(); i++)
                {
                    vector<int> track;
                    // go through each element in a row
                    for (int j = 0; j < grid[0]
                                            .size();
                         j++)
                    {
                        if (track.empty())
                        {
                            track.push_back(grid[i][j]);
                        }
                        else
                        {
                            // if found
                            if (find(track.begin(), track.end(), grid[i][j]) != track.end())
                            {
                                return false;
                            }
                            track.push_back(grid[i][j]);
                        }
                    }
                }
                return true;
            }

            /*
                CodeMaster has just returned from shopping.
                He scanned the check of the items he bought and gave the resulting string to Ratiorg to figure out the total number of purchased items.
                Since Ratiorg is a bot he is definitely going to automate it, so he needs a program that sums up all the numbers which appear in the given input.
                Help Ratiorg by writing a function that returns the sum of numbers that appear in the given inputString.
                Example
                For inputString = "2 apples, 12 oranges", the output should be
                sumUpNumbers(inputString) = 14.
            */
            int sumUpNumbers(string inputString)
            {
                int sumUpNumbers = 0;
                string temp = "";
                int i = 0;
                for (auto w : inputString)
                {
                    if (w > 47 && w < 58)
                    {
                        temp += w;
                    }
                    else
                    {
                        if (temp.length() != 0)
                        {
                            std::cout << temp << endl;
                            sumUpNumbers += (int)stoi(temp);
                        }
                        temp = "";
                    }
                }
                cout << temp << endl;
                if (temp.size() != 0)
                {
                    std::cout << temp << endl;
                    sumUpNumbers += (int)stoi(temp);
                }
                return sumUpNumbers;
            }

            /*
                Check if the given string is a correct time representation of the 24-hour clock.
                Example
                    For time = "13:58", the output should be
                    validTime(time) = true;
                    For time = "25:51", the output should be
                    validTime(time) = false;
                    For time = "02:76", the output should be
                    validTime(time) = false.
                    For time = "24:00", the output should be
                    validTime(time) = false.
            */
            bool validTime(std::string time)
            {
                // -------------- Not Using Algorithm
                // if(time[0] > '2' || time[3] > '6')
                // {
                //     std::cout << "Frist Run!" << std::endl;
                //     return false;
                // }
                // else
                // {
                //     std::cout << "Second Run!" << std::endl;
                //     if(time[0] == 50)
                //     {
                //         if(time[1] >= 52)  // 24:01 -> false: (24) error
                //         {
                //             std::cout << "inside Second Run! \n";
                //             return false;
                //         }
                //     }
                //     if(time[3] == 54)
                //     {
                //         if (time[4] > 47)
                //         {
                //             return false;
                //         }
                //     }
                //     return true;
                // }

                //------------Using Algorithm-------
                return std::regex_match(time, std::regex("(?:[01]\\d|2[0-3]):[0-5]\\d"));

                // ------------Another Way---------
                // return stoi(time.substr(0,2)) < 24 && stoi(time.substr(3,2)) < 60;
            }
        };

        struct Rain_Of_Season
        {
            /*
                Given an array of integers, replace all the occurrences of elemToReplace with substitutionElem.
                Example
                    For inputArray = [1, 2, 1], elemToReplace = 1, and substitutionElem = 3, the output should be
                    arrayReplace(inputArray, elemToReplace, substitutionElem) = [3, 2, 3].
            */
            std::vector<int> arrayReplace(std::vector<int> inputArray, int elemToReplace, int substitutionElem)
            {
                std::vector<int> temp;
                int len = inputArray.size();
                for (int i = 0; i < len; i++)
                {
                    if (inputArray[i] == elemToReplace)
                    {
                        temp.push_back(substitutionElem);
                    }
                    else
                    {
                        temp.push_back(inputArray[i]);
                    }
                }
                return temp;
            }

            /*
                Given two cells on the standard chess board,
                determine whether they have the same color or not.

                Example

                    For cell1 = "A1" and cell2 = "C3", the output should be
                    chessBoardCellColor(cell1, cell2) = true.

                    For cell1 = "A1" and cell2 = "H3", the output should be
                    chessBoardCellColor(cell1, cell2) = false.
            */
            bool chessBoardCellColor(std::string cell1, std::string cell2)
            {

                int int_cell1 = supportedFunctions::int_cell(cell1);
                int int_cell2 = supportedFunctions::int_cell(cell2);

                if ((int_cell1 % 2 != 0 && int_cell2 % 2 != 0) || (int_cell1 % 2 == 0 && int_cell2 % 2 == 0))
                {
                    return true;
                }
                return false;
            }

            /*
                Check if all digits of the given integer are even.

                Example

                For n = 248622, the output should be
                    evenDigitsOnly(n) = true;
                For n = 642386, the output should be
                    evenDigitsOnly(n) = false.
            */
            bool evenDigitsOnly(int n)
            {

                do
                {
                    int temp = n % 10;
                    n = n / 10;
                    if (temp % 2 != 0)
                        return false;
                } while (n > 0);

                return true;
            }
        };

        struct Rainbow_Of_Clarify
        {
            /*
                Given a position of a knight on the standard chessboard,
                find the number of different moves the knight can perform.

                The knight can move to a square that is two squares horizontallyand one square vertically,
                or two squares vertically and one square horizontally away from it.
                The complete move therefore looks like the letter L.
                Check out the image below to see all valid moves for a knight piece that is placed on one of the central squares.

            */
            int chessKnight(std::string cell)
            {
                int moves = 0;
                int posX_cell = int(cell[0]);
                std::cout << "X: " << posX_cell << "\n";
                int posY_cell = int(cell[1]);
                std::cout << "Y: " << posY_cell << "\n";
                // std::array<int,2> Pos_cell = {posX_cell,posY_cell};

                // left of x => x = x - 2
                int pre_posX_cell = posX_cell - 2 + posY_cell;

                // checking for pos of (x-2,y)
                if (pre_posX_cell >= (int('a') + posY_cell))
                {
                    // checking for pos of (x-2,y+1)
                    int pre_posX_cell_high = posX_cell - 2 + posY_cell + 1;
                    if (pre_posX_cell_high <= (posX_cell - 2 + int('8')))
                    {
                        std::cout << "pre_posX_cell_high: Yes"
                                  << "\n";
                        moves++;
                    }

                    // checking for pos of (x-2,y-1)
                    int pre_posX_cell_low = posX_cell - 2 + posY_cell - 1;
                    if (pre_posX_cell_low >= (posX_cell - 2 + int('1')))
                    {
                        std::cout << "pre_posX_cell_low: Yes"
                                  << "\n";
                        moves++;
                    }
                }

                // right of x => x = x + 2
                int next_posX_cell = posX_cell + 2 + posY_cell;
                if (next_posX_cell <= (int('h') + posY_cell))
                {
                    // move to the (x+2,y+1)
                    int next_posX_cell_high = posX_cell + 2 + posY_cell + 1;
                    if (next_posX_cell_high <= (posX_cell + 2 + int('8')))
                    {
                        std::cout << "next_posX_cell_high: Yes"
                                  << "\n";
                        moves++;
                    }

                    // move to the (x+2,y-1)
                    int next_posX_cell_low = posX_cell + 2 + posY_cell - 1;
                    if (next_posX_cell_low >= (posX_cell + 2 + int('1')))
                    {
                        std::cout << "next_posX_cell_low: Yes"
                                  << "\n";
                        moves++;
                    }
                }

                // check for (x,y+2)
                int high_posY_cell = posX_cell + posY_cell + 2;
                if (high_posY_cell <= (posX_cell + int('8')))
                {
                    // check for (x-1,y+2)
                    int high_posY_cell_left = posY_cell + 2 + posX_cell - 1;
                    if (high_posY_cell_left >= (int('a') + (posY_cell + 2)))
                    {
                        std::cout << "high_posY_cell_left: Yes"
                                  << "\n";
                        moves++;
                    }

                    // check for (x+1,y+2)
                    int high_posY_cell_right = posY_cell + 2 + posX_cell + 1;
                    if (high_posY_cell_right <= (int('h') + posY_cell + 2))
                    {
                        std::cout << "high_posY_cell_right: Yes"
                                  << "\n";
                        moves++;
                    }
                }

                // check for (x, y-2)
                int low_posY_cell = posY_cell - 2 + posX_cell;
                if (low_posY_cell >= (posX_cell + int('1')))
                {
                    // check for (x - 1, y - 2)
                    int low_posY_cell_left = posY_cell - 2 + posX_cell - 1;
                    if (low_posY_cell_left >= (int('a') + posY_cell - 2))
                    {
                        std::cout << "low_posY_cell_left: Yes"
                                  << "\n";
                        moves++;
                    }

                    // check for (x + 1, y - 2)
                    int low_posY_cell_right = posY_cell - 2 + posX_cell + 1;
                    if (low_posY_cell_right <= (int('h') + posY_cell - 2))
                    {
                        std::cout << "low_posY_cell_right: Yes"
                                  << "\n";
                        moves++;
                    }
                }
                return moves;
            }

            /*
                Given some integer, find the maximal number you can obtain by deleting exactly one digit of the given number.

                Example:
                    For n = 152, the output should be
                        deleteDigit(n) = 52;
                    For n = 1001, the output should be
                        deleteDigit(n) = 101.
            */
            int deleteDigit(int n)
            {
                int max = 0;
                int i = 1;
                do
                {

                    // Let us analyze this approach for N = 6358, K = 1
                    // The different possibilities after removal of every digit once are as follows:
                    //(6358 / 10) * 1 + 6358 % 1 = 635 + 0 = 635
                    //(6358 / 100) * 10 + 6358 % 10 = 630 + 8 = 638
                    //(6358 / 1000) * 100 + 6358 % 100 = 600 + 58 = 658
                    //(6358 / 10000) * 1000 + 6358 % 1000 = 0 + 358 = 358
                    int haff_second = n % i;
                    int haff_one = (n / (i * 10)) * i;
                    int res = haff_one + haff_second;
                    if (max < res)
                        max = res;
                    std::cout << "max: " << max << "\n";
                    i *= 10;
                } while (i < n);

                return max;
            }

            bool isDigit(char symbol)
            {
                int c = symbol;
                if (c < 48 || c > 57)
                    return false;
                return true;
            }

            std::string lineEncoding(std::string s)
            {
                std::string res = "";
                int length = s.length();
                int i = 0;

                while (i < length)
                {
                    char c = s[i];
                    int j = i;
                    int next_j = j + 1;
                    int count_same = 1;
                    while ((s[j] == s[next_j]) && (j < length - 1))
                    {
                        count_same++;
                        j++;
                        next_j++;
                    }
                    if (count_same == 1)
                    {
                        // s = abcdge
                        res += s[i];
                    }
                    else
                    {
                        // s = 2a3b5c....
                        res += std::to_string(count_same);
                        res += s[i];
                    }
                    std::cout << res << "\n";
                    i += count_same;
                }
                return res;
            }
        };

        struct Smooth_Sailing
        {
            /*
                Given an array of strings, return another array containing all of its longest strings.

                Example:
                    For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
                    allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
            */
            std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray)
            {

                std::vector<std::string> outputArray;
                int longest_length = inputArray[0].length();
                for (int i = 1; i < inputArray.size(); i++)
                {
                    if (inputArray[i].length() > longest_length)
                    {
                        longest_length = inputArray[i].length();
                    }
                }

                for (int j = 0; j < inputArray.size(); j++)
                {
                    if (inputArray[j].length() == longest_length)
                    {
                        outputArray.push_back(inputArray[j]);
                    }
                }
                return outputArray;
            }

            /*
                For n = 239017, the output should be
                    isLucky(n) = false;
                Bonus: For n = 23023, the output should be
                    isLucky(n) = True;
            */
            bool isLucky(int n)
            {
                std::vector<int> int_num;
                int sum_left = 0;
                int sum_right = 0;
                // pushing all of element of n;
                while (n > 0)
                {
                    int_num.push_back(n % 10);
                    n = n / 10;
                }
                int size = int_num.size();
                // std::cout << size;
                if (size % 2 == 0) // checking if size is even;
                {
                    int left = 0;
                    int right = size - 1;
                    while (left < right)
                    {
                        sum_left += int_num[left];
                        sum_right += int_num[right];
                        left++;
                        right--;
                    }
                }
                else
                {
                    int_num.push_back(0);
                    int left = 0;
                    int right = size;
                    while (left < right)
                    {
                        sum_left += int_num[left];
                        sum_right += int_num[right];
                        left++;
                        right--;
                    }
                }

                if (sum_left == sum_right)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            /*
                Given an array of strings, return another array containing all of its longest strings.

                Example
                    For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
                    allLongestStrings(inputArray) = ["aba", "vcd", "aba"].

                Input:
                    [execution time limit] 0.5 seconds(cpp)
                    [input] array.string inputArray

                    A non - empty array.

                    Guaranteed constraints :
                    1 ≤ inputArray.length ≤ 10,
                    1 ≤ inputArray[i].length ≤ 10.

                [output] array.string
                    Array of the longest strings, stored in the same order as in the inputArray.

            */
            std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray)
            {
                std::vector<std::string> outputArray;
                int longest_length = inputArray[0].length();
                for (int i = 1; i < inputArray.size(); i++)
                {
                    if (inputArray[i].length() > longest_length)
                    {
                        longest_length = inputArray[i].length();
                    }
                }

                for (int j = 0; j < inputArray.size(); j++)
                {
                    if (inputArray[j].length() == longest_length)
                    {
                        outputArray.push_back(inputArray[j]);
                    }
                }

                return outputArray;
            }

            /*
                Write a function that reverses characters in(possibly nested) parentheses in the input string.
                Input strings will always be well - formed with matching()s.

                Example
                    For inputString = "(bar)", the output should be
                        reverseInParentheses(inputString) = "rab";
                    For inputString = "foo(bar)baz", the output should be
                        reverseInParentheses(inputString) = "foorabbaz";
                    For inputString = "foo(bar)baz(blim)", the output should be
                        reverseInParentheses(inputString) = "foorabbazmilb";
                    For inputString = "foo(bar(baz))blim", the output should be
                        reverseInParentheses(inputString) = "foobazrabblim".
                    Because "foo(bar(baz))blim" becomes "foo(barzab)blim" and then "foobazrabblim".

                Input / Output:
                    [execution time limit] 0.5 seconds(cpp)
                    [input] string inputString
                    A string consisting of lowercase English letters and the characters(and).
                    It is guaranteed that all parentheses in inputString form a regular bracket sequence.
                    Guaranteed constraints : //0 ≤ inputString.length ≤ 50.
                [output] string
                    Return inputString, with all the characters that were in parentheses reversed.
            */
            void reverseInParentheses(std::string &inputString)
            {
                std::stack<char> st;
                int len = inputString.length();
                for (int i = 0; i < len; i++)
                {

                    // pushing position of '(' in stack;
                    if (inputString[i] == '(')
                    {
                        st.push(i);
                    }

                    // reversing string from index of stack.top() and position of ')'
                    else if (inputString[i] == ')')
                    {
                        reverse(inputString.begin() + st.top() + 1,
                                inputString.begin() + i);
                        st.pop();
                    }
                }

                // To store the modified string
                std::string res = "";
                for (int i = 0; i < len; i++)
                {
                    if (inputString[i] != ')' && inputString[i] != '(')
                        res += (inputString[i]);
                }
                inputString = res;
            }

            /*

                Some people are standing in a row in a park.There are trees between them which cannot be moved.
                Your task is to rearrange the people by their heights in a non - descending order without moving the trees.
                People can be very tall!

                Example
                For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
                    sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].
            */
            std::vector<int> sortByHeight(std::vector<int> &a)
            {
                int size = a.size();
                std::vector<int> temp;
                for (int i = 0; i < size - 1; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        if (a[i] != -1 && a[j] != -1)
                        {
                            if (a[i] > a[j])
                            {
                                int temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
                            }
                        }
                    }
                }
                // temp = a;
                // return temp;
                return a;
            }

            /*
                Given two strings, find the number of common characters between them.
                Example

                    For s1 = "aabcc" and s2 = "adcaa", the output should be
                    commonCharacterCount(s1, s2) = 3.
                Strings have 3 common characters - 2 "a"s and 1 "c".
            */
            int commonCharacterCount(std::string s1, std::string s2)
            {
                int total = 0;
                std::vector<char> char_vect;
                int size_s1 = s1.size();
                int size_s2 = s2.size();
                // passing through all elements in array
                for (int i = 0; i < size_s1; i++)
                {
                    // checking exist in previous elements or not!
                    if (char_vect.empty())
                    {
                        char_vect.push_back(s1[i]);
                    }
                    else
                    {
                        bool IsExist = false; // suppose that s1[i] is available for adding in char_vect;
                        for (int j = 0; j < char_vect.size(); j++)
                        {
                            if (s1[i] == char_vect[j])
                            {
                                IsExist = true;
                            }
                        }
                        if (IsExist == false)
                        {
                            // push_back element which is not in char_vect;
                            char_vect.push_back(s1[i]);
                        }
                    }
                }
                for (int i = 0; i < size_s2; i++)
                {
                    // checking exist in previous elements or not!
                    //  suppose that s1[i] is available for adding in char_vect;
                    if (char_vect.empty())
                    {
                        char_vect.push_back(s2[i]);
                    }
                    else
                    {
                        bool IsExist = false; // suppose that s2[i] is available for adding in char_vect;
                        for (int j = 0; j < char_vect.size(); j++)
                        {
                            if (s2[i] == char_vect[j])
                            {
                                IsExist = true;
                            }
                        }
                        if (IsExist == false)
                        {
                            // push_back element which is not in char_vect;
                            char_vect.push_back(s2[i]);
                        }
                    }
                }
                for (int i = 0; i < char_vect.size(); i++)
                {
                    std::cout << char_vect[i] << " ";
                }
                std::cout << std::endl;

                for (int i = 0; i < char_vect.size(); i++)
                {
                    int count_s1 = 0;
                    int count_s2 = 0;
                    for (int j = 0; j < s1.size(); j++)
                    {
                        if (s1[j] == char_vect[i])
                        {
                            count_s1++;
                        }
                    }
                    for (int j = 0; j < s2.size(); j++)
                    {
                        if (s2[j] == char_vect[i])
                        {
                            count_s2++;
                        }
                    }
                    if (count_s1 >= count_s2)
                    {
                        total += count_s2;
                    }
                    else
                    {
                        total += count_s1;
                    }
                }

                return total;
            }
        };

        struct Through_The_Frog
        {
            /*
                Given a sorted array of integers a, your task is to determine
                which element of a is closest to all other values of a.In other words,
                find the element x in a, which minimizes the following sum :

                abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.length - 1] - x)
                (where abs denotes the absolute value)

                If there are several possible answers, output the smallest one.

                Example

                For a = [2, 4, 7], the output should be absoluteValuesSumMinimization(a) = 4.

                for x = 2, the value will be abs(2 - 2) + abs(4 - 2) + abs(7 - 2) = 7.
                for x = 4, the value will be abs(2 - 4) + abs(4 - 4) + abs(7 - 4) = 5.
                for x = 7, the value will be abs(2 - 7) + abs(4 - 7) + abs(7 - 7) = 8.
                The lowest possible value is when x = 4, so the answer is 4.

                For a = [2, 3], the output should be absoluteValuesSumMinimization(a) = 2.

                for x = 2, the value will be abs(2 - 2) + abs(3 - 2) = 1.
                for x = 3, the value will be abs(2 - 3) + abs(3 - 3) = 1.
                Because there is a tie, the smallest x between x = 2 and x = 3 is the answer.
            */
            int absoluteValuesSumMinimization(std::vector<int> a)
            {
                int len = a.size();
                int res = 0;
                int min = 99999999; // chose max of this type! if we have elements more than min -> return will be wrong
                // sum = abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.size() - 1] - x)
                for (int i = 0; i < len; i++)
                {
                    float sum = 0;
                    int x = a[i];
                    for (int j = 0; j < len; j++)
                    {
                        sum = sum + abs(a[j] - x);
                    }
                    std::cout << "case a[" << i << "] = " << a[i] << " -> " << sum << std::endl;
                    if (sum < min)
                    {
                        min = sum;
                        res = a[i];
                    }
                }
                return res;
            }

            /*
                Consider integer numbers from 0 to n - 1 written down along the circle in such a way
                that the distance between any two neighboring numbers is equal
                (note that 0 and n - 1 are neighboring, too).

                Given n and firstNumber,
                find the number which is written in the radially opposite position to firstNumber.

                Example

                For n = 10 and firstNumber = 2, the output should be
                circleOfNumbers(n, firstNumber) = 7.
            */
            int circleOfNumbers(int n, int firstNumber)
            {
                if (firstNumber < n / 2)
                    return n / 2 + firstNumber;
                return firstNumber - n / 2;
            }

            /*

                You have deposited a specific amount of money into your bank account.
                Each year your balance increases at the same growth rate.
                With the assumption that you don't make any additional deposits,
                find out how long it would take for your balance to pass a specific threshold.

                Example

                For deposit = 100, rate = 20, and threshold = 170, the output should be
                depositProfit(deposit, rate, threshold) = 3.

                Each year the amount of money in your account increases by 20 % .So throughout the years, your balance would be :

                year 0 : 100;
                year 1: 120;
                year 2: 144;
                year 3: 172.8.
                Thus, it will take 3 years for your balance to pass the threshold, so the answer is 3.
            */
            int depositProfit(int deposit, int rate, int threshold)
            {
                int year = 0;
                float growth = rate / float(100);
                float deposit_temp = deposit;
                while (deposit_temp < threshold)
                {
                    year++;
                    deposit_temp += deposit_temp * growth;
                }
                return year;
            }

            /*
                Given an array of equal - length strings,
                you'd like to know if it's possible to rearrange the order of the elements in such a way that
                each consecutive pair of strings differ by exactly one character.
                Return true if it's possible, and false if not.

                Note: You're only rearranging the order of the strings,
                not the order of the letters within the strings!

                Example

                For inputArray = ["aba", "bbb", "bab"], the output should be
                stringsRearrangement(inputArray) = false.

                There are 6 possible arrangements for these strings :

                ["aba", "bbb", "bab"]
                ["aba", "bab", "bbb"]
                ["bbb", "aba", "bab"]
                ["bbb", "bab", "aba"]
                ["bab", "bbb", "aba"]
                ["bab", "aba", "bbb"]
                None of these satisfy the condition of consecutive strings differing by 1 character,
                so the answer is false.

                For inputArray = ["ab", "bb", "aa"], the output should be
                stringsRearrangement(inputArray) = true.

                It's possible to arrange these strings
                in a way that each consecutive pair of strings differ by 1 character
                (eg: "aa", "ab", "bb" or "bb", "ab", "aa"), so return true.

            */
            int dist(const std::string &s1, const std::string &s2)
            {
                int count = 0;
                for (int i = 0; i < s1.size(); i++)
                {
                    if (s1[i] != s2[i])
                    {
                        count++;
                    }
                }
                return count;
            }
        };

    private:
        int m_problemsID;
    };
};
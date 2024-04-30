// Giới hạn ký tự: 3000
// Cho dãy a gồm n số nguyên không âm a(1), a(2), ..., a(n) và Q câu hỏi.

// Mỗi câu hỏi sẽ cho biết 3 số X L R, yêu cầu hãy đếm số lần xuất hiện số X trong đoạn từ L đến R. Hay nói cách khác đếm số lượng số nguyên i thỏa mãn 2 điều kiện sau:

// L ≤ i ≤ R
// a(i) = X.
// Bạn hãy trả về một mảng gồm Q phần tử, phần tử thứ i là đáp án của câu hỏi thứ i.

// Ví dụ:

// n=7, a=[7,6,2,0,0,6,8], Q=3, query=[[2,1,4],[6,1,6],[7,2,4]]
//  thì countNum(n,a,Q,query)=[1,2,0]
// Giải thích: Mỗi phần tử trong query sẽ là bộ 3 số (X, L, R) theo thứ tự.
// Mảng a: 7 6 2 0 0 6 8 
// Câu hỏi thứ 1: X=2, L=1, R=4 thì đáp án là 1, đó là i=3.
// Câu hỏi thứ 2: X=6, L=1, R=6 thì đáp án là 2, đó là các số i= 2,6.
// Câu hỏi thứ 3: X=7, L=2, R=4 thì đáp án là 0.
// Vậy mảng ta cần trả về tương ứng là [1, 2, 0]


#include <iostream>
#include <vector>
#include <chrono>


using namespace std;

class Timer
{
private:
  // Type aliases to make accessing nested type easier
  using clock_t = std::chrono::high_resolution_clock;
  using second_t = std::chrono::duration<double, std::ratio<1>>;
 
  std::chrono::time_point<clock_t> m_beg;
 
public:
  Timer() : m_beg(clock_t::now())
  {
  }

  void reset()
  {
    m_beg = clock_t::now();
  }

  double elapsed() const
  {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
  }
};

void vecPrint(vector<int> vec);

int countX(vector<int> arr, int find, int left, int right)
{
    int count = 0;
    int iRun = left;
    while (iRun <= right)
    {
        if (arr[iRun] == find)
        {
            count++;
        }
        iRun++;
    }
    return count;
}

std::vector<int> countNum(int n, std::vector<int> a, int Q, std::vector<std::vector<int>> query)
{
    vector<int> res;
    for (int iQue = 0; iQue < Q; iQue++)
    {
        vector<int> elemQuery = query[iQue];
        res.push_back(countX(a,elemQuery[0],elemQuery[1] - 1,elemQuery[2] - 1));
    }
    
    return res;
}

void vecPrint(vector<int> vec)
{
    cout << "\nOut put: \n";
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    //Output: [1,2,0]
    int n = 7;
    vector<int> a{7,6,2,0,0,6,8};
    int Q = 3;
    vector<vector<int>> query {
        {2,1,4},{6,1,6}, {7,2,4}
    };
    Timer t;    
    vector<int> count = countNum(n,a,Q,query);
    std::cout << "Time taken: " << t.elapsed() << " seconds\n";
    vecPrint(count);
    

    // Output: [0,0,0,1,0,2,0,1,1,1]
    int n2 = 10;
    vector<int> a2{7,9,0,9,8,9,2,6,6,4};
    int Q2 = 10;
    vector<vector<int>> query2 {
        {0,7,8},{3,1,6},{1,7,8},{0,1,7},{8,4,4},{9,3,9},{5,7,8},{6,1,8},{4,1,10},{6,3,8}
    };
    vector<int> count2 = countNum(n2,a2,Q2,query2);
    vecPrint(count2);

    return 0;
}

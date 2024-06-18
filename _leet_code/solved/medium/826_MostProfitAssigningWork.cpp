/*
    You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
    difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
    worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
    Every worker can be assigned at most one job, but one job can be completed multiple times.
    For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
    Return the maximum profit we can achieve after assigning the workers to the jobs.
     
    Example 1:
        Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
        Output: 100
        Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
    Example 2:
        Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
        Output: 0
*/
class Solution {
    public:
        int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                                vector<int>& worker) {
            vector<pair<int, int>> jobProfile;
            jobProfile.push_back({0, 0});
            for (int i = 0; i < difficulty.size(); i++) {
                jobProfile.push_back({difficulty[i], profit[i]});
            }
    
            // Sort by difficulty values in increasing order.
            sort(jobProfile.begin(), jobProfile.end());
            for (int i = 0; i < jobProfile.size() - 1; i++) {
                jobProfile[i + 1].second =
                    max(jobProfile[i].second, jobProfile[i + 1].second);
            }
    
            int netProfit = 0;
            for (int i = 0; i < worker.size(); i++) {
                int ability = worker[i];
    
                // Find the job with just smaller or equal difficulty than ability.
                int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (jobProfile[mid].first <= ability) {
                        jobProfit = max(jobProfit, jobProfile[mid].second);
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
    
                // Increment profit of current worker to total profit.
                netProfit += jobProfit;
            }
            return netProfit;
        }
};

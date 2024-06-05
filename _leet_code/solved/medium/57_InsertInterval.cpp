/*
    You are given an array of non-overlapping intervals intervals 
    where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
    You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
    and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

    Return intervals after the insertion.
    Note that you don't need to modify intervals in-place. You can make a new array and return it.

    Example 1:
        Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
        Output: [[1,5],[6,9]]
    Example 2:
        Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
        Output: [[1,2],[3,10],[12,16]]
        Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
    	int _size = intervals.size();
    	if (_size == 0) {
    		return vector<vector<int>>{newInterval};
    	}
    	// If the new interval is out of range in lowest -> just append after newInterval
#ifdef OLD_HANDLE
    	if (newInterval[1] < intervals[0][0]) {
    		vector<vector<int>> res;
    		res.push_back(newInterval);
    		for (auto elem : intervals) {
    			res.push_back(elem);
    		}
    		return res;
    	}
    	if (intervals[_size - 1][1] < newInterval[0]) {
    		intervals.push_back(newInterval);
    		return intervals;
    	}
#endif
    	
    	vector<vector<int>> res;
    	int _start_new = newInterval[0];
    	int _end_new = newInterval[1];
    	int _status = 0; // finding new start
    	bool isPushNewInterval = false;
    
#ifndef OLD_HANDLE
    	// When the new interval is less than the first one -> push it first and running to push whole 
    	if (newInterval[1] < intervals[0][0]) {
    		res.push_back(newInterval);
    		isPushNewInterval = true;
    	}
#endif
    
    	for (auto i = 0; i < _size; ++i)
    	{
    		if (intervals[i][1] < _start_new) {
    			res.push_back(intervals[i]);
    		}
    		else if (intervals[i][0] > _end_new) {
    			if (!isPushNewInterval) {
    				res.push_back({_start_new, _end_new});
    				isPushNewInterval = true;
    			}
    			res.push_back(intervals[i]);
    		} else {
    			if (_start_new >= intervals[i][0]
    			&& _end_new <= intervals[i][1]) {
    				res.push_back(intervals[i]);
    				isPushNewInterval = true;
    			}
    			else {
    				_start_new = min(_start_new, intervals[i][0]);
    				_end_new = max(_end_new, intervals[i][1]);
    			}
    		}
    	}
    	if (!isPushNewInterval) {
    		res.push_back({_start_new, _end_new});
    	}
    	return res;
    }
};

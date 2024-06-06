#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <algorithm>

using namespace std;
string g_str_verify = "";

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

	for (auto elem : res) {
		g_str_verify += to_string(elem[0]) + ":" + to_string(elem[1]);
		g_str_verify += " ";
	}
	// Remove the last " " in the string
	g_str_verify.erase(--g_str_verify.end());
	return res;
}

// [1 2 2 3 4 6 7 8]
// [1 2]
//      2
// [1 2 3]
//      [2 4] -> false

// [1 2 2 3 3 4  6 7 8]
// [1 2]
//      2
// [1 2 3]
//      [2 3] -> false
bool isNStraightHand(vector<int>& hand, int groupSize) {
	// If impossible for creating group
	if (hand.size() % groupSize != 0) {
		return false;
	}
	std::sort(hand.begin(), hand.end());
	struct holder {
		int _val;
		int _count;
		bool _isNew = true;
	};

	holder _count {
		._val = hand[0],
		._count = 0
	};

	int _next_start = 0;
	for (int i = 1; i < hand.size(); ++i) {
		if (!_count._isNew && hand[i] > _count._val + 1) {
			return false;
		}

		if (_count._isNew) {
			_count._isNew = false;
			_count._val = hand[i] - 1;
			_count._count++;
		}
		else {
			
		}
	}
	return true;
}


TEST(insert, intervalTest) {
	static vector<vector<vector<int>>> _vt = {
		{
			{1,2},
			{4,10},
			{13,20}
		},
		{
			{1,5}
		},
		{
			{0,0}
		}
	};
	static vector<vector<int>> newInterval = {
		{5,6},
		{2,7},
		{1,1}
	};

	static vector<string> result = {
		"1:2 4:10 13:20",
		"1:7",
		"0:0 1:1"
	};

	for (int i = 0; i < _vt.size(); ++i) {
		g_str_verify.clear();
		// invoke method
		insert(_vt[i], newInterval[i]);
		// EXPECT_EQ(g_str_verify, "1:2 4:10 13:20");
		EXPECT_EQ(g_str_verify, result[i]);
	}
	
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	// test_interval();
	return RUN_ALL_TESTS();
}


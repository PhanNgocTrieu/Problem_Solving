#include <iostream>
#include <vector>
#include <gtest/gtest.h>

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

void test_interval() {
	static vector<vector<vector<int>>> _vt = {
		{
			{1,2},
			// {3,5},
			// {6,7},
			// {8,10},
			{4,10},
			// {12,16} 
			{13,20}
		},
		{
			{1,5}
		},
		{
			{0,0}
		}
	};

	static vector<vector<vector<int>>> newInterval = {
		{
			{5,6},
			{5,11},
			{13,20},
		},
		{
			{2,7}
		},
		{
			{1,1}
		}
	};

	for (int i = 0; i < _vt.size(); ++i) {
		for (auto new_interval : newInterval[i]) {
			cout << "Test-case:" << new_interval[0] << " - " << new_interval[1] << endl;
			auto vt = insert(_vt[i], new_interval);
			for (auto elem : vt) {
				cout << elem[0] << " - " << elem[1] << endl;
			}
			cout << endl;
		}
	}
	
}


TEST(insert, intervalTest) {
	vector<vector<int>> _vt = {
		{1,2},
		{4,10},
		{13,20}
	};
	vector<int> _new = {
		{5,6},
	};
	// invoke method
	insert(_vt, _new);
	// expectation for verify
	EXPECT_EQ(g_str_verify, "1:2 4:10 13:20");
	
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	// test_interval();
	return RUN_ALL_TESTS();
}


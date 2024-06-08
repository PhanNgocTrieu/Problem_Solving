#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <gtest/gtest.h>

using namespace std;
#if 0
struct good_subarray {
	int sum_val = 0;
	int count = 0;
	bool isGood = false;
};

int get_sum_of_elem(const vector<int>& nums, int k, good_subarray& g_sb, int idx) {
	cout << __FUNCTION__ << " passing: " << __LINE__ << " g_sb.sum: " << g_sb.sum_val << endl;
	// out of list -> return
	if (idx >= nums.size()) {
		// cout << __FUNCTION__ << " passing: " << __LINE__ << endl;
		return 0;
	}

	if (g_sb.count == 2) {
		return 0;
	}
	// cout << __FUNCTION__ << " passing: " << __LINE__ << endl;
	// Already found -> return
	if (g_sb.isGood) {
		return 0;
	}
	// cout << __FUNCTION__ << " passing: " << __LINE__ << endl;
	g_sb.sum_val += get_sum_of_elem(nums, k, g_sb, ++idx);
	g_sb.count++;

	if (g_sb.sum_val % k == 0
	&& g_sb.count >= 2) {
		g_sb.isGood = true;
	}
	// cout << __FUNCTION__ << " passing: " << __LINE__ << endl;
	// Reverse value
	// g_sb.sum_val -= nums[idx];

	return g_sb.sum_val;
}
#endif

bool handle_check_subarray_sum(const vector<int> &nums, int k, int idx, int sum, int count)
{
	// cout << __FUNCTION__ << " passing: " << __LINE__ << endl;
	if (idx >= nums.size())
	{
		return false;
	}
	sum += nums[idx];
	count++;
	if (sum % k == 0 && count > 1)
	{
		return true;
	}
	idx++;
	// cout << __FUNCTION__ << " passing: " << __LINE__ << endl;
	return handle_check_subarray_sum(nums, k, idx, sum, count);
}

bool checkSubarraySum(const vector<int> &nums, int k)
{
	for (auto i = 0; i < nums.size(); ++i)
	{
		int count = 0;
		int sum = 0;
		if (handle_check_subarray_sum(nums, k, i, sum, count))
		{
			return true;
		}
	}
	return false;
}

TEST(test_case_1, UI_TEST)
{
	EXPECT_TRUE(checkSubarraySum({23, 2, 4, 6, 7}, 6));
}

TEST(test_case_2, UI_TEST)
{
	EXPECT_TRUE(checkSubarraySum({23, 2, 6, 4, 7}, 6));
}

TEST(test_case_3, UI_TEST)
{
	EXPECT_FALSE(checkSubarraySum({23, 2, 6, 4, 7}, 13));
}

TEST(test_case_4, UI_TEST)
{
	EXPECT_TRUE(checkSubarraySum({23, 2, 6, 4, 7}, 2));
}

TEST(test_case_5, UI_TEST)
{
	EXPECT_TRUE(checkSubarraySum({23, 2, 4, 6, 6}, 7));
}

TEST(test_case_6, UNIT_TEST)
{
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	// test_interval();
	return RUN_ALL_TESTS();
}

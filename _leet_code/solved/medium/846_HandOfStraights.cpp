// Same as 1296 Id
/*
    Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, 
    and consists of groupSize consecutive cards.
    
    Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
    return true if she can rearrange the cards, or false otherwise.

    Example 1:

        Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
        Output: true
        Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
    
    Example 2:
        Input: hand = [1,2,3,4,5], groupSize = 4
        Output: false
        Explanation: Alice's hand can not be rearranged into groups of 4.
*/
class Solution {
public:
#define SELF_SOLVED
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    	// If impossible for creating group
    	if (hand.size() % groupSize != 0) {
    		return false;
    	}
        if (groupSize == 1) {
            return true;
        }
    	std::sort(hand.begin(), hand.end());
    	bool isNotRemainValue = false;
    	int _start = hand[0];
    	hand[0] = -1;
    	int _count = 1;
    	bool res = true;
    	while (!isNotRemainValue) {
    		isNotRemainValue = true;
    		for (int i = 1; i < hand.size(); ++i) {
#if 0
    			cout << endl;
    			for (auto e : hand) {
    				cout << e << " ";
    			}
    			cout << endl;
    			cout << "\t -> _start: " << _start << " _count: " << _count << " hand[i]: " << hand[i]  << endl;
#endif
    			if (_count == groupSize) {
    				_count = 0;
    				_start = -1;
    				break;
    			}
    			if (hand[i] != -1) {
    				if (_start == -1) {
    					_start = hand[i];
    					hand[i] = -1;
    					_count++;
    					isNotRemainValue = false;
    				}
    
    				if (hand[i] > _start + 1) {
    					res = false;
    					break;
    				}
    				else if (hand[i] - 1 == _start) {
    					_start = hand[i];
    					hand[i] = -1;
    					isNotRemainValue = false;
    					_count++;
    				}
    			}
    		}
    		if (_count == groupSize) {
    			_count = 0;
    			_start = -1;
    			isNotRemainValue = false;
    		}
    		if (!res) {
    			break;
    		}
    	}
    
    	if (_count != 0) {
    		res = false;
    	}
    	return res;
    }
#else
   bool findSuccessors(vector<int>& hand, int groupSize, int i, int n) {
        int next = hand[i] + 1;
        hand[i] = -1;  // Mark as used
        int count = 1;
        i += 1;
        while (i < n && count < groupSize) {
            if (hand[i] == next) {
                next = hand[i] + 1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        return count == groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        std::sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++) {
            if (hand[i] >= 0) {
                if (!findSuccessors(hand, groupSize, i, n)) return false;
            }
        }
        return true;
    }
#endif
};

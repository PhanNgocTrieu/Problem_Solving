/*
    In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. 
    For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

    Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, 
    replace all the derivatives in the sentence with the root forming it. 
    If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
    
    Return the sentence after the replacement.
*/
#ifdef OTHER_WAY
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());

        // Replace each word in sentence with the corresponding shortest root
        string word;
        string newSentence;
        while (getline(sStream, word, ' ')) {
            newSentence += shortestRoot(word, dictSet) + " ";
        }

        newSentence.pop_back();  // remove extra space
        return newSentence;
    }

private:
    string shortestRoot(string word, unordered_set<string> dictSet) {
        // Find the shortest root of the word in the dictionary
        for (int i = 1; i <= word.length(); i++) {
            string root = word.substr(0, i);
            if (dictSet.contains(root)) {
                return root;
            }
        }
        // There is not a corresponding root in the dictionary
        return word;
    }
};
#endif

#define TOO_LONG_TIME
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <gtest/gtest.h>

using namespace std;

bool if_equal(string lhs, string rhs) {
	if (strncmp(lhs.c_str(), rhs.c_str(), lhs.size()) == 0) {
		return true;
	}
	return false;
}

bool isExistInDictionray(const vector<string> &dictionary, string& word, const unordered_map<string, string> map) {

	for (auto elem : map) {
		if (elem.first[0] == word[0]) {
			if (if_equal(elem.second,word)) {
				word = elem.second;
			}
		}
	}
	return false;
}

string replaceWords(vector<string> &dictionary, string sentence)
{
	// cout << __FUNCTION__ << " word: " << word << endl;
	unordered_map<string, string> mapping;
	for (auto dic : dictionary) {
		if (mapping[dic] != "") {
			if (if_equal(dic,mapping[dic])) {
				if (dic.length() < mapping[dic].length()) {
					mapping[dic] = dic;
				}
			}
		} else {
			mapping[dic] = dic;
		}
	}

	// for (auto elem : mapping) {
	// 	cout << "key: " << elem.first << " - value: " << elem.second << endl;
	// }
	// cout << endl;
	string result = "";
#if 1
	auto foundIt = sentence.find_first_of(' ');
	while (foundIt != sentence.npos) {
		auto get_word = sentence.substr(0, foundIt);
		// cout << "word:" << get_word << endl;
		// handle checking word;
		(void)isExistInDictionray(dictionary, get_word, mapping);
		result += get_word + " ";
		// cout << " after compare: " << result << endl;
		// Remove word
		sentence.erase(0, foundIt + 1);
		// cout << sentence << endl;
		foundIt = sentence.find_first_of(' ');
	}

	isExistInDictionray(dictionary, sentence, mapping);
	result += sentence;
#endif
	return result;
}

TEST(ReplaceWords, UI_TEST) {
	static vector<vector<string>> map_dictionary = {
		{"cat","bat","rat"},
		{"a","b","c"},
		{"a", "aa", "aaa", "aaaa"},
		{"ac","ab"}
	};

	static vector<string> sentences = {
		"the cattle was rattled by the battery",
		"aadsfasf absbs bbab cadsfafs",
		"a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa",
		"it is abnormal that this solution is accepted"
	};
	
	static vector<string> results = {
		"the cat was rat by the bat",
		"a a b c",
		"a a a a a a a a bbb baba a",
		"it is ab that this solution is ac"
	};

	for (int i = 0; i < map_dictionary.size(); ++i) {
		EXPECT_EQ(replaceWords(map_dictionary[i],sentences[i]),results[i]);
	}
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	// test_interval();
	return RUN_ALL_TESTS();
}
#endif

/*
  Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). 
  You may return the answer in any order.

  Example 1:
    Input: words = ["bella","label","roller"]
    Output: ["e","l","l"]
  
  Example 2:
    Input: words = ["cool","lock","cook"]
    Output: ["c","o"]
*/
#if 0 // Slow one
  class Solution {
  public:
      vector<string> commonChars(vector<string>& words) {
          vector<string> res;
          unordered_map<char, int> mapping_c;
          for (auto c : words[0]) {
              mapping_c[c]++;
          }
          int size = words.size();
          bool flag_found = false;
          for (int i = 1; i < size; ++i) {
              unordered_map<char, int> mapping_next;
              // Mapping word
              for (const auto& c : words[i]) {
                  mapping_next[c]++;
              }
              for (auto elem : mapping_c) {
                  auto foundIt = mapping_next.find(elem.first); // to slow
                  if (foundIt != mapping_next.end()) {
                      mapping_c[elem.first] = min(mapping_c[foundIt->first], foundIt->second);
                      flag_found = true;
                  } else {
                      mapping_c[elem.first] = 0;
                  }
              }
              if (!flag_found) {
                  return vector<string>{};
              }
          }
  
          for (auto& elem : mapping_c) {
              while (elem.second > 0) {
                  res.push_back(string(1,elem.first));
                  elem.second--;
              }
          }
  
          return res;
      }
  };
#endif 

#if 1
    class Solution {
    public:
        vector<string> commonChars(vector<string>& words) {
            vector<int> count(26, INT_MAX);
            vector<string> res;
            for (const auto& w : words) {
                vector<int> counts(26, 0);
                for (const auto& c : w) {
                  counts[c - 'a']++;
                }
                for (int i = 0; i < 26; i++) {
                  count[i] = min(count[i], counts[i]);
                }
            }
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < count[i]; j++) {
                    res.push_back(string(1, 'a' + i));
                }
            }
            return res;
        }
    };
#endif

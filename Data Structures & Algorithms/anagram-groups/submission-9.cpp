#include <ranges>

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1) return {strs};

        std::unordered_map<std::string, std::vector<std::string>> res;
        for (const auto& s : strs) {
            std::vector<unsigned int> freq(26, 0);
            for (const char c : s) {
                freq[c - 'a']++;
            }

            std::string key = std::to_string(freq[0]);
            for (size_t i{1}; i < 26; i++) {
                key += ',' + std::to_string(freq[i]);
            }

            res[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& strArray : res | std::views::values) {
            result.push_back(strArray);
        }

        return result;
    }
};

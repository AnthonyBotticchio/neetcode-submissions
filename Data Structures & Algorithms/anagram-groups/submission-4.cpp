#include <ranges>

class Solution {
    std::unordered_map<std::string, std::vector<std::string>> strMap;

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1) return {strs};

        std::vector<std::vector<std::string>> res;
        for (const auto& s : strs) {
            std::vector<unsigned int> freq(26, 0);
            for (const char c : s) {
                freq[c - 'a']++;
            }

            std::string key = std::to_string(freq[0]);
            for (size_t i{1}; i < 26; i++) {
                key += ',' + std::to_string(freq[i]);
            }

            strMap[key].push_back(s);
        }

        for (const auto& strArray : strMap | std::views::values) {
            res.push_back(strArray);
        }

        return res;
    }
};

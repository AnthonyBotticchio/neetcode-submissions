#include <ranges>

class Solution {
    std::unordered_map<std::string, std::vector<std::string>> strMap;

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1) return {strs};

        std::vector<std::vector<std::string>> res;
        // {act, {act, cat}} {aht, 1}, {opts, 3}
        // {{act -> {act, cat}}, {opts -> {pots, tops, stop}, {aht -> {hat}}}
        for (const auto& s : strs) {
            auto sorted = s;
            std::sort(sorted.begin(), sorted.end());

            if (const auto& it = strMap.find(sorted); it != strMap.end()) {
                it->second.push_back(s);
            } else {
                strMap.emplace(sorted, std::vector<std::string>{s});
            }
        }

        for (const auto& strArray : strMap | std::views::values) {
            res.push_back(strArray);
        }

        return res;
    }
};

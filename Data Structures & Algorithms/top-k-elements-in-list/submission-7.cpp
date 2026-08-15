class Solution {
    std::unordered_map<int, unsigned int> countMap;

   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return std::vector<int>{*nums.begin()};
        }

        for (const auto i : nums) {
            countMap[i]++;
        }

        std::vector<std::pair<int, unsigned int>> sorted(countMap.begin(), countMap.end());
        // Sort values
        std::sort(sorted.begin(), sorted.end(),
                  [](const auto& l, const auto& r) { return l.second > r.second; });
        std::vector<int> res(k);  // Reserve k space
        std::transform(sorted.begin(), sorted.begin() + k, res.begin(),
                       [](const auto& pair) { return pair.first; });

        return res;
    }
};

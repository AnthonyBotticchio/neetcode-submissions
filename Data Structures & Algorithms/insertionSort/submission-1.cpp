// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };

#include <ranges>

class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        size_t n = pairs.size();
        std::vector<std::vector<Pair>> res;

        if(pairs.empty()) {
            return res;
        }
        else if(n == 1) {
            res.push_back(pairs);
            return res;
        }

        for(size_t i = 0; i < n; i++) {
            int j = i - 1;

            while(j >= 0 && pairs[j].key > pairs[j + 1].key) {
                std::swap(pairs[j], pairs[j + 1]);
                j--;
            }

            res.push_back(pairs);
        }

        return res;
    }
};

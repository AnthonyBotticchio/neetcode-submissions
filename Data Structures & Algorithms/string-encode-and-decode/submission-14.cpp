class Solution {
    std::vector<int> store;

#define DELIMETER '#'

   public:
    string encode(vector<string>& strs) {
        std::string res{};

        // Push each stoi int onto stack
        for (const auto& s : strs) {
            auto len = s.size();
            res += std::to_string(len) + DELIMETER + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        // Create result vector. Reserve stack size
        std::vector<string> res;

        int idx{};
        while (idx < s.size()) {
            int delim_idx = s.find(
                DELIMETER, idx);  // find offers a place to start searching from. We start from idx
            if (delim_idx == std::string::npos) break;

            int strLen = std::stoi(s.substr(idx, delim_idx - idx));

            res.push_back(s.substr(delim_idx + 1, strLen));
            idx = strLen + delim_idx + 1;
        }

        return res;
    }
};

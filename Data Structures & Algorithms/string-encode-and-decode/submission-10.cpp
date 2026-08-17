class Solution {
    std::vector<int> store;

#define DELIMETER '#'

   public:
    string encode(vector<string>& strs) {
        std::string res;

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

        size_t idx{};
        size_t endIdx{};
        std::string lengthStr;
        std::string temp;  // dummy to hold chars
        while (idx < s.size()) {
            if (s[idx] == DELIMETER) {
                int length = std::stoi(lengthStr);
                idx++;                  // Increment idx to starting pos
                endIdx = idx + length;  // idx when to stop
                while (idx < endIdx)    // Read all chars of encoded string
                {
                    temp += s[idx++];
                }

                // Add to result clear;
                res.push_back(temp);
                temp.clear();
                lengthStr.clear();
            } else {
                // Assume that idx, outside of the bottom control loop, will always
                // land on a length char (ex. 0, 3, 9)
                lengthStr += s[idx++];
            }

        }

        return res;
    }
};

class Solution {
    std::stack<char> stack;
    std::unordered_map<char, char> map{{'}', '{'}, {')', '('}, {']', '['}};

   public:
    bool isValid(string s) {
        for (const char c : s) {
            const auto it = map.find(c);
            if (it == std::end(map)) {  // c is a Opening bracket
                stack.push(c);
            } else {                                  // c is a Closing bracket
                const char openBracket = it->second;  // Corresponding opening bracket

                if (!stack.empty()) {
                    // If previous is the corresponding opening bracket
                    if (openBracket == stack.top()) {
                        stack.pop();
                        continue;
                    }
                }

                stack.push(c);
            }
        }

        return stack.empty();
    }
};

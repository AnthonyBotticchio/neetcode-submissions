class MinStack {
    std::stack<int> stack;
    std::stack<int> minStack;

   public:
    MinStack() {}

    void push(int val) {
        stack.push(val);
        minStack.push(std::min<int>(val, minStack.empty() ? val : minStack.top()));
    }

    void pop() { stack.pop(); minStack.pop();}

    int top() { return stack.top(); }

    int getMin() { return minStack.top(); }
};

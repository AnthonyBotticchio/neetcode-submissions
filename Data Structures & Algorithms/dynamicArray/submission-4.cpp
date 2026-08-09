class DynamicArray {
    int* m_arr = nullptr;
    int m_length = 0;
    int m_capacity = 0;

   public:
    DynamicArray(int capacity) : m_capacity(capacity) {
        m_arr = new int[capacity];  // the new int[__] declares a new int arr with the '[]'
    }

    ~DynamicArray() {
        delete[] m_arr;
    } 

    int get(int i) { return m_arr[i]; }

    void set(int i, int n) {
        if (i < m_capacity) {
            m_arr[i] = n;
        }
    }

    void pushback(int n) {
        if (getSize() == getCapacity()) {
            resize();
        }

        m_arr[m_length] = n;
        m_length++;
    }

    int popback() {
        if (m_length > 0) {
            m_length--;
        }

        return m_arr[m_length];
    }

    void resize() {
        m_capacity *= 2;
        int* newArr = new int[m_capacity];
        for (int i = 0; i < m_length; i++) {
            newArr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = newArr;
    }

    int getSize() { return m_length; }

    int getCapacity() { return m_capacity; }
};

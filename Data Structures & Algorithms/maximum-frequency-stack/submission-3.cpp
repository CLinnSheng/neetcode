/*
Pop removes and return the most frequent element in the stack
So frequency matters here
So definitely we need to use map to track the frequency of each val
We need to keep track whats the maximum frequency also, this also can be another map
mapping to a stack --> this also solve the tie for the most frequent element
*/
class FreqStack {
public:
    std::unordered_map<int, int> freq;
    std::unordered_map<int, stack<int>> freq_stack;
    int maxFreq{};
    FreqStack() {
        
    }
    
    void push(int val) {
        // Increase the cnt of that element
        freq[val]++;

        // Push into stack map
        freq_stack[freq[val]].push(val);

        // Update the maxFreq
        if (maxFreq < freq[val])
        {
            maxFreq = freq[val];
        }
    }
    
    int pop() {
        // Get the last top element of stack with maxFreq & Pop it
        int element = freq_stack[maxFreq].top();

        // Pop it
        freq_stack[maxFreq].pop();

        // Decrease the cnt
        freq[element]--;

        // Update MaxFreq
        if (freq_stack[maxFreq].empty())
        {
            maxFreq--;
        }

        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
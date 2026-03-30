/*
Design a stack where it always pop the most frequent elmeent.

Intuition:
Ok the key thing is actually how do we always ensure the most frequent element is at the top.
So the frequency of each val is important and we need it.
So we can use a hashmap to store the information of each frequecny.
And then theres come naother problem how do we deal with number with the same frequency?
At here we can solve it by using stack so the top of the stack will always be the lsat element push into the stack
Time Complexity: O(n)
*/
class FreqStack {
public:
    std::unordered_map<int, int> cnt;
    std::unordered_map<int, std::stack<int>> cnt_stack;
    int maxCnt;

    FreqStack() {
        maxCnt = 0;    
    }
    
    // If found new maxCnt, then build new stack for the particulary cnt
    void push(int val) {
        int currCnt = ++cnt[val];
        if (currCnt > maxCnt)
        {
            maxCnt = currCnt;
            cnt_stack[maxCnt] = std::stack<int>();
        }

        // Push to respective cnt, so we always get the last access element at the top for each freq
        cnt_stack[currCnt].push(val);
    }
    
    int pop() {
        int val = cnt_stack[maxCnt].top();
        cnt_stack[maxCnt].pop();
        cnt[val]--;

        // Checking the new maximum count
        if (cnt_stack[maxCnt].empty())
            maxCnt--;

        return val;        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
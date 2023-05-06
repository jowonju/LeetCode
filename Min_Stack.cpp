//Using a node
class MinStack {
    private Node head;
        
    public void push(int x) {
        if (head == null) 
            head = new Node(x, x, null);
        else 
            head = new Node(x, Math.min(x, head.min), head);
    }
    
    public void pop() {
        head = head.next;
    }
    
    public int top() {
        return head.val;
    }
    
    public int getMin() {
        return head.min;
    }
        
    private class Node {
        int val;
        int min;
        Node next;
            
        private Node(int val, int min, Node next) {
            this.val = val;
            this.min = min;
            this.next = next;
        }
    }
}

//Using two stacks
class MinStack {
public:

    MinStack() {
    }
    
    void push(int val) {
        if(minStk.size() > 0 && minStk.top() >= val)
        {
            minStk.push(val);
        }
            
        
        if(stk.size() < 1)
        {
            minStk.push(val);
        }
        
        stk.push(val);
    }
    
    void pop() {
        if(stk.top() == minStk.top())
        {
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
    
private:
    std::stack<int> minStk;
    std::stack<int> stk;
};

//Using one stack
class MinStack {
public:
    stack<int>s;
    int minElement = INT_MAX;//initalize with max value

    void push(int val) {
        if (minElement >= val) {// whenever val is lesser than current minElement, store current minElement in stack and make val as current minElement
            s.push(minElement); //for tracking the previous min value
            minElement = val;
        }
        s.push(val);
    }

    void pop() {
        if (minElement == s.top()) {//top is minElement then previous element will be previous minElement, so pop and store current top as current MinElement
            s.pop();
            minElement = s.top();
        }
        s.pop();
    }

    int top() {// return stack top
        return s.top();
    }

    int getMin() {//return minElement
        return minElement;
    }
};
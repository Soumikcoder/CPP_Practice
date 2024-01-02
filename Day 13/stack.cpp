// Stack class.
class Stack {
    vector<int>data;
    int topID=-1;
public:
    
    Stack(int capacity) {
        // Write your code here.
        data=vector<int>(capacity,0);
    }

    void push(int num) {
        // Write your code here.
        if((topID+1)!=data.size())
            data[++topID]=num;
    }

    int pop() {
        if(topID>-1)
            return data[topID--];
        else
            return -1;
        // Write your code here.
    }
    
    int top() {
        // Write your code here.
        if(topID!=-1)
            return data[topID];
        else
            return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(topID==-1) return 1;
        else return 0;
    }
    
    int isFull() {
        if(topID==(data.size()-1)) return 1;
        else return 0;
        // Write your code here.
    }
    
};

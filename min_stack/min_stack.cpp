#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        s_.push(x);
        if (min_s_.empty() || x<=getMin())
            min_s_.push(x);
    }

    void pop() {
        if (s_.empty())
            return;

        if (min_s_.top() == s_.top())
            min_s_.pop();
        s_.pop();
    }

    int top() {
        return s_.top();
    }

    int getMin() {
        return min_s_.top();
    }

private:
    stack<int> s_;
    stack<int> min_s_;
};

int main(int argc, char *argv[])
{
    MinStack s;
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(2);
    s.push(10);

    cout << "top:" << s.top() << endl;
    cout << "min:" << s.getMin() << endl;
    s.pop();
    cout << "min:" << s.getMin() << endl;
    s.pop();
    cout << "min:" << s.getMin() << endl;
    s.pop();
    cout << "min:" << s.getMin() << endl;
    s.pop();
    cout << "min:" << s.getMin() << endl;

    return 0;
}

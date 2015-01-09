#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        s_.push(x);
        if (min_s_.empty()) {
            min_s_.push(make_pair(x, 1));
        } else {
            if (x < getMin())
                min_s_.push(make_pair(x, 1));
            else
                min_s_.top().second++;
        }
    }

    void pop() {
        if (s_.empty())
            return;

        s_.pop();
        min_s_.top().second--;
        if (min_s_.top().second == 0)
            min_s_.pop();
    }

    int top() {
        return s_.top();
    }

    int getMin() {
        return min_s_.top().first;
    }

private:
    stack<int> s_;
    stack<pair<int, int> > min_s_;
};

int main(int argc, char *argv[])
{
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(3);
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

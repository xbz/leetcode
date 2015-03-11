#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(const vector<int>& v)
{
    vector<int>::size_type i;
    for (i=0; i<v.size()-1; i++)
        cout << v[i] << ' ';
    cout << v[i] << endl;
}

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            _stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = _stack.top();
        _stack.pop();
        TreeNode *tmp = cur;
        cur = cur->right;
        while (cur != NULL) {
            _stack.push(cur);
            cur = cur->left;
        }
        return tmp->val;
    }

private:
    stack<TreeNode *> _stack;
};

int main(int argc, char *argv[])
{
    // TreeNode *empty = NULL;
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(50);
    TreeNode *t3 = new TreeNode(15);
    t3->left = t1;
    t3->right = t2;
    TreeNode *t4 = new TreeNode(50);
    TreeNode *t5 = new TreeNode(20);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(30);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(10);
    t1->right = t7;

    BSTIterator it(t3);
	while (it.hasNext())
		cout << it.next() << endl;

    return 0;
}

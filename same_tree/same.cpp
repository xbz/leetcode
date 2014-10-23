#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p==NULL or q==NULL)
            return p==q;

        return p->val==q->val && \
               isSameTree(p->left, q->left) && \
               isSameTree(p->right, q->right);
    }
};

// sumbit times for the first accept: 1
int main(int argc, char *argv[])
{
    TreeNode* t1 = new TreeNode(10);
    // t1->left = new TreeNode(5);
    // t1->right = new TreeNode(15);
    TreeNode* t2 = new TreeNode(10);
    // t2->left = new TreeNode(5);
    // t2->right = new TreeNode(20);

    Solution s;
    bool isSame = s.isSameTree(t1, t2);
    cout << isSame << endl;

    return 0;
}

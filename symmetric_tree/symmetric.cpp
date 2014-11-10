#include <iostream>
#include <vector>

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

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return isSymmHelper(root->left, root->right);
    }
private:
    bool isSymmHelper(TreeNode *left, TreeNode *right) {
        if (left==NULL || right==NULL)
            return left == right;
        return left->val == right->val && \
            isSymmHelper(left->left, right->right) && \
            isSymmHelper(left->right, right->left);
    }
};

int main(int argc, char *argv[])
{
    // TreeNode *empty = NULL;
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(15);
    t3->left = t1;
    t3->right = t2;
    TreeNode *t4 = new TreeNode(50);
    TreeNode *t5 = new TreeNode(20);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(60);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->right = t7;
    Solution s;

    bool isSymm = s.isSymmetric(t3);
    cout << "tree is symmetric:" << isSymm << endl;

    return 0;
}

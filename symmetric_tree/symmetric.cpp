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
        vector<int> v1;
        inOrder(root, v1);
        vector<int> v2;
        reverseInOrder(root, v2);
        if (v1.size() != v2.size())
            return false;
        return equal(v1.begin(), v1.end(), v2.begin());
    }
private:
    void reverseInOrder(TreeNode *root, vector<int>& v) {
        if (root == NULL)
            return;
        reverseInOrder(root->right, v);
        v.push_back(root->val);
        reverseInOrder(root->left, v);
    }
    void inOrder(TreeNode *root, vector<int>& v) {
        if (root == NULL)
            return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
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
    TreeNode *t6 = new TreeNode(6);
    t2->right = t6;
    TreeNode *t7 = new TreeNode(6);
    // t1->left = t7;
    Solution s;

    bool isSymm = s.isSymmetric(t3);
    cout << "tree is symmetric:" << isSymm << endl;

    return 0;
}

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL)
            return ret;

        ret.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
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
    TreeNode *t6 = new TreeNode(60);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->right = t7;
    Solution s;

    vector<int> v = s.preorderTraversal(t3);
    cout << "tree preorder:" << endl;
    print(v);

    return 0;
}

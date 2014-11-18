#include <iostream>
#include <vector>
#include <stack>

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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;

        if (!root->left && !root->right)
            return root->val == sum;

        return hasPathSum(root->left, sum-root->val) || \
            hasPathSum(root->right, sum-root->val);
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
    TreeNode *t6 = new TreeNode(12);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->right = t7;
    TreeNode *t8 = new TreeNode(100);
    t7->left = t8;
    Solution s;

    const int sum = 50;
    bool hasPath = s.hasPathSum(NULL, sum);
    cout << "tree has Path:" << sum << " " << hasPath << endl;

    return 0;
}

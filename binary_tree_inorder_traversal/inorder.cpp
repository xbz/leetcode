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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (true) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
			ret.push_back(cur->val);
            cur = cur->right;
        }
        return ret;
    }

    vector<int> inorderTraversal_recursive(TreeNode *root) {
        vector<int> ret;
        inorder(root, ret);
        return ret;
    }

private:
    void inorder(TreeNode *root, vector<int>& v) {
        if (root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
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
    TreeNode *t4 = new TreeNode(500);
    TreeNode *t5 = new TreeNode(20);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(60);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->right = t7;
    Solution s;

    vector<int> v = s.inorderTraversal(t5);
    cout << "tree inorder:" << endl;
    print(v);

    return 0;
}

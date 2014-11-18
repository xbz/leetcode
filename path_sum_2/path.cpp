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

void print(const vector<vector<int> >& v)
{
    vector<vector<int> >::size_type i;
    for (i=0; i<v.size(); i++) {
        vector<vector<int> >::size_type j;
        for (j=0; j<v[i].size(); ++j)
            cout << v[i][j] << ' ';
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (!root) {
            vector<vector<int> > ret;
            return ret;
        }

        if (!root->left && !root->right) {
            vector<vector<int> > ret;
            if (root->val == sum) {
                vector<int> v;
                v.push_back(root->val);
                ret.push_back(v);
            }
            return ret;
        }

        vector<vector<int> > left = pathSum(root->left, sum-root->val);
        vector<vector<int> > right = pathSum(root->right, sum-root->val);
        vector<vector<int> > ret;
        for (vector<vector<int> >::size_type i=0; i<left.size(); ++i) {
            left[i].insert(left[i].begin(), root->val);
            ret.push_back(left[i]);
        }
        for (vector<vector<int> >::size_type i=0; i<right.size(); ++i) {
            right[i].insert(right[i].begin(), root->val);
            ret.push_back(right[i]);
        }
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
    TreeNode *t6 = new TreeNode(12);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->right = t7;
    TreeNode *t8 = new TreeNode(100);
    t7->left = t8;
    TreeNode *t9 = new TreeNode(51);
    t7->right = t9;
    Solution s;

    const int sum = 77;
    vector<vector<int> > v = s.pathSum(t3, sum);
    print(v);

    return 0;
}

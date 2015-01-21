#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root) {
    if (root == NULL)
        return;

    cout << "enter left" << endl;
    print(root->left);
    cout << root->val << endl;
    cout << "enter right" << endl;
    print(root->right);
}

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return NULL;

        int root_idx = (num.size()-1) / 2;
        vector<int> left(num.begin(), num.begin()+root_idx);
        vector<int> right(num.begin()+root_idx+1, num.end());
        TreeNode *root = new TreeNode(num[root_idx]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 3, 5, 8 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));

    TreeNode *tree = s.sortedArrayToBST(v);
    print(tree);

    return 0;
}

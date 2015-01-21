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
        return helper(num, 0, num.size()-1);
    }

private:
    TreeNode *helper(const vector<int>& num, int i, int j) {
        if (i > j)
            return NULL;

        int mid = (i + j) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = helper(num, i, mid-1);
        root->right = helper(num, mid+1, j);
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

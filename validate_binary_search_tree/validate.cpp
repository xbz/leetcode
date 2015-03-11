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

class Solution {
public:
    bool isValidBST(TreeNode *root) {
		return valid(root, LONG_MIN, LONG_MAX);
	}

	bool valid(TreeNode *root, long low, long high) {
		if (root == NULL)
			return true;
		if (root->val<=low || root->val>=high)
			return false;
		return valid(root->left, low, root->val) && valid(root->right, root->val, high);
	}

    bool isValidBST_inorder(TreeNode *root) {
		stack<TreeNode *> s;
		TreeNode *pre = NULL;
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
			if (pre!=NULL && pre->val>=cur->val)
				return false;
			pre = cur;
			cur = cur->right;
		}
		return true;
	}

    bool isValidBST_orig(TreeNode *root) {
        if (!root)
            return true;

        vector<int> seq;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (1) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty())
                break;
            cur = s.top();
            seq.push_back(cur->val);
            s.pop();
            cur = cur->right;
        }
        for (vector<int>::size_type i=0; i<seq.size()-1; ++i)
            if (seq[i] >= seq[i+1])
                return false;
        return true;
    }

    bool isValidBST_wrong(TreeNode *root) {
        if (root == NULL)
            return true;
        if (root->left && root->left->val >= root->val)
            return false;
        if (root->right && root->right->val <= root->val)
            return false;

        return isValidBST(root->left) && isValidBST(root->right);
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
    TreeNode *t6 = new TreeNode(30);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(10);
    t1->right = t7;
    Solution s;

    bool isBST = s.isValidBST(t3);
    cout << "tree is bst:" << isBST << endl;

    return 0;
}

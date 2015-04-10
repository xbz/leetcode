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

class Traversal {
public:
    vector<int> preorder(TreeNode *root) {
        vector<int> ret;
        if (root == NULL)
            return ret;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if (cur->right != NULL)
                s.push(cur->right);
            if (cur->left != NULL)
                s.push(cur->left);
        }
        return ret;
    }

    vector<int> inorder(TreeNode *root) {
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
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}

private:
	// don't need process the case when prelen=1
	TreeNode *helper(const vector<int> &preorder, size_t prepos, size_t prelen,
					 const vector<int> &inorder, size_t inpos, size_t inlen) {
		if (prelen == 0)
			return NULL;

		int rootval = preorder[prepos];
		size_t pos = inpos;
		for (size_t i=inpos; i<inpos+inlen; ++i) {
			if (inorder[i] == rootval) {
				pos = i;
				break;
			}
		}

		size_t leftlen = pos - inpos;
		size_t rightlen = inlen - leftlen - 1;
		TreeNode *root = new TreeNode(rootval);
		root->left = helper(preorder, prepos+1, leftlen, inorder, inpos, leftlen);
		root->right = helper(preorder, prepos+1+leftlen, rightlen,
							 inorder, inpos+leftlen+1, rightlen);
		return root;
	}

};

int main(int argc, char *argv[])
{
	int arr1[] = { 1, 2, 4, 5, 3, 6 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	vector<int> pre(arr1, arr1+len1);
	int arr2[] = { 4, 2, 5, 1, 6, 3 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	vector<int> in(arr2, arr2+len2);
    Solution s;

	print(pre);
	print(in);
    TreeNode *tree = s.buildTree(pre, in);
	cout << tree->val << endl;
	cout << tree->right << endl;
	Traversal tra;
    print(tra.preorder(tree));
	print(tra.inorder(tree));

    return 0;
}

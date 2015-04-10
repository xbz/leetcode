#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

    vector<int> postorder(TreeNode *root) {
        vector<int> ret;
        if (root == NULL)
            return ret;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if (cur->left != NULL)
                s.push(cur->left);
            if (cur->right != NULL)
                s.push(cur->right);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}

private:
	TreeNode *helper(const vector<int> &inorder, size_t inpos, size_t inlen,
					 const vector<int> &postorder, size_t postpos, size_t postlen) {
		if (inlen == 0)
			return NULL;

		size_t pos = inpos;
		int rootval = postorder[postpos+postlen-1];
		for (size_t i=inpos; i<inpos+inlen; ++i) {
			if (inorder[i] == rootval) {
				pos = i;
				break;
			}
		}

		size_t leftlen = pos - inpos;
		size_t rightlen = inlen - leftlen - 1;
		TreeNode *root = new TreeNode(rootval);
		root->left = helper(inorder, inpos, leftlen,
							postorder, postpos, leftlen);
		root->right = helper(inorder, inpos+leftlen+1, rightlen,
							 postorder, postpos+leftlen, rightlen);
		return root;
	}

};

int main(int argc, char *argv[])
{
	int arr1[] = { 4, 2, 5, 1, 6, 3 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	vector<int> in(arr1, arr1+len1);
	int arr2[] = { 4, 5, 2, 6, 3, 1 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	vector<int> post(arr2, arr2+len2);
    Solution s;

	print(in);
	print(post);
    TreeNode *tree = s.buildTree(in, post);
	Traversal tra;
    print(tra.inorder(tree));
	print(tra.postorder(tree));

    return 0;
}

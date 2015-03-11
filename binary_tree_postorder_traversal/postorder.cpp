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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ret;
		stack<TreeNode *> s;
		TreeNode *cur = root;
		while (true) {
			while (cur != NULL) {
				s.push(cur);
				s.push(cur);
				cur = cur->left;
			}
			if (s.empty())
				break;

			cur = s.top();
			s.pop();
			if (!s.empty() && cur==s.top()) {
				cur = cur->right;
			} else {
				ret.push_back(cur->val);
				cur = NULL;
			}
		}
		return ret;
    }

    vector<int> postorderTraversal_recursive(TreeNode *root) {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }

private:
    void postorder(TreeNode *root, vector<int>& v) {
        if (root == NULL)
            return;

        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
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

    vector<int> v = s.postorderTraversal(t5);
    cout << "tree postorder:" << endl;
    print(v);

    return 0;
}

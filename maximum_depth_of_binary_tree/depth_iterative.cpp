#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;

        map<TreeNode *, int> m;
        queue<TreeNode *> q;
        q.push(root);
        m[root] = 1;
        int max = 1;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            //cout << "cur val:" << cur->val << endl;
            q.pop();
            int height = m[cur];
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            if (left != NULL) {
                q.push(left);
                m[left] = height+1;
                if (height+1 > max)
                    max = height+1;
            }
            if (right != NULL) {
                q.push(right);
                m[right] = height+1;
                if (height+1 > max)
                    max = height+1;
            }
        }
        return max;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *empty = NULL;
    TreeNode *t1 = new TreeNode(10);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(15);
    t3->left = t1;
    t3->right = t2;
    TreeNode *t4 = new TreeNode(50);
    TreeNode *t5 = new TreeNode(20);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(6);
    t2->right = t6;
    Solution s;

    int h1 = s.maxDepth(empty);
    cout << "h1 depth:" << h1 << endl;

    int h2 = s.maxDepth(t1);
    cout << "h2 depth:" << h2 << endl;

    int h3 = s.maxDepth(t5);
    cout << "h3 depth:" << h3 << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
        for (j=0; j<v[i].size(); j++)
            cout << v[i][j] << ' ';
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> level;
            size_t level_num = que.size();
            for (size_t i=0; i<level_num; ++i) {
                TreeNode *cur = que.front();
                que.pop();
                level.push_back(cur->val);
                if (cur->left != NULL)
                    que.push(cur->left);
                if (cur->right != NULL)
                    que.push(cur->right);
            }
            ret.insert(ret.begin(), level);
        }
        return ret;
    }

    vector<vector<int> > levelOrderBottom_orig(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;

        map<int, vector<int> > m;
        typedef pair<TreeNode *, int> Node;
        Node node = make_pair(root, 0);
        queue<Node> q;
        q.push(node);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            TreeNode *cur = node.first;
            m[node.second].push_back(cur->val);
            if (cur->left) {
                Node node_left = make_pair(cur->left, node.second+1);
                q.push(node_left);
            }

            if (cur->right) {
                Node node_right = make_pair(cur->right, node.second+1);
                q.push(node_right);
            }
        }
        map<int, vector<int> >::const_reverse_iterator it=m.rbegin();
        for (; it!=m.rend(); ++it)
            ret.push_back(it->second);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    // TreeNode *empty = NULL;
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(15);
    t3->left = t1;
    t3->right = t2;
    TreeNode *t4 = new TreeNode(50);
    TreeNode *t5 = new TreeNode(20);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(60);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->right = t7;
    Solution s;

    vector<vector<int> > v = s.levelOrderBottom(t3);
    print(v);

    return 0;
}

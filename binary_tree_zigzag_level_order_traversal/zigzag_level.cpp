#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
        map<int, vector<int> >::iterator it=m.begin();
        int index = 0;
        for (; it!=m.end(); ++it) {
            if (index%2 == 1)
                reverse(it->second.begin(), it->second.end());
            ret.push_back(it->second);
            ++index;
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    // TreeNode *empty = NULL;
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(8);
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

    vector<vector<int> > v = s.zigzagLevelOrder(t3);
    print(v);

    return 0;
}

#include <iostream>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p==NULL or q==NULL)
            return p==q;
        if (p->val != q->val)
            return false;

        map<string, int> m1 = build_path_helper(p);
        map<string, int> m2 = build_path_helper(q);
        if (m1.size() != m2.size())
            return false;

        for (map<string, int>::const_iterator cit=m1.begin();
            cit!=m1.end(); ++cit) {
            map<string, int>::const_iterator tmpit = m2.find(cit->first);
            if (tmpit == m2.end())
                return false;
            if (cit->second != tmpit->second)
                return false;
        }
        return true;
    }
private:
    map<string, int> build_path_helper(TreeNode *root) {
        typedef pair<TreeNode *, string> ExtraNode;
        stack<ExtraNode> s;
        map<string, int> m;
        string path;
        TreeNode *cur = root;
        while (1) {
            while (cur) {
                s.push(make_pair(cur, path));
                cur = cur->left;
                if (cur) {
                    path += "0";
                    m[path] = cur->val;
                }
            }
            if (s.empty())
                break;
            ExtraNode node = s.top();
            cur = node.first;
            path = node.second;
            s.pop();
            cur = cur->right;
            if (cur) {
                path += "1";
                m[path] = cur->val;
            }
        }
        return m;
    }
};

// sumbit times for the first accept: 1
int main(int argc, char *argv[])
{
    TreeNode* t1 = new TreeNode(10);
    t1->left = new TreeNode(5);
    t1->right = new TreeNode(15);
    TreeNode* t2 = new TreeNode(10);
    t2->left = new TreeNode(5);
    t2->right = new TreeNode(15);

    Solution s;
    bool isSame = s.isSameTree(t1, t2);
    cout << isSame << endl;

    return 0;
}

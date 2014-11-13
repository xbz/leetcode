#include <iostream>
#include <map>
#include <stack>
#include <queue>

using namespace std;

void print(const map<string, int>& m) {
    cout << "print map:" << endl;
    for (map<string, int>::const_iterator cit=m.begin();
        cit!=m.end(); ++cit)
        cout << cit->first << " " << cit->second << endl;
}

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
        print(m1);
        print(m2);
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
        typedef pair<TreeNode *, string> Node;
        queue<Node> q;
        string path;
        map<string, int> m;
        q.push(make_pair(root, path));
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            TreeNode *left = n.first->left;
            string path = n.second;
            if (left) {
                path += "0";
                q.push(make_pair(left, path));
                m[path] = left->val;
            }
            TreeNode *right = n.first->right;
            if (right) {
                path += "1";
                q.push(make_pair(right, path));
                m[path] = right->val;
            }
        }
        return m;
    }
    map<string, int> build_path_helper_pre(TreeNode *root) {
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
    TreeNode* t3 = new TreeNode(5);
    t3->right = new TreeNode(15);
    t2->left = t3;
    // t2->right = new TreeNode(20);

    Solution s;
    bool isSame = s.isSameTree(t1, t2);
    cout << isSame << endl;

    return 0;
}

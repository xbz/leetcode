#include <iostream>
#include <vector>
#include <stack>
#include <map>

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
    bool isSymmetric(TreeNode *root) {
        map<string, int> m = build_path_helper(root);
        for (map<string, int>::const_iterator cit=m.begin();
            cit!=m.end(); ++cit) {
            string rkey = reverse(cit->first);
            map<string, int>::const_iterator symit = m.find(rkey);
            if (symit == m.end())
                return false;
            if (symit->second != cit->second)
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
    string reverse(const string& s) {
        string ret;
        for (string::size_type i=0; i<s.length(); ++i)
            ret.push_back('1'-s[i]+'0');

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
    // TreeNode *t4 = new TreeNode(50);
    // TreeNode *t5 = new TreeNode(20);
    // t5->left = t3;
    // t5->right = t4;
    TreeNode *t6 = new TreeNode(6);
    t2->left = t6;
    TreeNode *t7 = new TreeNode(6);
    t1->left = t7;
    Solution s;

    bool isSymm = s.isSymmetric(t3);
    cout << "tree is symmetric:" << isSymm << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root) {
    if (root == NULL)
        return;

    cout << "enter left" << endl;
    print(root->left);
    cout << root->val << endl;
    cout << "enter right" << endl;
    print(root->right);
}

ListNode *build_list(const vector<int>& v) {
    ListNode *p = new ListNode(0);
    ListNode *head = p;
    for (size_t i=0; i<v.size(); i++) {
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return head->next;
}

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        return helper(v, 0, v.size()-1);
    }

private:
    TreeNode *helper(const vector<int>& num, int i, int j) {
        if (i > j)
            return NULL;

        int mid = i + (j-i)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = helper(num, i, mid-1);
        root->right = helper(num, mid+1, j);
        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 3, 5, 8 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    ListNode *pList = build_list(v);

    TreeNode *tree = s.sortedListToBST(pList);
    print(tree);

    return 0;
}

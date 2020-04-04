#include<iostream>
#include<vector>
#include<stack>

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        std::stack<TreeNode> st;

        if(root == NULL)
            return v;
        
        TreeNode* curr = root;
        TreeNode* prev;

        while(curr!=NULL || !st.empty())
        {
            if(curr != NULL)
            {
                st.push(*curr);
                curr = curr->left;
            }
            else{
                curr = &(st.top());
                st.pop();
                v.push_back(curr->val);
                prev = curr;
                curr = curr->right;
            }
        }
        return v;
    }
};

#include<iostream>
#include<vector>
#include<stack>

//Reference: https://en.wikipedia.org/wiki/Tree_traversal#Post-order

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> v;
        if(root == NULL)
            return v;
        TreeNode* curr = root;
        TreeNode* last_visited_node = NULL;
        std::stack<TreeNode*> st;

        // bool curr_right_visited = false;
        while(curr!=NULL || !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else{
                curr = st.top();
                //If comes from left, go to right
                if(curr->right!=NULL && last_visited_node!=curr->right)
                {
                    curr = curr->right;
                }
                else
                {
                    st.pop();
                    v.push_back(curr->val);
                    last_visited_node = curr;
                    curr = NULL;
                }
                // else{
                //     last_visited_node = curr;
                //     v.push_back(curr->val);
                //     st.pop();
                // }
            }
        }
        return v;
    }
};
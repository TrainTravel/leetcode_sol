#include<iostream>
#include<stack>
// Definition for a binary tree node.



struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        TreeNode* prev = NULL;
        TreeNode* current = root;
        std::stack<TreeNode*> st;
        // 'current != NULL' means you can go down in the tree
        // !st.empty allows us to go back up in the tree
        while(current != NULL || !st.empty())
        {
            if(current == NULL) //if cannot go left, only can go back up
            {
                current = st.top();
                st.pop();
                if(prev!=NULL && (current->val <= prev->val))
                    return false;
                
                prev = current;
                current = current->right;
            }
            else
            {
                st.push(current);
                current = current->left;
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root == NULL)
//             return true;
//         TreeNode* prev = NULL;
//         TreeNode* current = root;
//         std::stack<TreeNode*> st;
//         // 'current != NULL' means you can go down in the tree
//         // !st.empty allows us to go back up in the tree
//         while(current != NULL || !st.empty())
//         {
//             if(current == NULL) //if cannot go left, only can go back up
//             {
//                 if(prev!=NULL)
//                     std::cout<<"get prev: " << prev->val<<std::endl;
//                 std::cout <<"cannot go left" <<std::endl;
//                 current = st.top();
//                 st.pop();
//                 std::cout << "popped current: " <<current->val <<std::endl;
//                 if(prev!=NULL && (current->val <= prev->val))
//                 {
//                     std::cout << "current: " << current-> val << " prev: " << prev->val<<std::endl;
//                     return false;
//                 }
//                 else
//                     std::cout<< "ok" <<std::endl;
//                 prev = current;
//                 std::cout << "set prev: " <<prev->val <<std::endl;
//                 current = current->right;
//                 std::cout << std::endl;
//                 std::cout << "get prev: " <<prev->val <<"\n" <<std::endl;
//             }
//             else
//             {
//                 if(prev!=NULL)
//                     std::cout << "get prev: " <<prev->val <<std::endl;
//                 st.push(current);
//                 std::cout << current->val << " pushed into stack" <<std::endl;
//                 if(prev!=NULL)
//                     std::cout << "get prev: " <<prev->val <<std::endl;
//                 else
//                     std::cout << "prev is null\n" <<std::endl;
                        
//                 current = current->left;
//             }
//         }
//         return true;
//     }
// };
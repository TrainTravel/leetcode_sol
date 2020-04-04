#include<iostream>
#include<stack>

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // std::vector<int> v;
        int nthsmallest = 0;
        std::stack<TreeNode> st;
        
        if(root == NULL)
            return 0;
        
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
                // v.push_back(curr->val);
                if(++nthsmallest == k)
                    return curr->val;
                prev = curr;
                curr = curr->right;
            }
            // std::cout<< "size: " << v.size() <<std::endl;
            // if(v.size() == k)
            //     return v[k-1];
        }
        return -1;
    }
};

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         std::vector<int> v;
//         std::stack<TreeNode> st;
        
//         if(root == NULL)
//             return 0;
        
//         TreeNode* curr = root;
//         TreeNode* prev;

//         while(curr!=NULL || !st.empty())
//         {
//             if(curr != NULL)
//             {
//                 st.push(*curr);
//                 curr = curr->left;
//             }
//             else{
//                 curr = &(st.top());
//                 st.pop();
//                 v.push_back(curr->val);
//                 prev = curr;
//                 curr = curr->right;
//             }
//             // std::cout<< "size: " << v.size() <<std::endl;
//             if(v.size() == k)
//                 return v[k-1];
//         }
//         return -1;
//     }
// };

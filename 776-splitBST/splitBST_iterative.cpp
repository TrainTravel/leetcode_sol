#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int v) {
        vector<TreeNode *> res(2, NULL);
        std::queue<TreeNode*> larger;
        std::queue<TreeNode*> smaller;
        TreeNode* curr = root;
        TreeNode* small_curr, *large_curr;
        small_curr = large_curr = NULL;
        /* Corner case */
        if (root == NULL) {
            return res;
        }

        while(curr != NULL){
            if(curr->val > v){
                larger.push(curr);
                std::cout<< "pushing " << curr->val << " to larger queue." << std::endl;
                curr = curr->left;
            }
            else{
                smaller.push(curr);
                std::cout<< "pushing " << curr->val << " to smaller queue." << std::endl;
                curr = curr->right;
            }
        }

        TreeNode* small_prev = NULL;
        while(!smaller.empty()){
            small_curr = smaller.front();
            std::cout<<"popping small" <<std::endl;
            if(small_prev!=NULL){               
                std::cout<<"here: small_prev->val: " <<small_prev->val<<std::endl;
                small_prev->right = small_curr;
                std::cout<<"small_prev->val: " << small_prev->val << "'s right node = " << small_curr->val <<std::endl;
            }
            std::cout << "From small queue, pop: " << small_curr->val <<std::endl;
            smaller.pop();         
            
            if(!res[0])
                res[0] = small_curr;
            // small_curr = small_curr->right = NULL;
            small_prev = small_curr;
            
        }
        if(small_prev)
            small_prev->right = NULL;
        std::cout<<"Finished popping small queue." <<std::endl;
        
        TreeNode* large_prev = NULL;
        while (!larger.empty())
        {
            large_curr = larger.front();
            std::cout<<"popping large" <<std::endl;
            if(large_prev!=NULL){               
                std::cout<<"here: large_prev->val: " <<large_prev->val<<std::endl;
                large_prev->left = large_curr;
                std::cout<<"large_prev->val: " << large_prev->val << "'s left node = " << large_curr->val <<std::endl;
            }
            std::cout << "From large queue, pop: " << large_curr->val <<std::endl;
            larger.pop();
            if(!res[1])
                res[1] = large_curr;
            large_prev = large_curr;
        }
        if(large_prev)
            large_prev->left = NULL;
        return res;
    }
};
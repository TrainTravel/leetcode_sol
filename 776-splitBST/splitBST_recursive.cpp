#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode *> res(2, NULL);
        if(root == NULL) return res;

        if(root->val > V){
            res[1] = root;
            auto res1 = splitBST(root->left, V);
            root->left = res1[1];
            return {res1[0], root};
        }else{
            res[0] = root;
            auto res1 = splitBST(root->right, V);
            root->right = res1[0];
            return {root, res1[1]};
        }
    }       
};
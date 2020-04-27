#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
This problem is super hard for me.
After thinking all day, I gave up and saw that others also doubt why this problem is only "medium". See: https://leetcode.com/problems/split-bst/solution/

The solutions that I referred to:
https://leetcode.com/problems/split-bst/discuss/113798/C%2B%2BEasy-recursion-in-O(n)
https://leetcode.com/problems/split-bst/discuss/113801/Yet-another-short-recursive-c%2B%2B-solution-4ms

In a left subtree of the root, there might be some subtree that is larger than target key V. Finding the possible subtree(larger than V) in the left subtree of the root requires finding out the larger subtree of splitting the left subtree. Therefore, the problem can be recursively handled.
For python: https://leetcode.com/problems/split-bst/discuss/159985/Python-DFS-tm
**/

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

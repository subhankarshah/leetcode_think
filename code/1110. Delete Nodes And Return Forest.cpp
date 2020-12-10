// https://leetcode.com/problems/delete-nodes-and-return-forest

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* plantTrees(TreeNode* node, bool parentCut, unordered_set<int> &shouldDelete, vector<TreeNode*> &forest){
        if(node==NULL) return NULL;
        bool nodeCut = shouldDelete.find(node->val)!=shouldDelete.end();
        if(parentCut && !nodeCut)
            forest.push_back(node);
        node->left = plantTrees(node->left, nodeCut, shouldDelete, forest);
        node->right = plantTrees(node->right, nodeCut, shouldDelete, forest);
        return nodeCut ? NULL : node;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> shouldDelete(to_delete.begin(),to_delete.end());
        vector<TreeNode*> forest;
        plantTrees(root,true,shouldDelete,forest);
        return forest;
    }
};
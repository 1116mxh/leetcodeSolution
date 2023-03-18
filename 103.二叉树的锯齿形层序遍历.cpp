/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> Queue;
        Queue.push(root);
        bool target = true;
        while(!Queue.empty()){
            int size = Queue.size();
            deque<int> tempdeque;
            for(int i =0; i < size; i++){
                TreeNode* node = Queue.front();
                Queue.pop();
                if(!target){
                    tempdeque.push_front(node->val);
                }else{
                    tempdeque.push_back(node->val);
                }

                if(node->left) Queue.push(node->left);
                if(node->right) Queue.push(node->right);

            }
            target = !target;
            result.push_back(vector<int>{tempdeque.begin(),tempdeque.end()});
            
        }
        return result;
        

    }
};
// @lc code=end


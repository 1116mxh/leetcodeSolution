/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    int num;
    void recoverTree(TreeNode* root) {
        find(root,nullptr);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

    }

    // 中序遍历（二叉搜索树中序遍历后是一个递增有序数列）
    // 核心思想是，有两个数字位置交换时，会出现两种情况，一种是：两个数字是中序遍历中的相邻数字 另一种是：两个数字不相邻
    // 相邻情况下，交换两个数字即可
    // 不相邻情况下，会有两个位置不满足递增，且第一个位置 i > i+1中i是错误节点，第二个位置：i>i+1中i+1是错误位置
    // 所以交换第一个位置的i和第二个位置的i+1即可
    // 下面函数，root是根节点，last是上一个访问的节点
    TreeNode* find(TreeNode* root,TreeNode* last){

        // 如果左子树存在则上一个访问的节点是左节点
        if(root->left){
            last = find(root->left,last);
        }
        // 第一个访问的节点没有上一个节点所以要判断是否是第一个
        if(last && root->val < last->val){
            if(!first){
                first = last;
                second = root;
            }else{
                second = root;
            }
        }
        // 右节点的上一个访问节点是父节点，如果没有右节点，上一个访问的节点还是root
        last = root;
        if(root->right){
            // 如果有右节点上一个访问的节点是右节点
            last = find(root->right,root);
        }

        return last;

    }

};
// @lc code=end


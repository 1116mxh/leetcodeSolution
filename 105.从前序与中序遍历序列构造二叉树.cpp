/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

// 要先设置好边界条件， 本题设置左闭右闭区间
class Solution {
public:
    unordered_map<int,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        if(n == 0 ) return nullptr;
        
        // inorder映射关系
        for(int i = 0; i < inorder.size(); i++){
            index[inorder[i]] = i;
        }

        return help(preorder,inorder,0,0, n-1,n-1); 

    }

    TreeNode* help(vector<int>& preorder,vector<int>& inorder,int pstart,int istart,int pend,int iend){

        if(pstart > pend) return nullptr;

        TreeNode* root = new TreeNode(preorder[pstart]);

        int iroot = index[preorder[pstart]];

        root->left = help(preorder,inorder,pstart+1,istart,pstart+(iroot - istart),iroot-1);

        root->right = help(preorder,inorder,pstart+(iroot - istart)+1,iroot+1,pend,iend);

        return root;

    }
};
// @lc code=end


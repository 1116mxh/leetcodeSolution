/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    unordered_map<int,ListNode*> map;
    TreeNode* sortedListToBST(ListNode* head) {

        int length = 0;
        for(ListNode* i = head; i;length++){
            map[length] = i;
            i = i->next;
        }

        return buildTree(0,length);
        
    }

    TreeNode* buildTree(int start,int end){

        if(start >= end) return nullptr;

        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(map[mid]->val);

        root->left = buildTree(start,mid);
        root->right = buildTree(mid+1,end);

        return root;


    }
};
// @lc code=end


/*
    https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15
    This solution is wrong, continue to update!
    
    Need to read: Breath First Search or Deep First Search
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
    void handleInsertNode(TreeNode*& head, const vector<int>& newBranch, bool& isInsert) {
        if (head == nullptr || isInsert) {
            return;
        }
        // Parent position
        if (head->val == newBranch[0]) {
            TreeNode* newChild = new TreeNode(newBranch[1]);
            if (newBranch[2]) {
                head->left = newChild;
            } else {
                head->right = newChild;
            }
            isInsert = true;
            return;
        }
        else if (head->val == newBranch[1]) { // adding new parent from the left
            TreeNode* newParent = new TreeNode(newBranch[0]);
            newBranch[2] == 1 ? newParent->left = head : newParent->right = head;
            head = newParent;
            isInsert = true;
            return;
        }

        handleInsertNode(head->left, newBranch, isInsert);
        handleInsertNode(head->right, newBranch, isInsert);
    }
    void addChild(TreeNode*& head,const vector<int>& newBranch) {
        if (head == nullptr) {
            cout << "Go here!! " << endl;
            TreeNode* parentNode = new TreeNode(newBranch[0]);
            TreeNode* childNode = new TreeNode(newBranch[1]);
            if (newBranch[2]) {
                parentNode->left = childNode;
            }
            else {
                parentNode->right = childNode;
            }
            head = parentNode;
            return;
        }
        else {
            bool isInserted = false;
            handleInsertNode(head, newBranch, isInserted);
        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* head = nullptr;
        for (auto d : descriptions) {
            addChild(head, d);
        }
        return head;
    }
};

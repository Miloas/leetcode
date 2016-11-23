/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    void update(TreeNode *root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode *root) {
       update(root); 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       return !st.empty(); 
    }

    /** @return the next smallest number */
    int next() {
        auto p = st.top();st.pop();
        update(p->right);
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
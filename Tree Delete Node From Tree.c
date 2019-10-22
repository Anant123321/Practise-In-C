typedef struct TreeNode TreeNode;
int findmin(TreeNode * root)
{
    if(root->left)return findmin(root->left);
    else return root->val;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root==NULL)return NULL;
    if(key<root->val)root->left=deleteNode(root->left,key);
    if(key>root->val)root->right=deleteNode(root->right,key);
    else if(root->val==key)
    {
        if(root->left==NULL && root->right==NULL)return NULL;
        if(root->left && root->right==NULL)return root->left;
        if(root->left==NULL && root->right)return root->right;
        int val1=findmin(root->right);
        root->val=val1;
        root->right=deleteNode(root->right,val1);
    }
    return root;
}


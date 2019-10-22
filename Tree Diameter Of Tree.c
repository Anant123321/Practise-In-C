int max(int a,int b)
{
    if(a>b)return a;
    else
        return b;
}
int maxheight(struct TreeNode* root)
{
 if(root==NULL)return 0;
    return 1+max(maxheight(root->left),maxheight(root->right));
}
int func(struct TreeNode * root)
{
     if(root==NULL)return 0;
    int a=maxheight(root->left)+maxheight(root->right);
    int b=max(func(root->left),func(root->right));
    return max(a,b);
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return 0;
    return func(root);
}

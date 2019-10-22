
    
    void func(Node * root)
    {
        if(root==NULL)return;

        queue<pair<Node*,int>> q;
        pair <Node*,int> pp;
        pp.first=root;
        pp.second=0;
        q.push(pp);
        int i=0;
        int arr[1001];
        for(i=0;i<1001;i++)arr[i]=-5000;
        vector<int>brr;
        while(!q.empty())
        {
           pair<Node*,int> p=q.front();
           Node *n = p.first;
           int j=p.second;
           q.pop();
           //printf("%d ",n->data);
           if(arr[500+j]==-5000)
           {
               arr[500+j]=n->data;               
           }
           if(n->right)
           {
               pair <Node*,int> pp;
                pp.first=n->right;
                pp.second=j+1;
                q.push(pp);
           }
           if(n->left)
           {
               pair <Node*,int> pp;
                pp.first=n->left;
                pp.second=j-1;
                q.push(pp);
           }
        }
        for(i=0;i<1001;i++)
        if(arr[i]!=-5000)
        printf("%d ",arr[i]);

    }
    void topView(Node * root) {
        if(root==NULL)return;
        func(root);
    }

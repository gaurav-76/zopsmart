
// Preorder

void pre(node *root)
{
  stack<node*>st;
  node *p = root;


  while( p!=NULL || !st.empty())
  {
    

    if(p!=NULL)
    {
      cout<<p->data<<" ";
      st.push(p);
      p = p->lchild;

    }
    else
    {
      p = st.top();
      st.pop();
      p = p->rchild;
    }

  }

}

// inorder

void in(node *root)
{
  node *p = root;

  stack<node*>st;

  while(!st.empty() || p!=NULL)
  {
    if(p!=NULL)
    {
      st.push(p);
      p=p->lchild;
    }

    else
    {
      p = st.top();
      st.pop();
      cout<<p->data<<" ";
      p = p->rchild;
    }
  }
}

// postorder 2 stack

void pos(node *root)
{
  node *p ;

  stack<node*>s1;
  stack<int>s2;

  s1.push(root);

  while(!s1.empty())
  {
      p = s1.top();
      s1.pop();

      s2.push(p->data);

      if(p->lchild)
      {
        s1.push(p->lchild);
      }
      if(p->rchild)
      {
        s1.push(p->rchild);
      }
  }

  while(!s2.empty())
  {
    cout<<s2.top()<<" ";
    s2.pop();
  }
}


   // one stack

vector<int> postOrderIterative(struct Node* root)
{
    vector<int> postOrderList;
   
    if (root == NULL)
        return postOrderList;
   
    stack<Node*> S;
    S.push(root);
    Node* prev = NULL;
    while (!S.empty()) {
        auto current = S.top();
       
        if (prev == NULL || prev->left == current
            || prev->right == current) {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
     
        }
 
        else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
 
   
        }
        else if (current->right == prev) {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}
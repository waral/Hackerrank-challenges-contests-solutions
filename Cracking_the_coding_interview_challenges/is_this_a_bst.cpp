/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
bool contains(Node* root, int number)
    {
    if(root == NULL) return false;
    if(root->data == number || contains(root->left,number) || contains(root->right,number)) return true;
    return false;
}

bool duplicate(Node* root)
    {
    if(root == NULL) return false;
    if(contains(root->left, root->data) || contains(root->right, root->data) || duplicate(root->left) || duplicate(root->right)) return true;
    return false;
    
}


bool checkBST(Node* root) {
    
    if(root==NULL) return true;
    if(duplicate(root)) return false;
    
    if(root->left==NULL && root->right==NULL)
            return true;
       
       if(root->left == NULL && root->right!=NULL)
           {
           if(root->right->data > root->data && checkBST(root->right)) return true;
           else return false;
           }
  
       
       if(root->right ==NULL && root->left!=NULL)
           {
           if(root->left->data < root->data && checkBST(root->left)) return true;
           else return false;
       }
       if(root->left->data == root->right->data)
           return false;
       
       if(root->left->data < root->data && root->right->data > root->data && checkBST(root->left) && checkBST(root->right)) return true;
 
        return false;
   }

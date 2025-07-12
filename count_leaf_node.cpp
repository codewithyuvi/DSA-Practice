/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

void inOrder(BinaryTreeNode<int> *root, int &count){
    //base case
    if(root == NULL){
        return;
    }


    //LNR
    inOrder(root->left, count);//L
    
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    
    inOrder(root->right, count);//R
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    inOrder(root, cnt);

    return cnt;
}
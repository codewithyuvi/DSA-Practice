#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};
node* buildTree(node* root){

    cout << "Enter the data:" << endl;
    int data;
    cin >> data;

    root = new node(data);
    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left" << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right" << data << endl;
    root->right= buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q; 
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){ //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()){ //queue still has some child nodes.
                q.push(NULL);
            }
        }

        else{
            cout << temp -> data << " ";
            
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root){
    
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    inorder(root->left); // L
    cout << root->data << " "; // N
    inorder(root->right); // R
}

void preorder(node* root){
    
    //base case
    if(root == NULL){
        return;
    }

    //NLR
    cout << root->data << " "; // N
    preorder(root->left); // L
    preorder(root->right); // R
}

void postorder(node* root){
    
    //base case
    if(root == NULL){
        return;
    }

    //LRN
    postorder(root->left); // L
    postorder(root->right); // R
    cout << root->data << " "; // N
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter a data for root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }

    }
}

int main(){
    node* root = NULL;
    // 5 3 1 -1 -1 -1 2 -1 -1
    //create a tree
    // root = buildTree(root);    

    // //level order 
    // cout << "Printing the level order traversal output " << endl;
    // levelOrderTraversal(root);

    // cout << "inorder traversal is: ";
    // inorder(root);

    // cout << "preorder traversal is: ";
    // preorder(root);

    // cout << "postorder traversal is: ";
    // postorder(root);

    buildFromLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);


}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
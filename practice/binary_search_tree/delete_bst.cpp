#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *right,*left;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* inordersucc(Node* root){
    Node* curr=root;
    while(curr and curr->left!=NULL){
        curr=curr->left;
    }
    return curr;

}
Node* deletebst(Node* root,int key){
    if(key<root->data){
        root->left=deletebst(root->left,key);
    }
    else if(key>root->data){
        root->right=deletebst(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deletebst(root->right,temp->data);

    }
    return root;

}

int main(){

Node* root=new Node(4);
root->left=new Node(2);
root->right=new Node(5);
root->left->left=new Node(1);
root->left->right=new Node(3);
root->right->right=new Node(6);
inorder(root);
cout<<endl;
root=deletebst(root,2);
inorder(root);

return 0;
}
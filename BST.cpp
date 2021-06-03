#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

bool find(node* root, int left, int right){
    if(root == NULL){
        return true;
    }
    return left < root->data &&
            right > root->data &&
            find(root->left, left, root->data) &&
            find(root->right, root->data, right);
}


bool isBST(node* root){
    if(root == NULL){
        return true;
    }
    return find(root, INT16_MIN, INT16_MAX);
}



struct node* inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return NULL;
}

struct node* insertBST(struct node* root, int x){

    if(x <= root->data && root->left == NULL){
        root->left = new node(x);
        return root;
    }
    else if(x > root->data && root->right == NULL){
        root->right = new node(x);
        return root;
    }
    else if(x <= root->data){
        insertBST(root->left, x);
    }
    else{
        insertBST(root->right, x);
    }

}

struct node* searchBST(struct node* root, int x){
    if(root == NULL){
        cout<<"False"<<endl;
        return NULL;
    }
    else if(root->data == x){
        cout<<"True"<<endl;
        return NULL;
    }
    else if(x <= root->data){
        searchBST(root->left, x);
    }
    else{
        searchBST(root->right, x);
    }
}

struct node* minValueNode(struct node* root){
    struct node* current = root;
    while (current->left != NULL)
    {   
        current = current->left;
    }
    return current;
    
} 

struct node* deleteBST(struct node* root, int x){
    if(root == NULL){
        return root;
    }
    if(x < root->data){
        deleteBST(root->left, x);
    }
    else if(x > root->data){
        deleteBST(root->right, x);
    }
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {   
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, x);
        
    }
    return root;
}

int main(){
    struct node* root = new node(8);
    root->left = new node(2);
    root->right = new node(9);
    root->left->left = new node(1);
    root->left->right = new node(5);
    int data;
    cin>>data;

    while (data != 0)
    {
        insertBST(root,data);
        inorder(root);
        cin>>data;
    }
    
    
    insertBST(root, 7);
    inorder(root);
    searchBST(root,10);
    deleteBST(root, 2);
    inorder(root);
    cout<<isBST(root);

}

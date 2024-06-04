#include<iostream>

using namespace std;

class Tree{
    private:
        int data;
        Tree *left, *right;
    public:
        Tree* create_Tree(){
            Tree *new_node = new Tree;
            int value;
            cout << "enter value ";
            cin >> value;
            if (value==-1)
            {
                return NULL;
            }
            new_node->data = value;

            cout << "Left Child of " << value << " [-1 for no child]\n";
            new_node->left = create_Tree();

            cout << "Right Child of " << value << " [-1 for no child]\n";
            new_node->right = create_Tree();

            return new_node;
        }

        // Traversal Methods
        void Inorder(Tree* root){
            if (root!=NULL)
            {
                Inorder(root->left);
                cout << root->data << " ";
                Inorder(root->right);
            }
        }
        void Preorder(Tree* root){
            if (root!=NULL)
            {
                cout << root->data << " ";
                Preorder(root->left);
                Preorder(root->right);
            }
        }
        void PostOrder(Tree* root){
            if (root!=NULL)
            {
                PostOrder(root->left);
                PostOrder(root->right);
                cout << root->data << " ";
            }   
        }
        void freeTree(struct Tree *root)
        {
            if (root != NULL)
            {
                freeTree(root->left);
                freeTree(root->right);
                delete root;
            }
        }
};


int main()
{
    Tree t1, *root;
    root = new Tree;

    root = t1.create_Tree();
    t1.Inorder(root);
    cout << endl;
    t1.Preorder(root);
    cout << endl;
    t1.PostOrder(root);

    t1.freeTree(root);

    return 0;
}

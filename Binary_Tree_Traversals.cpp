#include <iostream>
using namespace std;
class Node
{
public:
char data;
Node *left, *right;
Node(char value)
{
data = value;
left = right = nullptr;
}
};
class BinaryTree
{
Node *root;
void preorder(Node *p)
{
if (p == nullptr)
return;
cout << p->data << " ";
preorder(p->left);
preorder(p->right);
}
void inorder(Node *p)
{
if (p == nullptr)
return;
inorder(p->left);
cout << p->data << " ";
inorder(p->right);
}
void postorder(Node *p)
{
if (p == nullptr)
return;
postorder(p->left);
postorder(p->right);
cout << p->data << " ";
}
public:
BinaryTree()
{
root = new Node('A');
root->left = new Node('B');
root->right = new Node('C');
root->left->left = new Node('D');
root->left->right = new Node('E');
}


void displayPreorder()
{
cout << "Preorder: ";
preorder(root);
cout << endl;
}
void displayInorder()
{
cout << "Inorder: ";
inorder(root);
cout << endl;
}
void displayPostorder()
{
cout << "Postorder: ";
postorder(root);
cout << endl;
}
};
int main()
{
BinaryTree tree;
tree.displayPreorder();
tree.displayInorder();
tree.displayPostorder();
return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
int data;
Node *left, *right;
Node(int value)
{
data = value;
left = right = nullptr;
}
};
class BST
{
Node *root;
Node* insert(Node *p, int value)
{
if (p == nullptr)
return new Node(value);
if (value < p->data)
p->left = insert(p->left, value);
else if (value > p->data)
p->right = insert(p->right, value);
return p;
}
Node* search(Node *p, int key)
{
if (p == nullptr || p->data == key)
return p;
if (key < p->data)
return search(p->left, key);
return search(p->right, key);
}
Node* minimumNode(Node *p)
{
while (p != nullptr && p->left != nullptr)
p = p->left;


return p;
}
Node* maximumNode(Node *p)
{
while (p != nullptr && p->right != nullptr)
p = p->right;
return p;
}
Node* deleteNode(Node *p, int key)
{
if (p == nullptr)
return p;
if (key < p->data)
p->left = deleteNode(p->left, key);
else if (key > p->data)
p->right = deleteNode(p->right, key);
else
{
// Case 1 and 2: zero or one child
if (p->left == nullptr)
{
Node *temp = p->right;
delete p;
return temp;
}
else if (p->right == nullptr)
{
Node *temp = p->left;
delete p;
return temp;
}
// Case 3: two children
Node *temp = minimumNode(p->right);
p->data = temp->data;
p->right = deleteNode(p->right, temp->data);
}
return p;
}
int height(Node *p)
{
if (p == nullptr)
return 0;
return 1 + max(height(p->left), height(p->right));
}
void inorder(Node *p)
{
if (p == nullptr)
return;
inorder(p->left);
cout << p->data << " ";
inorder(p->right);
}


public:
BST()
{
root = nullptr;
}
void insertValue(int value)
{
root = insert(root, value);
}
void searchValue(int key)
{
if (search(root, key) != nullptr)
cout << key << " found in BST\n";
else
cout << key << " not found in BST\n";
}
void deleteValue(int key)
{
if (search(root, key) == nullptr)
cout << key << " not found; cannot delete\n";
else
{
root = deleteNode(root, key);
cout << key << " deleted successfully\n";
}
}
void displayMinimum()
{
Node *p = minimumNode(root);
if (p == nullptr)
cout << "Tree is empty\n";
else
cout << "Minimum: " << p->data << endl;
}
void displayMaximum()
{
Node *p = maximumNode(root);
if (p == nullptr)
cout << "Tree is empty\n";
else
cout << "Maximum: " << p->data << endl;
}
void displayHeight()
{
cout << "Height: " << height(root) << endl;
}
void display()
{
cout << "Inorder: ";
inorder(root);
cout << endl;
}
};


int main()
{
BST tree;
int choice, value;
do
{
cout << "\n--- BST Operations ---\n";
cout << "1. Insert\n2. Delete\n3. Search\n";
cout << "4. Minimum\n5. Maximum\n6. Height\n";
cout << "7. Display\n0. Exit\n";
cout << "Enter choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "Enter value: ";
cin >> value;
tree.insertValue(value);
break;
case 2:
cout << "Enter value to delete: ";
cin >> value;
tree.deleteValue(value);
break;
case 3:
cout << "Enter value to search: ";
cin >> value;
tree.searchValue(value);
break;
case 4:
tree.displayMinimum();
break;
case 5:
tree.displayMaximum();
break;
case 6:
tree.displayHeight();
break;
case 7:
tree.display();
break;
case 0:
cout << "Program terminated\n";
break;
default:
cout << "Invalid choice\n";
}
} while (choice != 0);
return 0;
}

#include <iostream>
using namespace std;
class LinkedList
{
struct Node
{
int data;
Node* next;
};
Node* head;
public:
LinkedList()
{
head = NULL;
}


// Insert at the end
void insert(int value)
{
Node* newNode = new Node;
newNode->data = value;
newNode->next = NULL;
if (head == NULL)
head = newNode;
else
{
Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
}
// Delete a node by value
void deleteNode(int value)
{
Node* temp = head;
Node* prev = NULL;
while (temp != NULL && temp->data != value)
{
prev = temp;
temp = temp->next;
}
if (temp == NULL)
{
cout << "Element not found\n";
return;
}
if (prev == NULL)
head = temp->next;
else
prev->next = temp->next;
delete temp;
cout << "Node deleted\n";
}
// Search an element
void search(int value)
{
Node* temp = head;
while (temp != NULL)
{
if (temp->data == value)
{
cout << "Element found\n";
return;
}
temp = temp->next;
}


cout << "Element not found\n";
}
// Reverse the linked list
void reverse()
{
Node* prev = NULL;
Node* curr = head;
Node* next = NULL;
while (curr != NULL)
{
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}
head = prev;
cout << "List reversed\n";
}
// Display the list
void display()
{
Node* temp = head;
while (temp != NULL)
{
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL\n";
}
};
int main()
{
LinkedList list;
list.insert(10);
list.insert(20);
list.insert(30);
cout << "Original list: ";
list.display();
list.search(20);
list.deleteNode(20);
cout << "After deletion: ";
list.display();
list.reverse();
cout << "After reversing: ";
list.display();
return 0;
}

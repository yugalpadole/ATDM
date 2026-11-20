#include <iostream>
using namespace std;
class DoublyList
{
struct Node
{
int data;
Node* prev;
Node* next;
};
Node* head;
public:
DoublyList()
{


head = NULL;
}
// Insert at the end
void insert(int value)
{
Node* newNode = new Node;
newNode->data = value;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL)
head = newNode;
else
{
Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}
}
// Delete a node by value
void deleteNode(int value)
{
Node* temp = head;
while (temp != NULL && temp->data != value)
temp = temp->next;
if (temp == NULL)
{
cout << "Element not found\n";
return;
}
if (temp->prev != NULL)
temp->prev->next = temp->next;
else
head = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
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
// Display forward
void displayForward()
{
Node* temp = head;
cout << "Forward: ";
while (temp != NULL)
{
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
// Display backward
void displayBackward()
{
if (head == NULL)
{
cout << "List is empty\n";
return;
}
Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
cout << "Backward: ";
while (temp != NULL)
{
cout << temp->data << " ";
temp = temp->prev;
}
cout << endl;
}
};
int main()
{
DoublyList list;
list.insert(10);
list.insert(20);
list.insert(30);
list.displayForward();
list.displayBackward();
list.search(20);
list.deleteNode(20);


list.displayForward();
list.displayBackward();
return 0;
}

#include <iostream>
using namespace std;
class Queue
{


int a[5];
int front, rear;

public:
Queue()
{
front = -1;
rear = -1;
}
void enqueue(int x)
{
if (rear == 4)
{
cout << "Queue is Full\n";
return;
}
if (front == -1)
front = 0;
a[++rear] = x;
cout << x << " inserted\n";
}
void dequeue()
{
if (front == -1)
{
cout << "Queue is Empty\n";
return;
}
cout << "Deleted: " << a[front] << endl;
if (front == rear)
{
front = rear = -1;
}
else
{
front++;
}
}
void display()
{
if (front == -1)
{
cout << "Queue is Empty\n";
return;
}
cout << "Queue elements: ";
for (int i = front; i <= rear; i++)
cout << a[i] << " ";
cout << endl;
}
};


int main()
{
Queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.display();
q.dequeue();
q.display();
return 0;
}

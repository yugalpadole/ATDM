#include <iostream>
using namespace std;
class Practical
{
int a[5];
int top;
public:
Practical()
{
top = -1;
}
// ADT: Stack operations
void push(int x)
{
if (top == 4)
cout << "Stack is Full\n";
else
a[++top] = x;
}
void pop()
{
if (top == -1)
cout << "Stack is Empty\n";
else
cout << "Deleted element: " << a[top--] << endl;
}


void display()
{
cout << "Stack elements: ";
for (int i = top; i >= 0; i--)
cout << a[i] << " ";
cout << endl;
}
// Time Complexity Analysis: O(n)
void timeAnalysis(int n)
{
int count = 0;
for (int i = 1; i <= n; i++)
count++;
cout << "Number of iterations: " << count << endl;
cout << "Time Complexity: O(n)" << endl;
}
// Recursion: Factorial
int factorial(int n)
{
if (n <= 1)
return 1;
return n * factorial(n - 1);
}
};
int main()
{
Practical obj;
int n;
// ADT
cout << "--- Stack ADT ---" << endl;
obj.push(10);
obj.push(20);
obj.push(30);
obj.display();
obj.pop();
obj.display();
// Time Complexity Analysis
cout << "\n--- Time Complexity ---" << endl;
obj.timeAnalysis(5);
// Recursion
cout << "\n--- Recursion ---" << endl;
cout << "Enter a number for factorial: ";
cin >> n;
if (n < 0)
cout << "Enter a non-negative number";
else
cout << "Factorial = " << obj.factorial(n);
return 0;
}

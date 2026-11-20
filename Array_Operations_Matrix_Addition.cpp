#include <iostream>
using namespace std;
class ArrayMatrix
{
int a[10], n;
public:
void input()
{
cout << "Enter array size: ";
cin >> n;
cout << "Enter array elements: ";
for (int i = 0; i < n; i++)
cin >> a[i];
}
// Array Traversal
void traversal()
{


cout << "Array: ";
for (int i = 0; i < n; i++)
cout << a[i] << " ";
cout << endl;
}
// Array Insertion
void insertion()
{
int pos, value;
cout << "Enter position and value: ";
cin >> pos >> value;
if (pos < 1 || pos > n + 1 || n == 10)
{
cout << "Invalid position or array full\n";
return;
}
for (int i = n; i >= pos; i--)
a[i] = a[i - 1];
a[pos - 1] = value;
n++;
cout << "After insertion: ";
traversal();
}
// Array Deletion
void deletion()
{
int pos;
cout << "Enter position to delete: ";
cin >> pos;
if (pos < 1 || pos > n)
{
cout << "Invalid position\n";
return;
}
for (int i = pos - 1; i < n - 1; i++)
a[i] = a[i + 1];
n--;
cout << "After deletion: ";
traversal();
}
// Linear Searching
void searching()
{
int key, i;
cout << "Enter element to search: ";
cin >> key;


for (i = 0; i < n; i++)
{
if (a[i] == key)
{
cout << "Element found at position "
<< i + 1 << endl;
return;
}
}
cout << "Element not found\n";
}
// Matrix Addition
void matrixAddition()
{
int x[3][3], y[3][3], z[3][3];
cout << "Enter first 3x3 matrix:\n";
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
cin >> x[i][j];
cout << "Enter second 3x3 matrix:\n";
for (int i = 0; i < 3; i++)
for (int j = 0; j < 3; j++)
cin >> y[i][j];
cout << "Sum of matrices:\n";
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
z[i][j] = x[i][j] + y[i][j];
cout << z[i][j] << " ";
}
cout << endl;
}
}
};
int main()
{
ArrayMatrix obj;
cout << "--- Array Operations ---\n";
obj.input();
obj.traversal();
obj.insertion();
obj.deletion();
obj.searching();
cout << "\n--- Matrix Addition ---\n";
obj.matrixAddition();
return 0;
}

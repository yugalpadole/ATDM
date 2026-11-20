#include <iostream>
using namespace std;
class Searching
{
int a[10], n;
public:
void input()
{
cout << "Enter number of elements: ";
cin >> n;
cout << "Enter elements in sorted order: ";
for (int i = 0; i < n; i++)
cin >> a[i];
}


void linearSearch(int key)
{
for (int i = 0; i < n; i++)
{
if (a[i] == key)
{
cout << "Linear Search: Element found at position "
<< i + 1 << endl;
return;
}
}
cout << "Linear Search: Element not found\n";
}
void binarySearch(int key)
{
int low = 0, high = n - 1;
while (low <= high)
{
int mid = low + (high - low) / 2;
if (a[mid] == key)
{
cout << "Binary Search: Element found at position "
<< mid + 1 << endl;
return;
}
else if (key < a[mid])
high = mid - 1;
else
low = mid + 1;
}
cout << "Binary Search: Element not found\n";
}
};
int main()
{
Searching s;
int key;
s.input();
cout << "Enter element to search: ";
cin >> key;
s.linearSearch(key);
s.binarySearch(key);
return 0;
}

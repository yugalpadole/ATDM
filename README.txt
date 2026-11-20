ATDM C++ PRACTICAL PROGRAMS
===========================

This folder contains separate C++ source files extracted from the uploaded ATDM lab manual.
Each .cpp file is an independent program. Open and compile one file at a time.

FILES
-----
01_ADT_Time_Complexity_Recursion.cpp
02_Array_Operations_Matrix_Addition.cpp
03_Singly_Linked_List.cpp
04_Doubly_Linked_List.cpp
05_Queue_Array.cpp
06_Linear_and_Binary_Search.cpp
07_Binary_Tree_Traversals.cpp
08_Binary_Search_Tree.cpp
09_Binary_Search_Tree_Alternative.cpp
10_Graph_BFS_DFS.cpp
11_Student_Record_Management_System.cpp

NOTES
-----
- The programs are based on the source code sections in codes(1).pdf.
- The source manual's detailed Assignment No. 07 is Binary Tree Traversals. The assignment index near the beginning lists Sorting Algorithms for No. 07, so the manual has an internal numbering/content mismatch.
- No Bubble Sort, Selection Sort, or Insertion Sort source program was present in the extracted program sections, so no substitute was silently added.
- The queue source found in the manual is an array-based queue.
- Some line breaks inside a C++ string literal caused by PDF text extraction were repaired so the graph program compiles.
- Tested with g++ using C++17 syntax checking. Compile/run each source file separately.

COMPILE EXAMPLE
---------------
g++ -std=c++17 01_ADT_Time_Complexity_Recursion.cpp -o program
./program

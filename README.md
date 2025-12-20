Overview
This project implements various sorting algorithms in C, analyzing their time complexity and performance characteristics. It covers fundamental sorting techniques with detailed analysis of Big O notation for algorithm evaluation.

Table of Contents:
Algorithm Implementations
Big O Notation Analysis
File Organization
Algorithm Properties
Compilation and Usage
Performance Characteristics

Algorithms
1. Bubble Sort
File: 0-bubble_sort.c
Prototype: void bubble_sort(int *array, size_t size);
Type: Comparison, in-place, stable
Complexity: 0-O

2. Insertion Sort (Linked List)
File: 1-insertion_sort_list.c
Prototype: void insertion_sort_list(listint_t **list);
Type: Comparison, in-place, stable
Complexity: 1-O

3. Selection Sort
File: 2-selection_sort.c
Prototype: void selection_sort(int *array, size_t size);
Type: Comparison, in-place, not stable
Complexity: 2-O

4. Quick Sort (Lomuto Partition)
File: 3-quick_sort.c
Prototype: void quick_sort(int *array, size_t size);
Type: Comparison, in-place, not stable
Complexity: 3-O

Big O Analysis
Algorithm	Best	Average	Worst	Space
Bubble Sort	O(n)	O(n²)	O(n²)	O(1)
Insertion Sort	O(n)	O(n²)	O(n²)	O(1)
Selection Sort	O(n²)	O(n²)	O(n²)	O(1)
Quick Sort	O(n log n)	O(n log n)	O(n²)	O(log n)
Project Structure
Core Files
sort.h - Main header with prototypes and structures

print_array.c - Array printing utility

print_list.c - List printing utility

Implementation Files
0-bubble_sort.c - Bubble sort for arrays

1-insertion_sort_list.c - Insertion sort for lists

2-selection_sort.c - Selection sort for arrays

3-quick_sort.c - Quick sort with Lomuto partition

Complexity Files
0-O, 1-O, 2-O, 3-O - Big O notation files

Data Structure
c
/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to previous element
 * @next: Pointer to next element
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
Compilation
bash

# Bubble Sort
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    0-bubble_sort.c print_array.c 0-main.c -o bubble

# Insertion Sort (List)
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    1-insertion_sort_list.c print_list.c 1-main.c -o insertion

# Selection Sort
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    2-selection_sort.c print_array.c 2-main.c -o selection

# Quick Sort
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    3-quick_sort.c print_array.c 3-main.c -o quick
Algorithm Properties
Property	Bubble	Insertion	Selection	Quick
Comparison	Yes	Yes	Yes	Yes
In-place	Yes	Yes	Yes	Yes
Stable	Yes	Yes	No	No
Adaptive	Yes	Yes	No	No
When to Use
Use Case	Recommended Algorithm
Educational	Bubble Sort, Selection Sort
Small datasets (< 20)	Insertion Sort
Nearly sorted data	Insertion Sort, Bubble Sort
Linked lists	Insertion Sort
General purpose	Quick Sort
Memory constraints	Selection Sort
Stability needed	Insertion Sort, Bubble Sort
Testing
Each algorithm has a corresponding *-main.c file that:

Shows initial unsorted data

Visualizes sorting process

Displays final sorted result

Key Concepts
1. Algorithm Analysis
Time and space complexity

Big O notation (best/average/worst cases)

Empirical vs theoretical analysis

2. Design Patterns
Iterative approaches (Bubble, Selection, Insertion)

Divide and conquer (Quick Sort)

Comparison-based sorting

3. Data Structures
Array-based algorithms

Linked list algorithms

Pointer manipulation

4. Implementation
Memory management in C

Pointer arithmetic

Testing strategies

Glossary:
Big O Notation - Describes algorithm complexity as input grows
Time Complexity - How runtime scales with input size
Space Complexity - Memory usage scaling
In-place - No extra data structures needed
Stable - Preserves order of equal elements
Comparison Sort - Uses comparison operations
Divide and Conquer - Recursive problem splitting
Adaptive - Efficient with partially sorted data
Lomuto Partition - Quick Sort scheme using last element as pivot
Recursion - Function calling itself

Authors:
-Afnan Mohammed AlFaidi, alfaidi.afnan@gmail.com 
-Lara Mubarak Alzannan, laradreamer79@gmail.com 

Holberton school by Tuwaiq academy 2025


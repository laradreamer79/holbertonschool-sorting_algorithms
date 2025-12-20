# Sorting Algorithms in C

---

## Overview
This project explores the design and implementation of **sorting algorithms** using the C programming language.  
It demonstrates how different algorithms organize data, highlights their strengths and weaknesses, and compares their performance using **time complexity analysis**.

The project includes sorting techniques that operate on both **arrays** and **doubly linked lists**, allowing practical experience with pointer manipulation, memory management, and algorithm optimization.  
Through these implementations, the project emphasizes understanding **when and why** a particular sorting method should be used based on the input size and data characteristics.

---

## Data Structures

### Doubly Linked List
```c
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

### File Organization

| **File Name**              | **Description**                                |
| -------------------------- | ---------------------------------------------- |
| `sort.h`                   | Function prototypes and data structures        |
| `print_array.c`            | Utility function to print an array             |
| `print_list.c`             | Utility function to print a doubly linked list |
| `0-bubble_sort.c`          | Bubble Sort algorithm (array)                  |
| `1-insertion_sort_list.c`  | Insertion Sort algorithm (doubly linked list)  |
| `2-selection_sort.c`       | Selection Sort algorithm (array)               |
| `3-quick_sort.c`           | Quick Sort using Lomuto partition scheme       |
| `100-shell_sort.c`         | Shell Sort algorithm                           |
| `101-cocktail_sort_list.c` | Cocktail Shaker Sort (doubly linked list)      |
| `102-counting_sort.c`      | Counting Sort algorithm                        |
| `103-merge_sort.c`         | Merge Sort algorithm                           |

### Time Complexity Summary

| **Algorithm**  | **Best Case** | **Average Case** | **Worst Case** | **Stable** |
| -------------- | ------------- | ---------------- | -------------- | ---------- |
| Bubble Sort    | O(n)          | O(n²)            | O(n²)          | Yes        |
| Insertion Sort | O(n)          | O(n²)            | O(n²)          | Yes        |
| Selection Sort | O(n²)         | O(n²)            | O(n²)          | No         |
| Quick Sort     | O(n log n)    | O(n log n)       | O(n²)          | No         |
| Shell Sort     | Depends       | Depends          | Depends        | No         |
| Counting Sort  | O(n + k)      | O(n + k)         | O(n + k)       | Yes        |
| Merge Sort     | O(n log n)    | O(n log n)       | O(n log n)     | Yes        |

### Compilation Example

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
0-bubble_sort.c 0-main.c print_array.c -o bubble

### Usage
./bubble

### Author 
**Lara Alzannan And Afnan Alfaidi**



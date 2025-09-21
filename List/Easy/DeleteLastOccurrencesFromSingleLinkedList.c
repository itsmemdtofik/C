/**
Given a singly linked list and a key, the task is to delete the last occurrence of that key in the linked list.

Examples:

Input: head: 1 -> 2 -> 3 ->1  -> 4 -> NULL, key = 1
Output: 1 -> 2 -> 3 -> 4 -> NULL

Approach: The idea is to traverse the linked list from beginning to end.
While traversing, keep track of last occurrence key node and previous node of that key.
After traversing the complete list, delete the last occurrence of that key.

Time Complexity: O(n), Traversing over the linked list of size n.
Auxiliary Space: O(1)
*/

#include <stdio.h>
#include "Node.h"


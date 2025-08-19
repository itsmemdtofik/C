#include <stdio.h>
#include <stdlib.h>

// Naive approach: O(n*k)
void firstNegativeNaive(int nums[], int n, int k) {
    printf("Naive approach result: ");
    for (int i = 0; i <= n - k; i++) {
        int found = 0;
        for (int j = i; j < i + k; j++) {
            if (nums[j] < 0) {
                printf("%d ", nums[j]);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("0 ");
    }
    printf("\n");
}

// Optimized sliding window approach using deque
typedef struct {
    int *data;
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq, int size) {
    dq->data = (int *) malloc(size * sizeof(int));
    dq->front = 0;
    dq->rear = 0;
}

int isEmpty(Deque *dq) {
    return dq->front == dq->rear;
}

void pushBack(Deque *dq, int val) {
    dq->data[dq->rear++] = val;
}

void popFront(Deque *dq) {
    if (!isEmpty(dq))
        dq->front++;
}

int getFront(Deque *dq) {
    return dq->data[dq->front];
}

void firstNegativeOptimized(int nums[], int n, int k) {
    printf("Optimized approach result: ");
    Deque dq;
    initDeque(&dq, n);

    for (int i = 0; i < n; i++) {
        // Remove indices out of current window
        while (!isEmpty(&dq) && getFront(&dq) < i - k + 1)
            popFront(&dq);

        // If current number is negative, store its index
        if (nums[i] < 0)
            pushBack(&dq, i);

        // When window is fully formed
        if (i >= k - 1) {
            if (!isEmpty(&dq))
                printf("%d ", nums[getFront(&dq)]);
            else
                printf("0 ");
        }
    }
    printf("\n");
    free(dq.data);
}

int main() {
    int nums[] = {-8, 2, 3, -6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    firstNegativeNaive(nums, n, k);

    int nums1[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = 3;

    firstNegativeOptimized(nums1, n1, k1);

    return 0;
}

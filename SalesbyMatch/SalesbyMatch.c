#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct stack
{
    int maxsize;
    int top;
    int *items;
};

struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}

int size(struct stack *pt)
{
    return pt->top + 1;
}

int isEmpty(struct stack *pt)
{
    return pt->top == -1;
}

int isFull(struct stack *pt)
{
    return pt->top == pt->maxsize - 1;
}

void push(struct stack *pt, int x)
{
    if (isFull(pt))
    {
        return -1;
    }
    pt->items[++pt->top] = x;
}

int peek(struct stack *pt)
{
    if (!isEmpty(pt))
    {
        return pt->items[pt->top];
    }
    else
    {
        return -1;
    }
}

int pop(struct stack *pt)
{
    if (isEmpty(pt))
    {
        return -1;
    }
    return pt->items[pt->top--];
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_inx;
    
    for(i = 0; i < n-1; i++)
    {
        min_inx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_inx])
            {
                min_inx = j;
            }
        }
        swap(&arr[min_inx], &arr[i]);
    }
}

int sockMerchant(int n, int ar_count, int* ar)
{
    int p_count = 0;
    int sock;
    int pair_index = 0;
    
    struct stack *stackp = newStack(ar_count);
    
    //sort the array
    selectionSort(ar, ar_count);
    int index = 0;
    push(stackp, ar[0]);

    for(int i = 1; i < ar_count; i++)
    {
        if (peek(stackp) == ar[i])
        {
            pop(stackp);
            p_count++;
        }
        else 
        {
            push(stackp, ar[i]);
        }
    }
    return p_count;


}

int main(int argc, char **argv)
{
    int ar[] = { 10, 20, 20, 10, 10, 30, 50, 10, 20 };
    printf("sockMerchant = %d\n", sockMerchant(9, 9, ar));

}

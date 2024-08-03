#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
} Queue;

void CreateQueue(Queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

Node *CreateNode(int init)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = init;
    node->next = NULL;
    return node;
}

int isEmptyQueue(Queue *q)
{
    return q->head == NULL;
}

void Enqueue(Queue *q, Node *node)
{
    if (isEmptyQueue(q))
    {
        q->head = node;
        q->tail = node;
    }
    else
    {
        q->tail->next = node;
        q->tail = node;
    }
}

int Dequeue(Queue *q)
{
    if (isEmptyQueue(q))
        return -1;
    Node *node = q->head;
    int data = node->data;
    q->head = node->next;
    free(node);
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    return data;
}

void PrintQueue(Queue *q)
{
    Node *node = q->head;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    CreateQueue(&queue);

    for (int i = 0; i < 5; i++) {
        Node *node = CreateNode(i + 1);
        Enqueue(&queue, node);
    }

    PrintQueue(&queue); // 1 2 3 4 5

    Dequeue(&queue);
    PrintQueue(&queue); // 2 3 4 5

    return 0;
}

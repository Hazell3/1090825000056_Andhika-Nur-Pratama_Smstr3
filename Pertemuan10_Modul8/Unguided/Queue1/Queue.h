#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#define MAXQ 5

typedef int infotype;

struct Queue {
    infotype info[MAXQ];   // indeks array dimulai dari 0
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
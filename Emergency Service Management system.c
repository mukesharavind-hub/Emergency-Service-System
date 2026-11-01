#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Call
typedef struct Call {
    int id;
    char priority[10];
    struct Call* next;
} Call;

// Structure for a Dispatch Record (Stack Node)
typedef struct Dispatch {
    char vehicle_id[10];
    Call* call;
    struct Dispatch* next;
} Dispatch;

// Queue structure
typedef struct {
    Call* front;
    Call* rear;
} CallQueue;

// Stack structure
typedef struct {
    Dispatch* top;
} DispatchStack;

// Initialize Queue
void initQueue(CallQueue* q) {
    q->front = q->rear = NULL;
}

// Initialize Stack
void initStack(DispatchStack* s) {
    s->top = NULL;
}

// Add a call to the queue
void receiveCall(CallQueue* q, int id, const char* priority) {
    Call* newCall = (Call*)malloc(sizeof(Call));
    newCall->id = id;
    strcpy(newCall->priority, priority);
    newCall->next = NULL;

    // Priority handling: High priority goes to the front
    if (strcmp(priority, "High") == 0 && q->front != NULL) {
        newCall->next = q->front;
        q->front = newCall;
    } else {
        if (q->rear == NULL) {
            q->front = q->rear = newCall;
        } else {
            q->rear->next = newCall;
            q->rear = newCall;
        }
    }
    printf("Call %d (%s) received.\n", id, priority);
}

// Dispatch a vehicle
void dispatchVehicle(CallQueue* q, DispatchStack* s, const char* vehicle_id) {
    if (q->front == NULL) {
        printf("No pending calls.\n");
        return;
    }

    // Dequeue the call
    Call* call = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    // Push to dispatch stack
    Dispatch* newDispatch = (Dispatch*)malloc(sizeof(Dispatch));
    strcpy(newDispatch->vehicle_id, vehicle_id);
    newDispatch->call = call;
    newDispatch->next = s->top;
    s->top = newDispatch;

    printf("Vehicle %s dispatched to Call %d.\n", vehicle_id, call->id);
}

// Undo the last dispatch
void undoLastDispatch(CallQueue* q, DispatchStack* s) {
    if (s->top == NULL) {
        printf("No dispatches to undo.\n");
        return;
    }

    // Pop from stack
    Dispatch* lastDispatch = s->top;
    s->top = s->top->next;

    Call* call = lastDispatch->call;

    // Return call to the front of the queue
    call->next = q->front;
    q->front = call;
    if (q->rear == NULL) q->rear = call;

    printf("Dispatch of Vehicle %s undone. Call %d returned to queue.\n", lastDispatch->vehicle_id, call->id);
    free(lastDispatch);
}

int main() {
    CallQueue q;
    DispatchStack s;

    initQueue(&q);
    initStack(&s);

    receiveCall(&q, 101, "Low");
    receiveCall(&q, 102, "High");

    dispatchVehicle(&q, &s, "A");
    dispatchVehicle(&q, &s, "B");

    undoLastDispatch(&q, &s);

    return 0;
}

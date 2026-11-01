# Emergency-Service-System

About the project:

Here is a C program implementation for the Emergency Service Management System. It uses a linked list-based queue to handle incoming emergency calls and a linked list-based stack to manage dispatched vehicles.

Objective:

The primary objective of this project is to design and implement an efficient Emergency Service Management System using fundamental data structures. By utilizing a priority queue for incoming emergency calls and a stack for tracking dispatched vehicles, the system aims to optimize response times and resource allocation. This ensures that high-priority incidents are addressed immediately while maintaining a reliable mechanism to manage and recall dispatch operations.

Data structure :

This project utilizes two primary data structures to manage operations efficiently:

1. Priority Queue (Linked List Implementation): Used to manage incoming emergency calls. It ensures that high-priority emergencies are serviced first, while standard calls are processed in a First-In, First-Out (FIFO) order.
2. Stack (Linked List Implementation): Used to track dispatched vehicles. This Last-In, First-Out (LIFO) structure allows the system to easily undo the most recent dispatch operation if a vehicle needs to be recalled or reassigned.

Features:

- Dynamic Call Handling: Automatically prioritizes high-severity emergencies over standard calls.
- Real-Time Dispatching: Assigns available vehicles to the most urgent calls in the queue.
- Undo Functionality: Allows administrators to instantly recall the last dispatched vehicle and return the call to the queue.
- Memory Efficient: Utilizes linked lists to dynamically allocate memory as calls and dispatches fluctuate.

Programming language:
-> C Programming Language

How it works:

1. Call Reception: When a new emergency call is received, it is evaluated for priority. High-priority calls are inserted at the front of the queue, while standard calls are added to the rear.
2. Vehicle Dispatch: The system processes calls from the front of the queue. When a vehicle is dispatched, the call is removed from the queue, and a record of the dispatch is pushed onto the stack.
3. Undo Operation: If a dispatch needs to be cancelled, the system pops the most recent record from the stack and returns the associated call back to the front of the queue for immediate reassignment.

Conclusion:

The Emergency Service Management System successfully demonstrates the practical application of stacks and queues in solving real-world resource allocation problems. By combining the FIFO nature of queues for fair processing with the LIFO nature of stacks for error correction, the system provides a robust framework for handling critical, time-sensitive operations.

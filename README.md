# Smart Hostel Room Allocation System

This project implements a hostel room allocation system in C using core data structures and algorithms. It demonstrates how different algorithmic approaches can be applied to solve a practical resource allocation problem.

The system uses a greedy strategy for fast assignment of students to rooms and includes additional features such as priority handling, search functionality, file storage, and basic analytics.

---

## Problem Overview

In a hostel, each room has a fixed capacity. Given a set of students, the goal is to allocate them to rooms such that:

* Room capacity constraints are not exceeded
* Allocation is efficient and practical
* Higher priority students are accommodated first

---

## Features

* Add and remove students
* Assign priority to students
* Add rooms with different capacities
* Allocate rooms using a greedy approach
* Search for a student’s room
* Display all room allocations
* Show usage analytics (efficiency, occupancy)
* Save and load data using file handling
* Menu-driven interface for easy interaction

---

## Approach

### Greedy Allocation

Students are sorted based on priority and assigned to the first available room with remaining capacity. This approach is fast and suitable for real-time allocation.

### Data Structures Used

* Arrays for storing students and rooms
* Structures for organizing data
* Basic searching and sorting techniques

---

## How to Run

### Compile

```bash
gcc main.c -o hostel
```

### Execute

```bash
./hostel
```

---

## Sample Workflow

1. Add students with their IDs and priorities
2. Add rooms with capacities
3. Allocate rooms
4. View room assignments
5. Search for a specific student
6. View analytics or save data

---

## Project Structure

```
Hostel-Room-Allocation/
│
├── main.c        # Main source code
├── data.txt      # Stored data file (generated at runtime)
├── README.md     # Documentation
```

---

## Learning Outcomes

* Understanding of greedy algorithms in real-world scenarios
* Practical use of structures and arrays in C
* Implementation of basic file handling
* Designing a menu-driven application
* Trade-offs between speed and optimality

---

## Limitations

* Uses a greedy approach, which may not always give optimal room usage
* Designed for moderate input sizes
* No graphical interface

---

## Future Improvements

* Add dynamic programming for optimal allocation
* Introduce roommate preference matching
* Improve search using hashing
* Add graphical or web-based interface
* Extend to a full hostel management system

---


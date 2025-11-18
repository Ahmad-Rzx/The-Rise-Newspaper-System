# Newspaper Delivery Management System

A C++ console-based management system for newspaper delivery services. Manage city locations, clients, delivery personnel, and assignments efficiently. The system leverages Dijkstra’s algorithm to calculate the shortest routes for deliveries.

---

## Features

- **City Graph Management:**  
  Add locations in a city with automatic computation of distances between all locations.

- **Client Management:**  
  Register clients with unique IDs, names, and associated city locations.

- **Delivery Personnel Management:**  
  Add delivery personnel with unique IDs, names, and track their current locations.

- **Delivery Assignments:**  
  Assign deliveries to clients and personnel. Automatically computes the shortest delivery route and distance.

- **Data Persistence:**  
  Save and load the complete state (graph, clients, personnel, and deliveries) to and from binary files.

---

## Project Structure

- `MainDriver.cpp` &mdash; Main entry point with menu-driven interface.
- `Graph.h/cpp` &mdash; City graph, distance management, save/load routines.
- `Client.h/cpp` &mdash; Client structure and client-related functions.
- `DeliveryPerson.h/cpp` &mdash; Delivery personnel structure and management.
- `Delivery.h/cpp` &mdash; Delivery assignments and Dijkstra shortest path implementation.
- `ManagementMenu.h/cpp` &mdash; Central menu and linking logic for all modules.

---

## How to Compile

**Requirement:** g++ (with C++11 support or later)

```sh
g++ -o NewspaperSystem MainDriver.cpp Graph.cpp Client.cpp DeliveryPerson.cpp Delivery.cpp ManagementMenu.cpp -std=c++11
```

---

## How to Run

- On **Windows PowerShell**:
  ```
  ./NewspaperSystem
  ```

- On **Command Prompt**:
  ```
  NewspaperSystem.exe
  ```

---

## Usage Guide

1. **Initialize City Graph**
   - Enter the number of locations in your city.
   - Enter the names for each location. Distances are calculated automatically.

2. **Menu Options**
   - Add clients
   - Add delivery personnel
   - Create delivery assignments (with automatic shortest path calculation)
   - View client, personnel, or delivery details
   - Save or load the system's entire state
   - Exit the program

---

## Notes

- Ensure all `.cpp` and `.h` files are in the same directory for compilation.
- The system state is preserved between runs if you use the save/load functionality.
- The shortest path computations for deliveries are fully automatic.

---

*Developed as a C++ console project for efficient and optimized management of newspaper deliveries across a city.*

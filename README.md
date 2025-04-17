# Euler-Graph-Algorithm
# ♾️ Eulerian Path and Circuit Detection in Undirected Graph

This repository provides a C++ implementation to detect **Eulerian Path** and **Eulerian Circuit** in an undirected graph using **DFS** and **degree parity** checks.

---

## 🧠 Concepts Used

- **Eulerian Circuit**: Exists if all vertices have even degree and the graph is connected.
- **Eulerian Path (but not circuit)**: Exists if exactly two vertices have an odd degree and the graph is connected.
- **No Euler Path or Circuit**: If more than two vertices have an odd degree or the graph is disconnected.

---

## 📌 Functions

### `int isEulerCircuit(int V, vector<int> adj[])`

Returns:
- `0` → No Euler Path or Circuit
- `1` → Euler Path but not Circuit
- `2` → Euler Circuit

---

## ⚙️ How It Works

1. **Connectivity Check**:
   - Uses DFS to ensure all non-zero degree vertices are in the same connected component.

2. **Degree Check**:
   - Counts the number of vertices with odd degree.
   - Applies Euler's Theorem rules.

---

⏱️ Time Complexity
DFS: O(V + E)

Degree check: O(V)

---

## 🧪 Example

```cpp
vector<int> adj[5];
adj[0] = {1, 2};
adj[1] = {0, 2};
adj[2] = {0, 1, 3, 4};
adj[3] = {2, 4};
adj[4] = {2, 3};

Solution sol;
int result = sol.isEulerCircuit(5, adj); // Output: 2 (Eulerian Circuit)


🧑‍💻 Author
Your Name – @Irythmgarg [Ridham Garg]


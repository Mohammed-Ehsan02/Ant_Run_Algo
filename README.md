# 🐜 ANT_RUN_ALGO Project

## 🚀 Overview
**ANT_RUN_ALGO** is a pathfinding and simulation algorithm project designed to move ants from a `start` room to an `end` room through a complex network of interconnected rooms (an ant farm).

The objective is to complete this task in the **minimum number of turns**, respecting strict movement rules and optimizing path usage.

---

## 🎯 Goal
- Parse a map containing ants, rooms, and tunnels (links)
- Build a graph representing the ant farm
- Use **Breadth-First Search (BFS)** to find the shortest path
- Simulate the ants’ movement through the path
- Output each ant move in the proper format

---

## 📥 Input Format
```
<number_of_ants>
##start
start_room x y
room1 x y
...
##end
end_room x y
...
roomA-roomB
roomB-roomC
...
```

- Rooms are defined by: `name x y`
- Links (tunnels) are defined as: `room1-room2`
- The `##start` and `##end` lines define the entry and exit points
- Lines starting with `#` are comments

---

## 📤 Output Format
1. Echo the input map (optional in bonus)
2. Show turn-by-turn ant movements:
```
L1-room2 L2-room3
L1-room3 L2-room4 L3-room2
...
```

Each `L<ant_id>-<room_name>` indicates a move by one ant in one turn.

---

## 📁 Directory Structure
```
lem-in/
├── Makefile
├── includes/
│   └── lem_in.h
├── src/
│   └── main.c
├── parsing/
│   ├── input.c
│   ├── room_input.c
│   ├── links_input.c
├── execution/
│   ├── bfs.c
│   ├── path.c
│   ├── simulate.c
├── utils/
│   ├── utils.c
│   ├── debug.c
├── libft/
├── maps/
│   ├── small_map.txt
│   ├── medium_map.txt
│   ├── large_map.txt
│   ├── big_map.txt
│   ├── biggest_map.txt
│   ├── mm.txt
│   ├── generator
│   └── generator_osx
```

---

## ⚙️ Compilation
```bash
make
```
This produces an executable binary named `lem-in`.

---

## 🧪 Run the Program
To run with a map:
```bash
./lem-in < maps/small_map.txt
```

---

## ✅ Allowed Functions (Mandatory)
Only the following system calls are allowed:
- `malloc`, `free`
- `read`, `write`
- `exit`, `strerror`, `perror`

---

## 🗺 Map Folder Contents

| File Name           | Description                    |
|---------------------|--------------------------------|
| `small_map.txt`     | Simple graph for debugging     |
| `medium_map.txt`    | Moderate graph for testing     |
| `large_map.txt`     | Challenging path test          |
| `big_map.txt`       | Large-scale simulation map     |
| `biggest_map.txt`   | Stress-test level map          |
| `mm.txt`            | Minimal test case              |
| `generator`         | Linux map generator binary     |
| `generator_osx`     | OSX map generator binary       |

---

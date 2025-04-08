# ANT_RUN_ALGO Project

## 🐜 Overview
ANT_RUN_ALGO is an algorithmic project where the goal is to move ants through a network of rooms (an ant farm) from a **start** room to an **end** room in the shortest number of moves. You must respect strict movement rules and optimize the solution to minimize the number of turns.

---

## 🧠 Goal
- Parse the input (ants, rooms, links)
- Build an in-memory graph of the ant farm
- Find optimal path(s) using **BFS**
- Simulate ant movement across paths
- Output each move in the correct format

---

## 📥 Input Format
```
<number_of_ants>
##start
start_room x y
room2 x y
...
##end
end_room x y
...
roomA-roomB
roomB-roomC
...
```

- `##start` and `##end` mark the start and end rooms
- Comments start with `#`
- Rooms are defined as `name x y`
- Links are defined as `room1-room2`

---

## 📤 Output Format
1. Print the input map
2. Print the ant movements, turn by turn:
```
L1-room2 L2-room3
L1-room3 L2-room4 L3-room2
...
```

---

## 🗂 Project Structure
```
lem-in/
├── Makefile
├── includes/
│   └── lem_in.h
├── src/
│   └── main.c
├── parsing/
│   ├── input.c
├── execution/
│   ├── simulate.c
├── utils/
│   ├── error.c
└── libft/
```

---

## ⚙️ Compilation
```bash
make
```
The compiled binary is named `lem-in`.

---

## 🚀 Run the Program
```bash
./lem-in < map.txt
```

---

## ✅ Allowed Functions (Mandatory Part)
- `malloc`, `free`
- `read`, `write`
- `exit`, `strerror`, `perror`

---

## 📚 Bonus (Optional)
- Visualizer (2D or 3D)
- Path display
- Advanced path optimization strategies

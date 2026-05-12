# ⊞ Tic Tac Toe — Console Game in C++

A two-player console-based Tic Tac Toe game built entirely in C++, featuring colourful ANSI output, persistent score tracking, and replay functionality.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [How to Compile](#how-to-compile)
- [How to Run](#how-to-run)
- [How to Play](#how-to-play)
- [Game Rules](#game-rules)
- [Win Conditions](#win-conditions)
- [Project Structure](#project-structure)
- [Core Concepts Used](#core-concepts-used)
- [Sample Output](#sample-output)

---

## Overview

This is a fully interactive, terminal-based Tic Tac Toe game for two players. The board updates dynamically after every move, invalid inputs are caught and handled gracefully, and the scoreboard persists across multiple rounds — all rendered with vibrant ANSI colours directly in the console.

---

## ✨ Features

| Feature | Details |
|---|---|
| 🎨 Colourful UI | ANSI colour codes for board, players, and messages |
| ✕ / ○ Markers | Player 1 in **Red**, Player 2 in **Cyan** |
| 📊 Scoreboard | Tracks wins for both players and draws across rounds |
| 🏆 Win Detection | Checks all 8 winning combinations after every move |
| 🤝 Draw Detection | Detects a full board with no winner |
| 🔄 Replay Option | Prompts to play again with validated `y/n` input |
| 🛡️ Input Validation | Rejects non-numeric, out-of-range, and occupied cells |
| 🖥️ Cross-Platform | Works on Linux, macOS, and Windows |

---

## Prerequisites

- A C++ compiler supporting **C++17** or later
  - Linux / macOS: `g++` (GCC) or `clang++`
  - Windows: `g++` via MinGW, or MSVC
- A terminal that supports **ANSI escape codes**
  - Linux / macOS: all standard terminals
  - Windows: Windows Terminal or enable Virtual Terminal in cmd

---

## 🔧 How to Compile

### Linux / macOS
```bash
g++ -std=c++17 -o tictactoe tictactoe.cpp
```

### Windows (MinGW)
```bash
g++ -std=c++17 -o tictactoe.exe tictactoe.cpp
```

### Using Clang
```bash
clang++ -std=c++17 -o tictactoe tictactoe.cpp
```

### Online Compiler (OnlineGDB)
1. Go to [https://www.onlinegdb.com](https://www.onlinegdb.com)
2. Select **C++** as the language
3. Paste the contents of `tictactoe.cpp`
4. Click **Run**

---

## ▶️ How to Run

```bash
./tictactoe        # Linux / macOS
tictactoe.exe      # Windows
```

---

## 🕹️ How to Play

1. The game starts with **Player 1 (✕)**.
2. The board cells are numbered **1 through 9**, laid out as:

```
 1 │ 2 │ 3
───┼───┼───
 4 │ 5 │ 6
───┼───┼───
 7 │ 8 │ 9
```

3. On your turn, type the **cell number** (1–9) and press `Enter`.
4. The board re-renders after every move showing the updated state.
5. The game announces a **winner** or a **draw** at the end of each round.
6. The **scoreboard** updates and you are asked to play again.

---

## 📖 Game Rules

- Players alternate turns — Player 1 always goes first in a new round.
- A cell already occupied **cannot** be chosen again.
- The first player to place **three marks in a line** wins.
- If all 9 cells are filled with no winner, the round is a **Draw**.
- Scores accumulate across rounds until you choose to quit.

---

## 🏆 Win Conditions

A player wins by completing any of the **8 possible lines**:

```
Rows:        Columns:     Diagonals:
X │ X │ X   X │   │     X │   │  
  │   │     X │   │       │ X │  
  │   │     X │   │       │   │ X

                          ← or →
```

The code checks all 8 combinations using a loop over rows and columns plus two explicit diagonal checks.

---

## 🗂️ Project Structure

```
tictactoe.cpp
│
├── ANSI colour macros       — defines RED, CYAN, YELLOW, etc.
├── Game state variables     — board[3][3], scoreX, scoreO, draws
│
├── clearScreen()            — cross-platform screen clear
├── printBanner()            — draws the title box
├── printScoreboard()        — shows current scores
├── initBoard()              — fills board with cell numbers 1–9
├── cellStr()                — returns colour-coded cell string
├── printBoard()             — renders the 3×3 grid with colours
│
├── checkWinner(char p)      — returns true if player p has won
├── isBoardFull()            — returns true if no empty cells remain
├── getMove(char player)     — validated input: accepts only 1–9, free cells
│
├── playTicTacToe()          — main round loop (move → check → switch)
└── main()                   — replay loop with y/n input validation
```

---

## 💡 Core Concepts Used

| Concept | Where Applied |
|---|---|
| **2D Arrays** | `board[3][3]` stores the game state |
| **Loops** | `for` loops scan rows, columns, and the board |
| **Conditional Logic** | `if/else` for win, draw, turn switching, input checks |
| **Functions** | Modular design — each responsibility in its own function |
| **String Manipulation** | ANSI escape codes assembled into coloured strings |
| **Input Validation** | `while` loop with `cin` error handling and range checks |
| **Cross-platform Macros** | `#ifdef _WIN32` for screen clear command |

---

## 🖥️ Sample Output

```
  ╔════════════════════════════╗
  ║  T I C  T A C  T O E       ║
  ╚════════════════════════════╝

  ┌───────────────────────────────────────────┐
  │  ✕ Player 1: 1   ○ Player 2: 0   Draws: 0 │
  └───────────────────────────────────────────┘

   X │ X │ X        ← WIN!
  ───┼───┼───
   O │ O │ 6
  ───┼───┼───
   7 │ 8 │ 9

  ╔══════════════════════════════╗
  ║  🏆  Player 1 (✕) WINS!     ║
  ╚══════════════════════════════╝

  Play again? (y/n):
```

---

## 📝 Notes

- Colours require an ANSI-compatible terminal. On older Windows `cmd`, run `chcp 65001` first or use Windows Terminal.
- The board numbering resets to 1–9 at the start of each new round, but **scores persist** for the entire session.
- Entering anything other than `y` or `n` at the replay prompt will show an error and re-ask.

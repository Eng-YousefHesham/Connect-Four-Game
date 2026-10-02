# Connect Four (C++)

A simple console Connect Four game built in C++ using procedural programming concepts and custom data structures. It handles turn-based gameplay, board rendering with ANSI color codes, and complete win/draw condition checking.

## Features

- **ANSI Colored Console UI:** Styled grid rendering with color-coded player tokens (`X` in red, `O` in yellow).
- **Player vs Player Mode:** Interactive turn-based gameplay for two local players with custom name inputs.
- **Win & Draw Detection:** Detects horizontal, vertical, and diagonal (up-right & down-right) 4-in-a-row connections.
- **Board Column Drop Handling:** Automatically stacks coins from the bottom row up and alerts users when a column is full.

## Concepts Demonstrated

- Basic Data Structures — 2D arrays (`char board[6][7]`) and custom `struct` types (`Player`)
- Conditional logic & matrix traversal algorithms for multi-directional win condition checking
- Function decomposition and pass-by-value/reference handling
- String manipulation and ANSI escape code terminal formatting
- Standard input/output handling (`cin` / `cout`)

## Project Structure
Connect-Four-CPP/
├── main.cpp     # Entry point - game loop, board rendering & win detection logic
├── README.md    # Project documentation
└── .gitignore   # Git ignore rules for compiled binaries
## How to Run

1. Make sure you have a C++ compiler installed (`g++`, `clang++`, or MSVC).
2. Clone this repository:
   ```bash
   git clone [https://github.com/Eng-YousefHesham/Connect-Four-CPP.git](https://github.com/Eng-YousefHesham/Connect-Four-CPP.git)

>> Welcome to Connect Four!
Choose game mode ('p' for player vs player, 'a' for player vs AI):
p
Player vs Player mode selected.
Enter your name: Player1
Enter your name: Player2

   1    2    3    4    5    6    7
[   ][   ][   ][   ][   ][   ][   ]
[   ][   ][   ][   ][   ][   ][   ]
[   ][   ][   ][   ][   ][   ][   ]
[   ][   ][   ][   ][   ][   ][   ]
[   ][   ][   ][   ][   ][   ][   ]
[   ][   ][   ][   ][   ][   ][   ]

Player1's turn. Enter column (1-7) to drop your coin: 4

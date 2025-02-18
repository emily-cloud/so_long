# So Long - 42 Berlin

## Introduction

**So Long** is a graphical 2D game project from 42 Berlin that introduces students to **game development** using the **MiniLibX** library. The objective is to create a simple **top-down game** where a player navigates through a map to reach an exit while collecting items and avoiding enemies (if implemented as a bonus).

## Features

- **2D graphical rendering** using MiniLibX
- **Player movement** (up, down, left, right)
- **Collectibles** that the player must gather before exiting
- **A valid map format** that follows specific constraints
- **Basic enemy AI** (Bonus)
- **Animations** for player and enemies (Bonus)

## Installation

```bash
git clone https://github.com/emily-cloud/so_long.git
cd so_long
make
```

## Usage

```bash
./so_long maps/map1.ber
```

## Map Format

The game map is defined in a `.ber` file and must contain:
- **Walls (`1`)** enclosing the map
- **Empty spaces (`0`)** for movement
- **A player (`P`)**
- **An exit (`E`)**
- **Collectibles (`C`)**
- *(Bonus: Enemies (`X`))*

Example:
```
111111
1P0C01
1000E1
111111
```

## Controls

- **W** / **Arrow Up** → Move up
- **S** / **Arrow Down** → Move down
- **A** / **Arrow Left** → Move left
- **D** / **Arrow Right** → Move right
- **ESC** → Quit game

## Dependencies

- **MiniLibX** (included in the repository)
- **GNU Make & GCC**
- **macOS or Linux (for X11 graphics)**

## Resources

- `man 3 mlx`
- `man 3 open`
- `man 3 read`
- `man 3 close`

## Authors

- Developed as part of the 42 Berlin curriculum by Huayun Ai.

## License

This project follows the academic rules of 42 and is intended for educational purposes.


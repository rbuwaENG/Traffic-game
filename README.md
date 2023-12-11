# Traffic Game
This is a command-line traffic game implemented in C. The game allows the player to navigate a car through a map filled with traffic paths, with the goal of reaching the destination.


## Features
- Interactive gameplay where the player can control the car using the keys 'w', 'a', 's', and 'd'.
- Undo feature that allows the player to revert their moves.
- File I/O functionality to read the map information from a text file.
- Proper error handling for invalid command-line arguments and missing files.

## Getting Started
To get started with the traffic game, follow these steps:
- Clone the repository: git clone https://github.com/your-username/traffic-game.git
- Navigate to the project directory: cd traffic-game
- Compile the source code: make
- Run the game: ./traffic <map_file_name>

## Usage
The game starts by displaying the initial map on the terminal. The player can control the car using the following keys:

- 'w': Move the car forward
- 'a': Rotate the car counterclockwise
- 's': Rotate the car clockwise
- 'd': Move the car backward
- 'u': Undo the previous move
- After each move, the map will be updated and displayed again. The goal of the game is to reach the destination ('G') by navigating through the traffic paths ('.').

## File I/O
The game reads the map information from a text file. The file should have the following format:
Each integer in the file represents a cell in the map, where:

- 0 represents an empty space (' ')
- 1 represents a traffic path ('.')
- 2 represents the car position and traffic path simultaneously ('>')
- 3 represents the player ('P')
- 4 represents the goal ('G')
Make sure to provide a valid map file as a command-line argument when running the game.

## Undo Feature
The game implements an undo feature that allows the player to revert their moves. Pressing the 'u' key will move the player and the car back to their previous positions. The undo feature can be used at any point during the game, except when the game is in its initial state.
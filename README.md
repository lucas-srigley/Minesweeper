# Minesweeper

A console-based implementation of the classic Minesweeper game written in C, featuring a 10x10 grid with randomly placed mines and recursive cell-filling algorithm.

## Overview

This Minesweeper clone provides the traditional gameplay experience where players must uncover all non-mine cells while avoiding hidden mines. The game features automatic cell expansion for empty areas and a flagging system to mark suspected mines.

## Game Features

- **10x10 Grid**: Standard game board with 10 randomly placed mines
- **Cell Checking**: Reveal cells and display adjacent mine counts
- **Flag System**: Mark suspected mine locations with flags
- **Recursive Fill**: Automatically uncover adjacent empty cells
- **Win/Loss Detection**: Game ends when all safe cells are revealed or a mine is hit

## Gameplay

Players interact through console commands:
- `c <row> <col>`: Check/reveal a cell at specified coordinates
- `f <row> <col>`: Flag a cell as containing a mine
- Numbers displayed show count of adjacent mines
- Game ends with victory (all safe cells revealed) or defeat (mine triggered)

## Technical Implementation

- **Grid Management**: Two 2D arrays for mine data and player visibility
- **Mine Generation**: Random placement using seeded random number generator
- **Adjacent Mine Counting**: Comprehensive boundary checking for all 8 directions
- **Recursive Algorithm**: Flood-fill style expansion for empty cell areas

## Tech Stack

- **Language**: C
- **Architecture**: Procedural programming with recursive functions
- **Input/Output**: Console-based user interface with scanf/printf

# Fishpedia 

Fishpedia is a simple console-based C project for storing and managing fish data.  
This project is the first step of my learning journey in C programming and game development fundamentals.

The long-term idea is to build a fish encyclopedia system that can later become part of a cozy simulation game inspired.

## Features

Current features:

- Add fish data
- Show all fish data
- Search fish by name
- Delete fish data
- Save fish data to a `.txt` file
- Load fish data when the program starts

## Fish Data

Each fish contains:

- Name
- Habitat
- Rarity
- Active time
- Record size
- Price
- Dish name
- Special note

Example:

```text
Gurame|River|Common|Night|8.00 kg|5000|Gurame bakar|Popular Indonesian freshwater fish
```

## How to compile
`gcc main.c fishList.c -o fishpedia`

## How to run
`./fishpedia`

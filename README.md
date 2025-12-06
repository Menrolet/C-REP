# Task Collection

This repo contains small C/C++ exercises, each in its own folder. See `README.ru.md` for the Russian version.

- **Metro stations** (`metro_stations/metro_stations.c`): defines a metro network graph, provides `set_station_links` and BFS-based `find_path` to build the shortest route from one station to another.  
  Build example: `gcc metro_stations/metro_stations.c -std=c11 -Wall -Wextra -o metro && ./metro`

- **URL stack** (`url_stack/url_stack.c`): singly linked stack of page visits with `push`/`pop`; `main` pushes the given URLs and frees the stack (no output).

- **Singleton pattern** (`singleton_pattern/main.cpp`): simple lazy singleton demo that returns the same instance pointer twice and prints confirmation.

- **Singly linked list** (`singly_linked_list/main.cpp`): smart-pointer based singly linked list with `push_back`, `pop_front`, and `show`; `main` appends 1..4 and prints them.

- **Mines placement** (`mines_placement/main.c`): places 12 mines (`*`) on a 10x10 grid so no mines touch orthogonally or diagonally; empty cells stay zeroed. No output.

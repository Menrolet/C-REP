#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

static int can_place_mine(char pg[SIZE][SIZE], int x, int y)
{
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                if (pg[nx][ny] == '*') {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(void)
{
    char pg[SIZE][SIZE] = {0};
    srand((unsigned)time(NULL));

    int mines_placed = 0;
    while (mines_placed < 12) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (pg[x][y] == 0 && can_place_mine(pg, x, y)) {
            pg[x][y] = '*';
            ++mines_placed;
        }
    }

    return 0;
}

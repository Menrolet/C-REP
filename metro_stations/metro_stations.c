#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

enum {name_length=50, total_links=50, max_path_station=100};

typedef struct tag_station {
    char name[name_length];                 // название станции метро
    struct tag_station* links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;

void set_station_links(STATION* st, int count_links, ...)
{
    va_list ap;
    va_start(ap, count_links);
    for(int i=0; i<count_links; i++)
    {
        st->links[i] = va_arg(ap, STATION*);
    }
    st->count_links = count_links;
    va_end(ap);
}

static int index_of(STATION* arr[], int count, STATION* v)
{
    for (int i = 0; i < count; ++i) {
        if (arr[i] == v) return i;
    }
    return -1;
}

void find_path(STATION* from, STATION* to, STATION* path[], int* count_st)
{
    STATION* queue[max_path_station];
    int head = 0, tail = 0;

    STATION* seen[max_path_station];
    STATION* parent[max_path_station];
    int seen_count = 0;

    *count_st = 0;

    // start BFS from source
    queue[tail++] = from;
    seen[seen_count] = from;
    parent[seen_count] = NULL;
    from->fl_reserved = 1;
    ++seen_count;

    int found = 0;
    while (head < tail && !found) {
        STATION* cur = queue[head++];
        for (int i = 0; i < cur->count_links; ++i) {
            STATION* nb = cur->links[i];
            if (!nb->fl_reserved) {
                queue[tail++] = nb;
                seen[seen_count] = nb;
                parent[seen_count] = cur;
                nb->fl_reserved = 1;
                ++seen_count;
                if (nb == to) {
                    found = 1;
                    break;
                }
            }
        }
    }

    if (found) {
        STATION* rev[max_path_station];
        int rev_count = 0;

        STATION* v = to;
        while (v != NULL) {
            rev[rev_count++] = v;
            int idx = index_of(seen, seen_count, v);
            v = (idx >= 0) ? parent[idx] : NULL;
        }

        for (int i = rev_count - 1; i >= 0; --i) {
            path[*count_st] = rev[i];
            ++(*count_st);
        }
    }

    // clear visited flags
    for (int i = 0; i < seen_count; ++i) {
        seen[i]->fl_reserved = 0;
    }
}

int main(void)
{
    STATION st[10] = {
        {"St #1", .count_links=0, .fl_reserved=0},
        {"St #2", .count_links=0, .fl_reserved=0},
        {"St #3", .count_links=0, .fl_reserved=0},
        {"St #4", .count_links=0, .fl_reserved=0},
        {"St #5", .count_links=0, .fl_reserved=0},
        {"St #6", .count_links=0, .fl_reserved=0},
        {"St #7", .count_links=0, .fl_reserved=0},
        {"St #8", .count_links=0, .fl_reserved=0},
        {"St #9", .count_links=0, .fl_reserved=0},
        {"St #10", .count_links=0, .fl_reserved=0},
    };
    set_station_links(&st[0], 2, &st[1], &st[2]);                 // 1: 2,3
    set_station_links(&st[1], 3, &st[0], &st[3], &st[4]);         // 2: 1,4,5
    set_station_links(&st[2], 2, &st[0], &st[5]);                 // 3: 1,6
    set_station_links(&st[3], 2, &st[1], &st[5]);                 // 4: 2,6
    set_station_links(&st[4], 2, &st[1], &st[7]);                 // 5: 2,8
    set_station_links(&st[5], 4, &st[2], &st[3], &st[6], &st[8]); // 6: 3,4,7,9
    set_station_links(&st[6], 2, &st[5], &st[8]);                 // 7: 6,9
    set_station_links(&st[7], 2, &st[4], &st[8]);                 // 8: 5,9
    set_station_links(&st[8], 4, &st[5], &st[6], &st[7], &st[9]); // 9: 6,7,8,10
    set_station_links(&st[9], 1, &st[8]);                         // 10: 9

    return 0;
}

// здесь подключение заголовочных файлов, директивы, функции
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {max_len = 1024};

typedef struct tag_obj {
    struct tag_obj* next;
    char url[max_len];
} OBJ, StekOBJ;

OBJ* push(OBJ* top, const char* url)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    if (!ptr) {
        return top;
    }
    strncpy(ptr->url, url, sizeof(ptr->url) - 1);
    ptr->url[sizeof(ptr->url) - 1] = '\0';
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if (top == NULL)
        return NULL;
    OBJ *new_ptr = top->next;
    free(top);
    return new_ptr;
}

int main(void)
{
    // здесь продолжайте функцию main
    OBJ *top = NULL;
    top = push(top, "https://proproprogs.ru/c_base/c_etapy-translyacii-programmy-v-mashinnyy-kod-standarty");
    top = push(top, "https://proproprogs.ru/c_base/c_struktura-i-ponimanie-raboty-programmy-hello-world");
    top = push(top, "https://proproprogs.ru/c_base/c_dvoichnaya-shestnadcaterichnaya-i-vosmerichnaya-sistemy-schisleniya");
    top = push(top, "https://proproprogs.ru/c_base/c_lokalnye-i-globalnye-peremennye");
    top = push(top, "https://proproprogs.ru/c_base/c_perechisleniya-enum-direktiva-typedef");


    // здесь освобождайте память, занимаемую стеком
    while (top) {
        top = pop(top);
    }

    return 0;
}

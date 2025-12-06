#include <iostream>
#include <memory>

using namespace std;

struct object {
    int data;
    std::shared_ptr<object> next;
};

using shared_obj_ptr = std::shared_ptr<object>;

void push_back(shared_obj_ptr& head, shared_obj_ptr& tail, int data)
{
    // добавление в конец нового объекта односвязного списка
    auto node = make_shared<object>();
    node->data = data;
    node->next = nullptr;
    if (!head) {
        head = node;
    } else {
        tail->next = node;
    }
    tail = node;
}

void pop_front(shared_obj_ptr& head, shared_obj_ptr& tail)
{
    // удаление первого объекта из односвязного списка
    if (!head) {
        tail = nullptr;
        return;
    }
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
}

void show(const shared_obj_ptr& head)
{
    auto cur = head;
    // отображение поля data объектов односвязного списка по порядку (от head до tail) в одну строчку через пробел
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main(void)
{
    // здесь продолжайте функцию main
    shared_obj_ptr head = nullptr;
    shared_obj_ptr tail = nullptr;
    for (int i = 1; i <= 4; i++) {
        push_back(head, tail, i);
    }
    show(head);

    return 0;
}

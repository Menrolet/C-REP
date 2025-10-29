#include <iostream>

class Singleton {
    private:
        int data {0};
        static Singleton* instance_ptr;
        Singleton() = default; 
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        static Singleton* getInstance() {
            if (instance_ptr == nullptr) {
                instance_ptr = new Singleton();
            }
            return instance_ptr;
        }
        void setData(int value) {
            data = value;
        }
        int getData() const {
            return data;
        }
    ~Singleton() = default;
};

Singleton* Singleton::instance_ptr = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2) {
        std::cout << "Both pointers point to the same instance." << std::endl;
    } else {
        std::cout << "Pointers point to different instances." << std::endl;
    }

    return 0;
}

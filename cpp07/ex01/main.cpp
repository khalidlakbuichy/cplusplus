#include "iter.hpp"

template <typename T>
void print(T const &i) {
    std::cout << i << std::endl;
}

int main (void) {
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, 5, print);

    float tab2[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
    ::iter(tab2, 5, print);

    std::string tab3[] = {"zero", "one", "two", "three", "four"};
    ::iter(tab3, 5, print);

    
    return 0;

}
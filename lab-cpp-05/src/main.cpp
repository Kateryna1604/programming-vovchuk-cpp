#include "list.hpp"

#include <iostream>
#include <string>

int main()
{
    List<int> numbers;

    numbers.add(10);
    numbers.add(3);
    numbers.add(7);
    numbers.add(1);

    std::cout << "INT LIST:" << std::endl;
    numbers.print();

    std::cout << "MIN = "
              << numbers.getMin()
              << std::endl;

    std::cout << "INDEX OF 7 = "
              << numbers.findIndex(7)
              << std::endl;

    numbers.sort();

    std::cout << "SORTED:" << std::endl;
    numbers.print();

    numbers.remove(1);

    std::cout << "AFTER REMOVE:" << std::endl;
    numbers.print();



    List<std::string> words;

    words.add("banana");
    words.add("apple");
    words.add("orange");

    std::cout << std::endl;

    std::cout << "STRING LIST:" << std::endl;
    words.print();

    std::cout << "MIN = "
              << words.getMin()
              << std::endl;

    words.sort();

    std::cout << "SORTED:" << std::endl;
    words.print();

    return 0;
}

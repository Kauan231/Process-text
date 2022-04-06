#include "includes/separate.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string enter_path;
    std::cout << "Enter path: ";
    std::cin >> enter_path;
    std::vector<std::string> words;
    words = separate(enter_path);
    show_repeat(get_keys(words), words);
}
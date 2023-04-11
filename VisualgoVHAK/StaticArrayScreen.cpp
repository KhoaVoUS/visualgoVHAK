#include "StaticArrayScreen.h"
#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "RenderStaticArray.h"

void InitArray(std::string str, doublyLinkedList& list)
{
    while (list.pHead != nullptr) list.deleteHead();
    // Create a stringstream object from the string
    std::stringstream ss(str);

    int value;
    // Iterate through each number in the stringstream
    while (ss >> value) {
        // Create a new node with the value
        Node* newNode = create(value);
        // Add the node to the linked list
        list.addTail(newNode);
    }
    list.loadList();
}
void StaticArrayScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& SA, sf::Color bg, bool& darkMode, int* a, int array_size, bool& fast)
{
    window.clear(bg);
    sf::Color ButtonBg;
    sf::Color darkBlue(0, 0, 128);
    sf::Color lightGreen(144, 238, 144);

    if (darkMode) ButtonBg = lightGreen;
    else ButtonBg = darkBlue;

    // Back button
    Button* BackButton = new Button(20, 20, 200, 50, font, "Back",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    BackButton->update(window);
    BackButton->render(window);
    if (BackButton->isClicked(window))
    {
        Menu = true;
        SA = false;
    }

    // Init button
    Button* InitButton = new Button(50, 100, 200, 50, font, "Init",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    InitButton->update(window);
    InitButton->render(window);

    //random
    std::srand(std::time(nullptr));
    Button* InitRandomButton = new Button(280, 100, 200, 50, font, "Init Randomly",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    InitRandomButton->update(window);
    InitRandomButton->render(window);
    if (InitRandomButton->isClicked(window))
    {
        for (int i = 0; i < array_size; i++)
        {
            int value = std::rand() % 10 + 1;
            a[i] = value;
        }
        
    }


    Button* Reset = new Button(50, 740, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        for (int i = 0; i < array_size; i++) a[i] = 0;
    }

    renderStaticArray(a, array_size, ButtonBg, font, window);
    window.display();

    delete BackButton, Reset;
}



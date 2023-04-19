#include "MenuScreen.h"
#include <iostream>
void MenuScreen(sf::RenderWindow& window, sf::Font& font, bool& Welcome, bool& Menu, sf::Color bg, bool& DLL, bool& SLL, bool& CLL, bool& SA, bool& DA, bool& S, bool& Q)
{
    window.clear(bg);
    sf::Color ButtonBg(173, 216, 230);

    Button* BackButton = new Button(50, 20, 200, 50, font, "Back",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    BackButton->update(window);
    
    if (BackButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 1;
    }

    BackButton->render(window);

    Button* DLLButton = new Button(100, 100, 300, 200, font, "Doubly Linked List",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* SLLButton = new Button(420, 100, 300, 200, font, "Singly Linked List",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* CLLButton = new Button(740, 100, 300, 200, font, "Circularly Linked List",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* StaticArrayButton = new Button(100, 350, 300, 200, font, "Static Array",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* DynamicArrayButton = new Button(420, 350, 300, 200, font, "Dynamic Array",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* StackButton = new Button(740, 350, 300, 200, font, "Stack",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* QueueButton = new Button(1060, 350, 300, 200, font, "Queue",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    DLLButton->update(window);
    DLLButton->render(window);

    SLLButton->update(window);
    SLLButton->render(window);

    CLLButton->update(window);
    CLLButton->render(window);

    StaticArrayButton->update(window);
    StaticArrayButton->render(window);

    DynamicArrayButton->update(window);
    DynamicArrayButton->render(window);

    StackButton->update(window);
    StackButton->render(window);

    QueueButton->update(window);
    QueueButton->render(window);

    if (DLLButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        DLL = 1;
    }

    if (SLLButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        SLL = 1;
    }

    if (CLLButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        CLL = 1;
    }

    if (StaticArrayButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        SA = 1;
    }

    if (DynamicArrayButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        DA = 1;
    }

    if (StackButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        S = 1;
    }

    if (QueueButton->isClicked(window))
    {
        Menu = 0;
        Welcome = 0;
        Q = 1;
    }
    window.display();

    delete DLLButton;
    delete SLLButton;
    delete CLLButton;
    delete StaticArrayButton;
    delete DynamicArrayButton;
    delete StackButton;
    delete QueueButton;
    delete BackButton;

}
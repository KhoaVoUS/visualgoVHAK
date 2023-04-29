#include  "SFML/Graphics.hpp"
#include "WelcomeScreen.h"
#include "MenuScreen.h"
#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"
#include "CircularlyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkedListScreen.h"
#include "SinglyLinkedListScreen.h"
#include "CircularlyLinkedListScreen.h"
#include "StackScreen.h"
#include "QueueScreen.h"
#include "StaticArrayScreen.h"
#include "DynamicArrayScreen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "VisualgoClone");

    sf::Event event;

    sf::Font font;

    sf::Color bg;
    sf::Color lightPink(255, 182, 193);
    sf::Color darkGray(64, 64, 64);

    font.loadFromFile("RobotoMono.ttf");
    bool Welcome = 1, Menu = 0, fast = 1, darkMode = 0;

    bool SLL = 0, DLL = 0, CLL = 0, SA = 0, DA = 0, S = 0, Q = 0;
    const int array_size = 8;
    float speed = 1.0;

    doublyLinkedList dLinkedList; dLinkedList.addTail(create(1)); dLinkedList.addTail(create(3)); dLinkedList.addTail(create(5));
    singlyLinkedList sLinkedList; sLinkedList.addTail(create(4)); sLinkedList.addTail(create(7)); sLinkedList.addTail(create(0));
    circularlyLinkedList cLinkedList; cLinkedList.addTail(create(5)); cLinkedList.addTail(create(2)); cLinkedList.addTail(create(2));
    Stack stack; stack.addHead(create(2)); stack.addHead(create(6));
    Queue queue; queue.addTail(create(2)); queue.addTail(create(21));

    int sArray[array_size] = { 0, 2, 6, 8 };
    std::vector<int> dArray;
    dArray.push_back(1);
    dArray.push_back(2);
    dArray.push_back(3);

    window.setFramerateLimit(30);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        if (darkMode)
            bg = darkGray; else bg = lightPink;


        if (Welcome) {
            WelcomeScreen(window, font, Welcome, Menu, fast, bg, darkMode, speed);
        }

        if (Menu) {
            MenuScreen(window, font, Welcome, Menu, bg, DLL, SLL, CLL, SA, DA, S, Q);
        }

        if (DLL)
        {
            DLLScreen(window, font, Menu, DLL, bg, darkMode, dLinkedList, fast, speed);
        }

        if (SLL)
        {
            SLLScreen(window, font, Menu, SLL, bg, darkMode, sLinkedList, fast, speed);
        }

        if (CLL)
        {
            CLLScreen(window, font, Menu, CLL, bg, darkMode, cLinkedList, fast, speed);
        }

        if (S)
        {
            StackScreen(window, font, Menu, S, bg, darkMode, stack, fast, speed);
        }

        if (Q)
        {
            QueueScreen(window, font, Menu, Q, bg, darkMode, queue, fast, speed);
        }
        
        if (SA)
        {
            StaticArrayScreen(window, font, Menu, SA, bg, darkMode, sArray, array_size, fast, speed);
        }

        if (DA)
        {
            DynamicArrayScreen(window, font, Menu, DA, bg, darkMode, dArray, fast, speed);
        }
    }

    return 0;
}
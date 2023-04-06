#include  "SFML/Graphics.hpp"
#include "WelcomeScreen.h"
#include "MenuScreen.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedListScreen.h"

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

    doublyLinkedList dLinkedList;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        if (darkMode)
            bg = darkGray; else bg = lightPink;


        if (Welcome) {
            WelcomeScreen(window, font, Welcome, Menu, fast, bg, darkMode);
        }

        if (Menu) {
            MenuScreen(window, font, Welcome, Menu, bg, DLL, SLL, CLL, SA, DA, S, Q);
        }

        if (DLL)
        {
            DLLScreen(window, font, Menu, DLL, bg, darkMode, dLinkedList, fast);
        }

    }

    return 0;
}
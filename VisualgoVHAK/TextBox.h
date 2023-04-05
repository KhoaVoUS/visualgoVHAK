#pragma once
#include <SFML/Graphics.hpp>

struct TextBox {
    sf::RectangleShape box;
    sf::Text text;
    bool isSelected;
    int cursorIndex;
    sf::RectangleShape cursor;

    TextBox(sf::Vector2f size, sf::Vector2f position, sf::Font& font);

    void draw(sf::RenderWindow& window);

    void handleEvent(sf::Event& event);
};



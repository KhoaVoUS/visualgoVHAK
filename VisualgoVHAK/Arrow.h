#pragma once
#include <SFML/Graphics.hpp>

struct Arrow {
    sf::RectangleShape body;
    sf::ConvexShape head1;
    sf::ConvexShape head2;
};

void drawArrowHorizontal(int x, int x1, int y1, sf::RenderWindow& window);

void drawArrowVertical(int x, int x1, int y, sf::RenderWindow& window);

void draw2headArrowHorizontal(int x, int x1, int y, sf::RenderWindow& window);

void draw2headArrowVertical(int x, int y, int y1, sf::RenderWindow& window);

void draw1headArrowHorizontal(int x, int x1, int y, sf::RenderWindow& window);

void draw1headArrowVertical(int x, int y, int y1, sf::RenderWindow& window);


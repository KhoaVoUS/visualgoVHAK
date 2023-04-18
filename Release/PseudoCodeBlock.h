#pragma once
#include <SFML/Graphics.hpp>

struct PseudoCodeBlock
{
    sf::RectangleShape background;
    std::vector<sf::Text> lines;
    std::vector<sf::Color> lineColors;

    // Constructor to initialize the background
    PseudoCodeBlock(sf::Font& font, float x, float y, float width, float height, sf::Color bgColor);

    void addLine(std::string text, sf::Font& font, int fontSize, sf::Color color);

    void draw(sf::RenderWindow& window);
    void changeLineColor(int lineNumber, sf::Color newColor);

};

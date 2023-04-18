#include "PseudoCodeBlock.h"

PseudoCodeBlock::PseudoCodeBlock(sf::Font& font, float x, float y, float width, float height, sf::Color bgColor)
{
    background.setPosition(x, y);
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(bgColor);
}

void PseudoCodeBlock::addLine(std::string text, sf::Font& font, int fontSize, sf::Color color)
{
    sf::Text line(text, font, fontSize);
    line.setFillColor(color);
    lines.push_back(line);
    lineColors.push_back(color);
}

void PseudoCodeBlock::draw(sf::RenderWindow& window)
{
    window.draw(background);
    float x = background.getPosition().x + 10.f; // Offset for left margin
    float y = background.getPosition().y + 10.f; // Offset for top margin
    for (int i = 0; i < lines.size(); i++)
    {
        lines[i].setPosition(x, y);
        lines[i].setFillColor(lineColors[i]);
        window.draw(lines[i]);
        y += lines[i].getGlobalBounds().height + 10.f; // Add spacing between lines
    }
}

void PseudoCodeBlock::changeLineColor(int lineNumber, sf::Color newColor)
{
    if (lineNumber < lines.size()) {
        lineColors[lineNumber] = newColor;
        lines[lineNumber].setFillColor(newColor);
    }
}

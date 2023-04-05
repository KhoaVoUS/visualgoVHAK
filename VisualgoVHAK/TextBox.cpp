#include "TextBox.h"
#include <SFML/Graphics.hpp>

TextBox::TextBox(sf::Vector2f size, sf::Vector2f position, sf::Font& font) {
    box.setSize(size);
    box.setPosition(position);
    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(2.f);
    box.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position + sf::Vector2f(10.f, 10.f));

    cursorIndex = text.getString().getSize();
    isSelected = false;

    cursor.setFillColor(sf::Color::Red);
    cursor.setSize(sf::Vector2f(2.f, text.getGlobalBounds().height));
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(text);

    if (isSelected) {
        cursor.setPosition(text.findCharacterPos(cursorIndex));
        window.draw(cursor);
    }
}


void TextBox::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        if (box.getGlobalBounds().contains(mousePos)) {
            isSelected = true;
        }
        else {
            isSelected = false;
        }
    }

    if (event.type == sf::Event::TextEntered && isSelected) {
        if (event.text.unicode == '\b') {
            if (!text.getString().isEmpty()) {
                text.setString(text.getString().substring(0, text.getString().getSize() - 1));
            }
        }
        else if (event.text.unicode < 128) {
            text.setString(text.getString() + static_cast<char>(event.text.unicode));
        }
    }

}

#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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
    // Update the text position based on its size and the box size
    sf::FloatRect textBounds = text.getGlobalBounds();
    sf::FloatRect boxBounds = box.getGlobalBounds();
    sf::Text TextDisplay = text;
    float textRight = textBounds.left + textBounds.width;
    if (textRight > boxBounds.left + boxBounds.width) {
        float delta = textRight - (boxBounds.left + boxBounds.width);
        text.move(-delta, 0);
        cursor.move(-delta, 0);
    }
    // Remove characters from the left as needed
    while (textBounds.width > boxBounds.width) {
        std::string textString = TextDisplay.getString();
        textString.erase(0, 1);
        TextDisplay.setString(textString);
        textBounds = TextDisplay.getGlobalBounds();
    }

    // Set text alignment to left
    TextDisplay.setOrigin(0, 0);
    TextDisplay.setPosition(box.getPosition().x + 5, box.getPosition().y + (box.getSize().y - TextDisplay.getGlobalBounds().height) / 2);

    // Draw box and modified text
    window.draw(box);
    window.draw(TextDisplay);

    // Draw cursor if textbox is selected
    if (isSelected) {
        cursor.setPosition(TextDisplay.findCharacterPos(cursorIndex));
        cursor.setSize(sf::Vector2f(2.f, TextDisplay.getGlobalBounds().height));
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
                cursorIndex = text.getString().getSize();
            }
        }
        else if (event.text.unicode < 128) {
            text.setString(text.getString() + static_cast<char>(event.text.unicode));
            cursorIndex = text.getString().getSize();
        }
    }
}


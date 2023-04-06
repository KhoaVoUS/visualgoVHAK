#pragma once
#include "DoublyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddTailDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddIndexDLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);


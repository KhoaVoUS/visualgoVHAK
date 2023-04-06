#pragma once
#include "DoublyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadDLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddTailDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddTailDLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexDLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexDLLStep(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeletePositionDLL(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderSearchDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);


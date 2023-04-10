#pragma once
#include "DoublyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderCLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadCLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddHeadCLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddTailCLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddTailCLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexCLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexCLLStep(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadCLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteHeadCLLStep(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailCLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailCLLStep(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeletePositionCLL(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeletePositionCLLStep(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderSearchCLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderSearchCLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);


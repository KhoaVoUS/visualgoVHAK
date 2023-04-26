#pragma once
#include "CircularlyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderCLL(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadCLL(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderAddHeadCLLStep(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderAddTailCLL(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderAddTailCLLStep(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexCLL(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderAddIndexCLLStep(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadCLL(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed);

void RenderDeleteHeadCLLStep(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailCLL(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed);

void RenderDeleteTailCLLStep(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeletePositionCLL(int index, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderDeletePositionCLLStep(int index, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderUpdateIndexCLL(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderUpdateIndexCLLStep(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderSearchCLL(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed);

void RenderSearchCLLStep(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);


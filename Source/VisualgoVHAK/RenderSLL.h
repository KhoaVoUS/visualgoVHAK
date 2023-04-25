#pragma once
#include "SinglyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderSLL(singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadSLL(int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed);

void RenderAddHeadSLLStep(int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddTailSLL(int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed);

void RenderAddTailSLLStep(int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexSLL(int index, int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderAddIndexSLLStep(int index, int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderUpdateIndexSLL(int index, int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderUpdateIndexSLLStep(int index, int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadSLL(singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed);

void RenderDeleteHeadSLLStep(singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailSLL(singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed);

void RenderDeleteTailSLLStep(singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeletePositionSLL(int index, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed);

void RenderDeletePositionSLLStep(int index, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderSearchSLL(int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed);

void RenderSearchSLLStep(int value, singlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);


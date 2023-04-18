#pragma once
#include "DoublyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderDynamicArray(std::vector<int>& a, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderSearchDynamicArray(int value, std::vector<int>& a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, float speed);

void RenderSearchDynamicArrayStep(int value, std::vector<int>& a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, sf::Color bg);

void RenderUpdateDynamicArray(int value, int index, std::vector<int>& a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, float speed);

void RenderUpdateDynamicArrayStep(int value, int index, std::vector<int>& a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, sf::Color bg);


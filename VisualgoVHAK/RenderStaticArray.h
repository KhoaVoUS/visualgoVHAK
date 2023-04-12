#pragma once
#include "DoublyLinkedList.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderStaticArray(int* a, int array_size, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderSearchStaticArray(int value, int* a, int array_size, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window);

void RenderSearchStaticArrayStep(int value, int* a, int array_size, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, sf::Color bg);


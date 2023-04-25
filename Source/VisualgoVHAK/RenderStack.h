#pragma once
#include "Stack.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderStack(Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadStack(int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed);

void RenderAddHeadStackStep(int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddTailStack(int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddTailStackStep(int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexStack(int index, int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexStackStep(int index, int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadStack(Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed);

void RenderDeleteHeadStackStep(Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailStack(Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailStackStep(Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeletePositionStack(int index, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeletePositionStackStep(int index, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderSearchStack(int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderSearchStackStep(int value, Stack& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);




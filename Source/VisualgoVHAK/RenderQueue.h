#pragma once
#include "Queue.h"
#include <vector>
#include "Button.h"
#include "Arrow.h"

void renderQueue(Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadQueue(int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderAddHeadQueueStep(int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddTailQueue(int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed);

void RenderAddTailQueueStep(int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexQueue(int index, int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderAddIndexQueueStep(int index, int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeleteHeadQueue(Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed);

void RenderDeleteHeadQueueStep(Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailQueue(Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeleteTailQueueStep(Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);

void RenderDeletePositionQueue(int index, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderDeletePositionQueueStep(int index, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg);

void RenderSearchQueue(int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window);

void RenderSearchQueueStep(int value, Queue& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg);


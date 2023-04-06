#pragma once
#include "Button.h"
#include "DoublyLinkedList.h"

void DLLScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& DLL, sf::Color bg, bool& darkMode, doublyLinkedList& dLinkedList, bool& fast);

void InitProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list);

void InitDoublyLinkedList(std::string str, doublyLinkedList& list, bool fast);

void AddHeadProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast);


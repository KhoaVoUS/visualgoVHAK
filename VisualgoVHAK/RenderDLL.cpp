#include "RenderDLL.h"

using namespace std;

void renderDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;
    std::string buttonText;
    while (cur != nullptr)
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth*2; // Increment the position for the next node
        cur = cur->Next;
    }

    for (int i = 0; i < visualizer.size(); i++)
        visualizer[i].render(window);
}


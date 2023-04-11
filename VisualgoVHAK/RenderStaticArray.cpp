#include "RenderStaticArray.h"

using namespace std;

void renderStaticArray(int* a, int array_size, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    for (int i = 0 ; i < array_size ; i++)
    {
        int value = a[i];
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
    }


    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);

    }
}

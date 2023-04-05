#include "RenderDLL.h"
#include <iostream>

using namespace std;

void renderDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

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

    if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);

    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height/2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

}

void RenderAddHeadDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    while (cur != nullptr)
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
    }
    if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();
    
    sf::sleep(sleepTime);

    Button tmp(500.f, 500.f, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    tmp.render(window);

    window.display();
    sf::sleep(sleepTime);

    if (visualizer.size()) visualizer[0].shape.setFillColor(visualizer[0].idleColor);
    tmp.shape.setFillColor(sf::Color::Red);

    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    tmp.render(window);
    if (visualizer.size()) draw2headArrowVertical(tmp.posX + width/2, tmp.posY, visualizer[0].posY + height, window);
    window.display();
    sf::sleep(sleepTime);

}

void RenderAddTailDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    while (cur != nullptr)
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
    }
    if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);
    x = 500.f; // Starting position of the first node
    y = 500.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    sleepTime = sf::seconds(0.3f);
    for (int i = 1; i < visualizer.size(); i++)
    {
        for (int j = 1; j < visualizer.size(); j++)
            visualizer[j].shape.setFillColor(visualizer[j].idleColor);

        visualizer[i].shape.setFillColor(sf::Color::Yellow);
        
        for (int j = 0; j < visualizer.size(); j++)
            visualizer[j].render(window);

        for (int j = 0; j < visualizer.size(); j++)
        {
            visualizer[i].render(window);
            if (j > 0)
            {
                int arrowX = visualizer[j].posX;
                int arrowY = visualizer[j].posY + height / 2;
                int prevArrowX = visualizer[j - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }

    tmp.render(window);
    if (visualizer.size()) draw2headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height/2, window);

    window.display();
    sf::sleep(sleepTime);
}

void RenderAddIndexDLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    while (cur != nullptr)
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
    }
    if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);


    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;

    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    sleepTime = sf::seconds(0.3f);
    for (int i = 1; i < index; i++)
    {
        for (int j = 1; j < visualizer.size(); j++)
            visualizer[j].shape.setFillColor(visualizer[j].idleColor);

        visualizer[i].shape.setFillColor(sf::Color::Yellow);

        for (int j = 0; j < visualizer.size(); j++)
            visualizer[j].render(window);

        visualizer[i].render(window);

        for (int j = 0; j < visualizer.size(); j++)
        {
            
            if (j > 0)
            {
                int arrowX = visualizer[j].posX;
                int arrowY = visualizer[j].posY + height / 2;
                int prevArrowX = visualizer[j - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }

    window.clear(bg);
    for (int j = 0; j < visualizer.size(); j++)
        visualizer[j].render(window);
    for (int j = 0; j < visualizer.size(); j++)
    {
        if (j == index) continue;
        if (j > 0)
        {
            int arrowX = visualizer[j].posX;
            int arrowY = visualizer[j].posY + height / 2;
            int prevArrowX = visualizer[j - 1].posX + width;
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    tmp.render(window);
    draw2headArrowVertical(visualizer[index].posX + width / 2, visualizer[index].posY, tmp.posY + height / 2, window);

    drawArrowVertical(visualizer[index - 1].posX + width , visualizer[index - 1].posY, tmp.posY + height / 2, window);
    draw1headArrowHorizontal(visualizer[index - 1].posX + width, tmp.posX, tmp.posY + height / 2, window);
    sf::sleep(sleepTime);
}



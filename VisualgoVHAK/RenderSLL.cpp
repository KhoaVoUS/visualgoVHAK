#include "RenderSLL.h"
#include <iostream>

using namespace std;

void renderSLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

}

void RenderAddHeadSLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    tmp.render(window);
    if (visualizer.size()) draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
    window.display();
    sf::sleep(sleepTime);

}

void RenderAddHeadSLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg)
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
    Button tmp(500.f, 500.f, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < 4)
    {
        window.clear(bg);
        Previous->render(window);
        Next->render(window);
        Previous->update(window);
        Next->update(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }


        if (currentStep == 0)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                if (i > 0)
                {
                    int arrowX = visualizer[i].posX;
                    int arrowY = visualizer[i].posY + nodeHeight / 2;
                    int prevArrowX = visualizer[i - 1].posX + nodeWidth;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            window.display();
        }

        if (currentStep == 1)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                if (i > 0)
                {
                    int arrowX = visualizer[i].posX;
                    int arrowY = visualizer[i].posY + nodeHeight / 2;
                    int prevArrowX = visualizer[i - 1].posX + nodeWidth;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.render(window);
            window.display();
        }
        if (currentStep == 2)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
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
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.render(window);
            window.display();
        }

        if (currentStep == 3)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
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
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.render(window);
            if (visualizer.size()) draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
            window.display();
        }

    }
    delete Previous, Next;
}

void RenderAddTailSLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);
    x = 500.f; // Starting position of the first node
    y = 500.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

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
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }

    tmp.render(window);
    if (visualizer.size()) draw1headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height / 2, window);

    window.display();
    sf::sleep(sleepTime);
}

void RenderAddTailSLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg)
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
    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < visualizer.size() + 2)
    {
        window.clear(bg);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == visualizer.size())
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.render(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        if (currentStep == visualizer.size() + 1)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.render(window);
            if (visualizer.size()) draw1headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height / 2, window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderAddIndexSLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);


    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;

    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

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
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    tmp.render(window);
    draw1headArrowVertical(visualizer[index].posX + width / 2, tmp.posY + height / 2, visualizer[index].posY, window);

    drawArrowVertical(visualizer[index - 1].posX + width, tmp.posY + height / 2, visualizer[index - 1].posY, window);
    draw1headArrowHorizontal(visualizer[index - 1].posX + width, tmp.posX, tmp.posY + height / 2, window);

    window.display();
    sf::sleep(sleepTime);
}

void RenderAddIndexSLLStep(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
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
    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < index + 2)
    {
        window.clear(bg);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }
        if (currentStep < index)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == index)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
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
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.render(window);
        }

        if (currentStep == index + 1)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
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
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.render(window);
            draw1headArrowVertical(visualizer[index].posX + width / 2, tmp.posY + height / 2, visualizer[index].posY, window);

            drawArrowVertical(visualizer[index - 1].posX + width, tmp.posY + height / 2, visualizer[index - 1].posY, window);
            draw1headArrowHorizontal(visualizer[index - 1].posX + width, tmp.posX, tmp.posY + height / 2, window);
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderUpdateIndexSLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f) / speed;
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
    Button tmp(visualizer[index].posX, visualizer[index].posY, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    window.display();

    sf::sleep(sleepTime);


    for (int i = 1; i <= index; i++)
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
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }


        window.display();
        sf::sleep(sleepTime);
    }
    window.clear(bg);
    for (int i = 0; i < visualizer.size(); i++) visualizer[i].shape.setFillColor(visualizer[i].idleColor);
    for (int i = 0; i < visualizer.size(); i++) visualizer[i].render(window);
    for (int j = 0; j < visualizer.size(); j++)
    {

        if (j > 0)
        {
            int arrowX = visualizer[j].posX;
            int arrowY = visualizer[j].posY + height / 2;
            int prevArrowX = visualizer[j - 1].posX + width;
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    tmp.shape.setFillColor(sf::Color::Cyan);
    tmp.render(window);
    window.display();
    sf::sleep(sleepTime);

}

void RenderUpdateIndexSLLStep(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
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
    x = visualizer[index].posX;
    y = visualizer[index].posY;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < index + 2)
    {
        window.clear(bg);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }
        if (currentStep <= index)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == index + 1)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);

            for (int j = 0; j < visualizer.size(); j++)
                visualizer[j].render(window);

            for (int j = 0; j < visualizer.size(); j++)
            {
                if (j > 0)
                {
                    int arrowX = visualizer[j].posX;
                    int arrowY = visualizer[j].posY + height / 2;
                    int prevArrowX = visualizer[j - 1].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.shape.setFillColor(sf::Color::Cyan);
            tmp.render(window);
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderDeleteHeadSLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);
    if (visualizer.size() > 1) {
        visualizer[1].shape.setFillColor(sf::Color::Red);
        visualizer[0].shape.setFillColor(visualizer[0].idleColor);
    }

    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();
    sf::sleep(sleepTime);

}

void RenderDeleteHeadSLLStep(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg) {
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



    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < 3)
    {
        window.clear(bg);
        Previous->render(window);
        Next->render(window);
        Previous->update(window);
        Next->update(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }

        if (currentStep == 0)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++) visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                if (i > 0)
                {
                    int arrowX = visualizer[i].posX;
                    int arrowY = visualizer[i].posY + height / 2;
                    int prevArrowX = visualizer[i - 1].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }

        if (currentStep == 1)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            if (visualizer.size() > 1) {
                visualizer[1].shape.setFillColor(sf::Color::Red);
                visualizer[0].shape.setFillColor(visualizer[0].idleColor);
            }
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                if (i > 0)
                {
                    int arrowX = visualizer[i].posX;
                    int arrowY = visualizer[i].posY + height / 2;
                    int prevArrowX = visualizer[i - 1].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }

        if (currentStep == 2)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            if (visualizer.size() > 1) {
                visualizer[1].shape.setFillColor(sf::Color::Red);
                visualizer[0].shape.setFillColor(visualizer[0].idleColor);
            }
            for (int i = 1; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                if (i > 1)
                {
                    int arrowX = visualizer[i].posX;
                    int arrowY = visualizer[i].posY + height / 2;
                    int prevArrowX = visualizer[i - 1].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }
        window.display();
    }
    delete Previous, Next;

}

void RenderDeleteTailSLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);
    x = 500.f; // Starting position of the first node
    y = 500.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    for (int i = 1; i < visualizer.size(); i++)
    {
        window.clear(bg);
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
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }

    window.clear(bg);
    for (int i = 0; i < visualizer.size() - 1; i++)
    {
        visualizer[i].render(window);
        if (i > 0)
        {
            int arrowX = visualizer[i].posX;
            int arrowY = visualizer[i].posY + height / 2;
            int prevArrowX = visualizer[i - 1].posX + width;
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();
    sf::sleep(sleepTime);

}

void RenderDeleteTailSLLStep(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg)
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < visualizer.size() + 2)
    {
        window.clear(bg);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        if (currentStep == visualizer.size())
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size() - 1; i++)
            {
                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == visualizer.size() + 1)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);

            for (int i = 0; i < visualizer.size() - 1; i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size() - 1; i++)
            {
                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        window.display();
    }
    delete Previous, Next;

}

void RenderDeletePositionSLL(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed) {
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);


    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;
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
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
        if (j == index || j == index + 1) continue;
        if (j > 0)
        {
            int arrowX = visualizer[j].posX;
            int arrowY = visualizer[j].posY + height / 2;
            int prevArrowX = visualizer[j - 1].posX + width;
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }


    window.display();
    sf::sleep(sleepTime);

    window.clear(bg);
    for (int j = 0; j < visualizer.size(); j++) if (j != index)
        visualizer[j].render(window);

    for (int j = 0; j < visualizer.size(); j++)
    {
        if (j == index) continue;
        if (j > 0)
        {
            int arrowX = visualizer[j].posX;
            int arrowY = visualizer[j].posY + height / 2;
            int prevArrowX = visualizer[j - 1].posX + width;
            if (j == index + 1) prevArrowX = visualizer[j - 2].posX + width;
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }
    window.display();
    sf::sleep(sleepTime);
};

void RenderDeletePositionSLLStep(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
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
    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < index + 2)
    {
        window.clear(bg);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }
        if (currentStep < index)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        if (currentStep == index)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int j = 0; j < visualizer.size(); j++)
                visualizer[j].render(window);

            for (int j = 0; j < visualizer.size(); j++)
            {
                if (j == index || j == index + 1) continue;
                if (j > 0)
                {
                    int arrowX = visualizer[j].posX;
                    int arrowY = visualizer[j].posY + height / 2;
                    int prevArrowX = visualizer[j - 1].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }

        if (currentStep == index + 1)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int j = 0; j < visualizer.size(); j++) if (j != index)
                visualizer[j].render(window);

            for (int j = 0; j < visualizer.size(); j++)
            {
                if (j == index) continue;
                if (j > 0)
                {
                    int arrowX = visualizer[j].posX;
                    int arrowY = visualizer[j].posY + height / 2;
                    int prevArrowX = visualizer[j - 1].posX + width;
                    if (j == index + 1) prevArrowX = visualizer[j - 2].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderSearchSLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
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
            draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
        }
    }

    window.display();

    sf::sleep(sleepTime);
    x = 500.f; // Starting position of the first node
    y = 500.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    for (int i = 1; i < visualizer.size(); i++)
    {
        for (int j = 1; j < visualizer.size(); j++)
        {
            visualizer[j].shape.setFillColor(visualizer[j].idleColor);
        }

        visualizer[i].shape.setFillColor(sf::Color::Yellow);

        for (int j = 0; j <= i; j++)
        {
            std::string tmp = visualizer[j].text.getString().toAnsiString();

            int cur = std::stoi(tmp);
            if (cur == value) visualizer[j].shape.setFillColor(sf::Color::Cyan);
        }

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
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }
    sf::sleep(sleepTime);
}

void RenderSearchSLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg) {
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
    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < visualizer.size())
    {
        window.clear(bg);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Previous->isClicked(window))
            {
                currentStep--;
                if (currentStep < 0)
                {
                    currentStep = 0;
                }
            }
            else if (Next->isClicked(window))
            {
                currentStep++;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);


            for (int j = 0; j <= currentStep; j++)
            {
                std::string tmp = visualizer[j].text.getString().toAnsiString();

                int cur = std::stoi(tmp);
                if (cur == value) visualizer[j].shape.setFillColor(sf::Color::Cyan);
            }

            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }


        window.display();
    }
    delete Previous, Next;
}






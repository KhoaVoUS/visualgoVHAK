#include "RenderCLL.h"
#include "PseudoCodeBlock.h"
#include <iostream>

using namespace std;

void renderCLL(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    Node* cur = list.pHead;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }


    if (visualizer.size()) {
        visualizer[0].shape.setFillColor(sf::Color::Red);
        sf::Text txt;
        txt.setFont(font);
        txt.setPosition(visualizer[0].posX, visualizer[0].posY - 50);
        sf::Color lightBlue(173, 216, 230);
        txt.setString("pHead");
        txt.setCharacterSize(15);
        txt.setFillColor(lightBlue);
        window.draw(txt);
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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height*2, window);
    }
}

void RenderAddHeadCLL(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.3f) / speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock

    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx", font, 16, sf::Color::Black);
    a.addLine("head = pre", font, 16, sf::Color::Black);
    //step 1
    a.draw(window);
    for (int i = 1; i < visualizer.size(); i++)
    {
        window.clear(bg);
        a.changeLineColor(2, sf::Color::Red);
        a.changeLineColor(1, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(2, sf::Color::Black);
        a.changeLineColor(1, sf::Color::Black);
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
        if (visualizer.size())
        {
            drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
            draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
            drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
        }

        window.display();
        sf::sleep(sleepTime);
    }

    //step 2
    x = 500, y = 500;

    if (visualizer.size())
    {
        x = visualizer[0].posX;
        y = visualizer[0].posY + height*2;
    }
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
    }
    tmp.render(window);
    a.changeLineColor(4, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);

    //step 3
    window.clear(bg);
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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
    }
    draw1headArrowVertical(tmp.posX + width/2, tmp.posY, visualizer[0].posY + height, window);
    tmp.render(window);
    a.changeLineColor(5, sf::Color::Red);
    a.changeLineColor(6, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(5, sf::Color::Black);
    a.changeLineColor(6, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);
    //step 4
    window.clear(bg);
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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
    }
    draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
    tmp.render(window);
    a.changeLineColor(7, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(7, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);
}

void RenderAddHeadCLLStep(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);

    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx", font, 16, sf::Color::Black);
    a.addLine("head = pre", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    x = 500, y = 500;

    if (visualizer.size())
    {
        x = visualizer[0].posX;
        y = visualizer[0].posY + height * 2;
    }
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < visualizer.size() + 5)
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
            else if (Last->isClicked(window))
            {
                currentStep = visualizer.size() + 5;
            }
        }

        if (currentStep < visualizer.size())
        {
            window.clear(bg);
            a.changeLineColor(2, sf::Color::Red);
            a.changeLineColor(1, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(2, sf::Color::Black);
            a.changeLineColor(1, sf::Color::Black);
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
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(4, sf::Color::Black);
            visualizer.back().shape.setFillColor(ButtonBg);
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
            a.changeLineColor(5, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(5, sf::Color::Black);
            visualizer.back().shape.setFillColor(ButtonBg);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
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

        if (currentStep == visualizer.size() + 2)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);

            tmp.render(window);
            a.draw(window);
            visualizer.back().shape.setFillColor(ButtonBg);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
            }
            if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
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

        if (currentStep == visualizer.size() + 3)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.render(window);
            a.changeLineColor(6, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(6, sf::Color::Black);
            visualizer.back().shape.setFillColor(ButtonBg);
            draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
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

        if (currentStep == visualizer.size() + 4)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(7, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(7, sf::Color::Black);
            tmp.shape.setFillColor(sf::Color::Red);
            tmp.render(window);
            visualizer.back().shape.setFillColor(ButtonBg);
            draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
            }
            if (visualizer.size()) visualizer[0].shape.setFillColor(visualizer[0].idleColor);
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
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;
}

void RenderAddTailCLL(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.3f) / speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock

    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx", font, 16, sf::Color::Black);
    //step 1
    a.draw(window);
    for (int i = 1; i < visualizer.size(); i++)
    {
        window.clear(bg);
        a.changeLineColor(2, sf::Color::Red);
        a.changeLineColor(1, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(2, sf::Color::Black);
        a.changeLineColor(1, sf::Color::Black);
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
        if (visualizer.size())
        {
            drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
            draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
            drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
        }

        window.display();
        sf::sleep(sleepTime);
    }

    //step 2
    x = 500, y = 500;

    if (visualizer.size())
    {
        x = visualizer[0].posX;
        y = visualizer[0].posY + height * 2;
    }
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
    }
    tmp.render(window);
    a.changeLineColor(4, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);

    //step 3
    window.clear(bg);
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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
    }
    draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
    tmp.render(window);
    a.changeLineColor(5, sf::Color::Red);
    a.changeLineColor(6, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(5, sf::Color::Black);
    a.changeLineColor(6, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);

}

void RenderAddTailCLLStep(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg)
{
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);

    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    x = 500, y = 500;

    if (visualizer.size())
    {
        x = visualizer[0].posX;
        y = visualizer[0].posY + height * 2;
    }
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < visualizer.size() + 4)
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
            else if (Last->isClicked(window))
            {
                currentStep = visualizer.size() + 4;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);
            a.changeLineColor(2, sf::Color::Red);
            a.changeLineColor(1, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(2, sf::Color::Black);
            a.changeLineColor(1, sf::Color::Black);
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
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(4, sf::Color::Black);
            visualizer.back().shape.setFillColor(ButtonBg);
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
            a.changeLineColor(5, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(5, sf::Color::Black);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
            }
            visualizer.back().shape.setFillColor(ButtonBg);
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

        if (currentStep == visualizer.size() + 2)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);

            tmp.render(window);
            a.draw(window);
            visualizer.back().shape.setFillColor(ButtonBg);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
            }
            if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
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

        if (currentStep == visualizer.size() + 3)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.render(window);
            a.changeLineColor(6, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(6, sf::Color::Black);
            visualizer.back().shape.setFillColor(ButtonBg);
            draw1headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 4, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 4, visualizer[0].posY + height * 3, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 4, window);
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
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;
}

void RenderAddIndexCLL(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
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
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);

    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++) ", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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
        a.changeLineColor(2, sf::Color::Red);
        a.changeLineColor(1, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(2, sf::Color::Black);
        a.changeLineColor(1, sf::Color::Black);
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

        if (visualizer.size())
        {
            drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
            draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
            drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
        }

        window.display();
        sf::sleep(sleepTime);
    }

    window.clear(bg);
    for (int j = 0; j < visualizer.size(); j++)
        visualizer[j].render(window);


    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
    }
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
    a.changeLineColor(4, sf::Color::Red);
    a.changeLineColor(5, sf::Color::Red);
    a.changeLineColor(6, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    a.changeLineColor(5, sf::Color::Black);
    a.changeLineColor(6, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);
}

void RenderAddIndexCLLStep(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);

    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++) ", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    
    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = index + 2;
            }
        }
        if (currentStep < index)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(1, sf::Color::Red);
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(1, sf::Color::Black);
            a.changeLineColor(2, sf::Color::Black);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);

            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
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

        if (currentStep == index)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(4, sf::Color::Black);
            for (int j = 0; j < visualizer.size(); j++)
                visualizer[j].render(window);

            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
            }
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
            a.changeLineColor(5, sf::Color::Red);
            a.changeLineColor(6, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(5, sf::Color::Black);
            a.changeLineColor(6, sf::Color::Black);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
            }
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
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;
}

void RenderUpdateIndexCLL(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.3f) / speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 300.f, sf::Color::White);

    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("pre.item = value", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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
        a.changeLineColor(1, sf::Color::Red);
        a.changeLineColor(2, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(1, sf::Color::Black);
        a.changeLineColor(2, sf::Color::Black);
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
    a.changeLineColor(3, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(3, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);

}

void RenderUpdateIndexCLLStep(int index, int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
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
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 300.f, sf::Color::White);

    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("pre.item = value", font, 16, sf::Color::Black);
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    x = visualizer[index].posX;
    y = visualizer[index].posY;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = index + 2;
            }
        }
        if (currentStep <= index)
        {
            window.clear(bg);
            a.changeLineColor(1, sf::Color::Red);
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(1, sf::Color::Black);
            a.changeLineColor(2, sf::Color::Black);
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
            a.changeLineColor(3, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(3, sf::Color::Black);
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
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;
}

void RenderDeleteHeadCLL(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed)
{
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("pre.next = head->next", font, 16, sf::Color::Black);
    a.addLine("head = head->next", font, 16, sf::Color::Black);
    sf::Time sleepTime = sf::seconds(0.3f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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
    //step 1
    for (int i = 1; i < visualizer.size(); i++)
    {
        window.clear(bg);
        a.changeLineColor(1, sf::Color::Red);
        a.changeLineColor(2, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(1, sf::Color::Black);
        a.changeLineColor(2, sf::Color::Black);
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

        if (visualizer.size())
        {
            drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
            draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
            drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
        }

        window.display();
        sf::sleep(sleepTime);
    }
    // step 2
    window.clear(bg);
    
    a.changeLineColor(3, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(3, sf::Color::Black);
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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[1].posX, visualizer.back().posY + height * 2, visualizer[1].posY + height, window);
        drawArrowHorizontal(visualizer[1].posX, visualizer.back().posX + width + 20, visualizer[1].posY + height * 2, window);
    }
    window.display();
    sf::sleep(sleepTime);
    //step 3
    window.clear(bg);
    a.changeLineColor(4, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
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

    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[1].posX, visualizer.back().posY + height * 2, visualizer[1].posY + height, window);
        drawArrowHorizontal(visualizer[1].posX, visualizer.back().posX + width + 20, visualizer[1].posY + height * 2, window);
    }
    window.display();
    sf::sleep(sleepTime);

}

void RenderDeleteHeadCLLStep(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;
    PseudoCodeBlock a(font, 0.f, 0.f, 300.f, 300.f, sf::Color::White);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("pre.next = head->next", font, 16, sf::Color::Black);
    a.addLine("head = head->next", font, 16, sf::Color::Black);
    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = visualizer.size() + 2;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);
            a.changeLineColor(1, sf::Color::Red);
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(1, sf::Color::Black);
            a.changeLineColor(2, sf::Color::Black);
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

            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
            }
        }

        if (currentStep == visualizer.size())
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(3, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(3, sf::Color::Black);
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

            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[1].posX, visualizer.back().posY + height * 2, visualizer[1].posY + height, window);
                drawArrowHorizontal(visualizer[1].posX, visualizer.back().posX + width + 20, visualizer[1].posY + height * 2, window);
            }

        }

        if (currentStep == visualizer.size() + 1)
        {
            window.clear(bg);
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(4, sf::Color::Black);
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

            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[1].posX, visualizer.back().posY + height * 2, visualizer[1].posY + height, window);
                drawArrowHorizontal(visualizer[1].posX, visualizer.back().posX + width + 20, visualizer[1].posY + height * 2, window);
            }

        }
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;

}

void RenderDeleteTailCLL(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.3f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("Vertex del = pre.next, aft = del.next", font, 16, sf::Color::Black);
    a.addLine("pre.next = aft, aft.prev = pre", font, 16, sf::Color::Black);
    a.addLine("delete del", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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
    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
    }
    window.display();

    sf::sleep(sleepTime);
    x = 500.f; // Starting position of the first node
    y = 500.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    for (int i = 1; i < visualizer.size() - 1; i++)
    {
        window.clear(bg);
        a.changeLineColor(1, sf::Color::Red);
        a.changeLineColor(2, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(1, sf::Color::Black);
        a.changeLineColor(2, sf::Color::Black);
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
        if (visualizer.size())
        {
            drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
            draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
            drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
        }

        window.display();
        sf::sleep(sleepTime);
    }
    //step 2
    window.clear(bg);
    a.changeLineColor(4, sf::Color::Red);
    a.changeLineColor(5, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    a.changeLineColor(5, sf::Color::Black);
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
    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
        drawArrowHorizontal(visualizer.back().posX - width, visualizer.back().posX + width + 10, visualizer[0].posY + height, window);
    }

    window.display();
    sf::sleep(sleepTime);

}

void RenderDeleteTailCLLStep(circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg)
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
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("do pre = pre.next", font, 16, sf::Color::Black);
    a.addLine(" while (pre != head)", font, 16, sf::Color::Black);
    a.addLine("Vertex del = pre.next, aft = del.next", font, 16, sf::Color::Black);
    a.addLine("pre.next = aft, aft.prev = pre", font, 16, sf::Color::Black);
    a.addLine("delete del", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = visualizer.size() + 2;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);
            a.changeLineColor(1, sf::Color::Red);
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(1, sf::Color::Black);
            a.changeLineColor(2, sf::Color::Black);
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

            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
            }

        }

        if (currentStep == visualizer.size())
        {
            window.clear(bg);
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(4, sf::Color::Black);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                if (i > 0 && i < visualizer.size() - 1)
                {
                    int arrowX = visualizer[i].posX;
                    int arrowY = visualizer[i].posY + height / 2;
                    int prevArrowX = visualizer[i - 1].posX + width;
                    draw1headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
                drawArrowHorizontal(visualizer.back().posX - width, visualizer.back().posX + width + 10, visualizer[0].posY + height, window);
            }
        }

        if (currentStep == visualizer.size() + 1)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(5, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(5, sf::Color::Black);
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
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
                drawArrowHorizontal(visualizer.back().posX - width, visualizer.back().posX + width + 10, visualizer[0].posY + height, window);
            }
        }
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;

}

void RenderDeletePositionCLL(int index, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed) {
    sf::Time sleepTime = sf::seconds(0.5f) / speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 500.f, 500.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex del = pre.next, aft = del.next", font, 16, sf::Color::Black);
    a.addLine("pre.next = aft, aft.prev = pre", font, 16, sf::Color::Black);
    a.addLine("delete del", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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
    a.changeLineColor(0, sf::Color::Red);
    a.changeLineColor(1, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(0, sf::Color::Black);
    a.changeLineColor(1, sf::Color::Black);
    window.display();

    sf::sleep(sleepTime);


    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;

    for (int i = 1; i < index; i++)
    {
        window.clear(bg);
        a.changeLineColor(2, sf::Color::Red);
        a.changeLineColor(3, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(2, sf::Color::Black);
        a.changeLineColor(3, sf::Color::Black);
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
    a.changeLineColor(4, sf::Color::Red);
    a.changeLineColor(5, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    a.changeLineColor(5, sf::Color::Black);

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
    a.changeLineColor(6, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(6, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);
};

void RenderDeletePositionCLLStep(int index, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 500.f, 500.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex del = pre.next, aft = del.next", font, 16, sf::Color::Black);
    a.addLine("pre.next = aft, aft.prev = pre", font, 16, sf::Color::Black);
    a.addLine("delete del", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    x = visualizer[index].posX;
    y = visualizer[index].posY - 100;

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = index + 2;
            }
        }
        if (currentStep < index)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(2, sf::Color::Red);
            a.changeLineColor(3, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(2, sf::Color::Black);
            a.changeLineColor(3, sf::Color::Black);
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
            a.changeLineColor(5, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(5, sf::Color::Black);
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
            a.changeLineColor(6, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(6, sf::Color::Black);
        }
        Last->render(window);
        Last->update(window);
        window.display();
    }
    delete Previous, Next, Last;
}

void RenderSearchCLL(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
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

    // Add the desired lines to the PseudoCodeBlock
    PseudoCodeBlock a(font, 0.f, 0.f, 700.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("temp = head", font, 16, sf::Color::Black);
    a.addLine("do", font, 16, sf::Color::Black);
    a.addLine("  if temp.item == v, temp.highlight = true while (temp!=head)", font, 16, sf::Color::Black);
    a.addLine("  temp = temp.next", font, 16, sf::Color::Black);

    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
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
    if (visualizer.size())
    {
        drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
        draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
        drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
    }
    window.display();

    sf::sleep(sleepTime);
    x = 500.f; // Starting position of the first node
    y = 500.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    for (int i = 1; i < visualizer.size(); i++)
    {
        a.changeLineColor(1, sf::Color::Red);
        a.changeLineColor(2, sf::Color::Red);
        a.changeLineColor(3, sf::Color::Red);
        a.draw(window);
        a.changeLineColor(1, sf::Color::Black);
        a.changeLineColor(2, sf::Color::Black);
        a.changeLineColor(3, sf::Color::Black);
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
        if (visualizer.size())
        {
            drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
            draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
            drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
        }
        window.display();
        sf::sleep(sleepTime);
    }
    sf::sleep(sleepTime);
}

void RenderSearchCLLStep(int value, circularlyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 700.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("temp = head", font, 16, sf::Color::Black);
    a.addLine("do", font, 16, sf::Color::Black);
    a.addLine("  if temp.item == v, temp.highlight = true while temp != head", font, 16, sf::Color::Black);
    a.addLine("  temp = temp.next", font, 16, sf::Color::Black);
    std::string buttonText;
    bool firstNode = true;

    while (cur != nullptr && (firstNode || cur != list.pHead))
    {
        int value = cur->data;
        buttonText = std::to_string(value);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
        cur = cur->Next;
        firstNode = false;
    }
    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;
    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = visualizer.size() - 1;
            }
        }
        if (currentStep < visualizer.size())
        {
            window.clear(bg);
            a.changeLineColor(1, sf::Color::Red);
            a.changeLineColor(2, sf::Color::Red);
            a.changeLineColor(3, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(1, sf::Color::Black);
            a.changeLineColor(2, sf::Color::Black);
            a.changeLineColor(3, sf::Color::Black);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            visualizer[currentStep].shape.setFillColor(sf::Color::Yellow);
            if (visualizer.size())
            {
                drawArrowVertical(visualizer.back().posX + width, visualizer.back().posY + height, visualizer.back().posY + height * 2, window);
                draw1headArrowVertical(visualizer[0].posX, visualizer.back().posY + height * 2, visualizer[0].posY + height, window);
                drawArrowHorizontal(visualizer[0].posX, visualizer.back().posX + width + 20, visualizer[0].posY + height * 2, window);
            }

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
        Last->render(window);
        Last->update(window);

        window.display();
    }
    delete Previous, Next, Last;
}






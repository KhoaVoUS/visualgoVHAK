#include "RenderDLL.h"
#include "PseudoCodeBlock.h"
#include <iostream>

using namespace std;

void renderDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
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

    if (visualizer.size()) {
        visualizer[0].shape.setFillColor(sf::Color::Red);
        visualizer.back().shape.setFillColor(sf::Color::Red);
    }

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
 
void RenderAddHeadDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    PseudoCodeBlock a(font, 0.f, 0.f, 550.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = head, if (head != null) head.prev = vtx", font, 16, sf::Color::Black);
    a.addLine("head = vtx", font, 16, sf::Color::Black);

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
    a.draw(window);
    window.display();
    
    sf::sleep(sleepTime);

    Button tmp(400.f, 400.f, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
    a.changeLineColor(0, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(0, sf::Color::Black);
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
    a.changeLineColor(1, sf::Color::Red);
    a.changeLineColor(2, sf::Color::Red);
    a.draw(window);
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

void RenderAddHeadDLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = head, if (head != null) head.prev = vtx", font, 16, sf::Color::Black);
    a.addLine("head = vtx", font, 16, sf::Color::Black);
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
    Button tmp(400.f, 400.f, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            a.draw(window);
            window.display();
        }
            
        if (currentStep == 1)
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            a.changeLineColor(0, sf::Color::Red);
            a.draw(window);
            tmp.render(window);
            a.changeLineColor(0, sf::Color::Black);
            window.display();
        }
        if (currentStep == 2)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            if (visualizer.size()) visualizer[0].shape.setFillColor(sf::Color::Red);
            tmp.shape.setFillColor(ButtonBg);

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
            a.changeLineColor(1, sf::Color::Red);
            a.draw(window);
            tmp.render(window);
            a.changeLineColor(1, sf::Color::Black);
            if (visualizer.size()) draw2headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            tmp.render(window);
            a.changeLineColor(2, sf::Color::Black);
            if (visualizer.size()) draw2headArrowVertical(tmp.posX + width / 2, tmp.posY, visualizer[0].posY + height, window);
            window.display();
        }

    }
    delete Previous, Next;
}

void RenderAddTailDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("tail.next = vtx, vtx.prev = tail", font, 16, sf::Color::Black);
    a.addLine("tail = vtx", font, 16, sf::Color::Black);
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
    if (visualizer.size()) {
        visualizer[0].shape.setFillColor(sf::Color::Red);
        visualizer.back().shape.setFillColor(sf::Color::Red);
    }
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
    x = 400.f; // Starting position of the first node
    y = 400.f;

    if (visualizer.size()) x = visualizer.back().posX, y = visualizer.back().posY - 100;

    Button tmp(x, y, nodeWidth, nodeHeight, font, to_string(value), ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);

    sleepTime = sf::seconds(0.3f);
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
    if (visualizer.size()) draw2headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height/2, window);
    a.changeLineColor(0, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(0, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);
    //step 2
    if (visualizer.size()) draw2headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height / 2, window);
    a.changeLineColor(1, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(1, sf::Color::Black);
    tmp.render(window);
    window.display();
    sf::sleep(sleepTime);
    //step 3
    if (visualizer.size()) visualizer.back().shape.setFillColor(ButtonBg);
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
    if (visualizer.size()) draw2headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height / 2, window);
    a.changeLineColor(2, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(2, sf::Color::Black);
    tmp.shape.setFillColor(sf::Color::Red);
    tmp.render(window);
    window.display();
    sf::sleep(sleepTime);
    
}

void RenderAddTailDLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("tail.next = vtx, vtx.prev = tail", font, 16, sf::Color::Black);
    a.addLine("tail = vtx", font, 16, sf::Color::Black);
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

    while (currentStep <  3)
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

        if (currentStep == 0)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.shape.setFillColor(ButtonBg);
            tmp.render(window);
            if (visualizer.size())
            {
                visualizer[0].shape.setFillColor(sf::Color::Red);
                visualizer.back().shape.setFillColor(sf::Color::Red);
            }
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
            a.changeLineColor(0, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(0, sf::Color::Black);
        }

        if (currentStep == 1)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.shape.setFillColor(ButtonBg);
            tmp.render(window);
            if (visualizer.size()) draw2headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height / 2, window);
            if (visualizer.size())
            {
                visualizer[0].shape.setFillColor(sf::Color::Red);
                visualizer.back().shape.setFillColor(sf::Color::Red);
            }
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
            a.changeLineColor(1, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(1, sf::Color::Black);
        }

        if (currentStep == 2)
        {
            window.clear(bg);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            tmp.shape.setFillColor(sf::Color::Red);
            tmp.render(window);
            if (visualizer.size()) draw2headArrowVertical(visualizer.back().posX + width / 2, visualizer.back().posY, tmp.posY + height / 2, window);
            if (visualizer.size())
            {
                visualizer[0].shape.setFillColor(sf::Color::Red);
                visualizer.back().shape.setFillColor(ButtonBg);
            }
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {

                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(2, sf::Color::Black);
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderAddIndexDLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/ speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 300.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft, aft.prev = vtx", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx, vtx.prev = pre", font, 16, sf::Color::Black);
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
    for (int i = 1; i < index; i++)
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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }
    window.clear(bg);
    a.changeLineColor(4, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    for (int j = 0; j < visualizer.size(); j++)
        visualizer[j].render(window);
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
    tmp.render(window);
    window.display();
    sf::sleep(sleepTime);
    //
    window.clear(bg);
    a.changeLineColor(6, sf::Color::Red);
    a.changeLineColor(5, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(6, sf::Color::Black);
    a.changeLineColor(5, sf::Color::Black);
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

    draw1headArrowVertical(visualizer[index - 1].posX + width , tmp.posY + height / 2, visualizer[index - 1].posY,  window);
    draw1headArrowHorizontal(visualizer[index - 1].posX + width, tmp.posX, tmp.posY + height / 2, window);

    window.display();
    sf::sleep(sleepTime);
}

void RenderAddIndexDLLStep(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 300.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex aft = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex vtx = new Vertex(v)", font, 16, sf::Color::Black);
    a.addLine("vtx.next = aft, aft.prev = vtx", font, 16, sf::Color::Black);
    a.addLine("pre.next = vtx, vtx.prev = pre", font, 16, sf::Color::Black);
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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == index)
        {
            window.clear(bg);
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(4, sf::Color::Black);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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

            draw1headArrowVertical(visualizer[index - 1].posX + width, tmp.posY + height / 2, visualizer[index - 1].posY, window);
            draw1headArrowHorizontal(visualizer[index - 1].posX + width, tmp.posX, tmp.posY + height / 2, window);
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderUpdateIndexDLL(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.3f) / speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
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
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
            draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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

void RenderUpdateIndexDLLStep(int index, int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            tmp.shape.setFillColor(sf::Color::Cyan);
            tmp.render(window);
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderDeleteHeadDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("temp = head", font, 16, sf::Color::Black);
    a.addLine("head = head.next", font, 16, sf::Color::Black);
    a.addLine("delete temp", font, 16, sf::Color::Black);
    a.addLine("if (head != null) head.prev = null", font, 16, sf::Color::Black);
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
    a.changeLineColor(1, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(1, sf::Color::Black);
    if (visualizer.size()) {
        visualizer[0].shape.setFillColor(sf::Color::Red);
        visualizer.back().shape.setFillColor(sf::Color::Red);
    }
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

    if (visualizer.size() > 1) {
        visualizer[1].shape.setFillColor(sf::Color::Red);
        visualizer[0].shape.setFillColor(visualizer[0].idleColor);
    }
    a.changeLineColor(2, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(2, sf::Color::Black);
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

    window.clear(bg);
    if (visualizer.size() > 1) {
        visualizer[1].shape.setFillColor(sf::Color::Red);
        visualizer[0].shape.setFillColor(visualizer[0].idleColor);
    }
    a.changeLineColor(3, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(3, sf::Color::Black);
    for (int i = 1; i < visualizer.size(); i++)
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

}

void RenderDeleteHeadDLLStep(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("temp = head", font, 16, sf::Color::Black);
    a.addLine("head = head.next", font, 16, sf::Color::Black);
    a.addLine("delete temp", font, 16, sf::Color::Black);
    a.addLine("if (head != null) head.prev = null", font, 16, sf::Color::Black);
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
            a.changeLineColor(0, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(0, sf::Color::Black);
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            for (int i = 0; i < visualizer.size(); i++) visualizer[i].shape.setFillColor(visualizer[i].idleColor);
            if (visualizer.size())
            {
                visualizer[0].shape.setFillColor(sf::Color::Red);
                visualizer.back().shape.setFillColor(sf::Color::Red);
            }
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
        }

        if (currentStep == 1)
        {
            window.clear(bg);
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(2, sf::Color::Black);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }

        if (currentStep == 2)
        {
            window.clear(bg);
            a.changeLineColor(3, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(3, sf::Color::Black);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
        }
        window.display();
    }
    delete Previous, Next;

}

void RenderDeleteTailDLL(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
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
    if (visualizer.size())
    {
        visualizer[0].shape.setFillColor(sf::Color::Red);
        visualizer.back().shape.setFillColor(sf::Color::Red);
    }
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("temp = tail", font, 16, sf::Color::Black);
    a.addLine("tail = tail.prev", font, 16, sf::Color::Black);
    a.addLine("tail.next = null", font, 16, sf::Color::Black);
    a.addLine("delete temp", font, 16, sf::Color::Black);

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
    a.changeLineColor(0, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(0, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);
    x = 400.f; // Starting position of the first node
    y = 400.f;

    visualizer.back().shape.setFillColor(ButtonBg);
    if (visualizer.size() - 2 >= 0) visualizer[visualizer.size() - 2].shape.setFillColor(sf::Color::Red);

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
    a.changeLineColor(2, sf::Color::Red);
    a.changeLineColor(3, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(2, sf::Color::Black);
    a.changeLineColor(3, sf::Color::Black);
    window.display();
    sf::sleep(sleepTime);


    window.clear(bg);
    a.changeLineColor(4, sf::Color::Red);
    a.draw(window);
    a.changeLineColor(4, sf::Color::Black);
    for (int i = 0; i < visualizer.size() - 1; i++)
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

}

void RenderDeleteTailDLLStep(doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg)
{
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("temp = tail", font, 16, sf::Color::Black);
    a.addLine("tail = tail.prev", font, 16, sf::Color::Black);
    a.addLine("tail.next = null", font, 16, sf::Color::Black);
    a.addLine("delete temp", font, 16, sf::Color::Black);
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

    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    int currentStep = 0;

    while (currentStep < 3)
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

        if (currentStep == 0)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(0, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(0, sf::Color::Black);
            if (visualizer.size())
            {
                visualizer[0].shape.setFillColor(sf::Color::Red);
                visualizer.back().shape.setFillColor(sf::Color::Red);
                if (visualizer.size() - 2 >= 0) visualizer[visualizer.size() - 2].shape.setFillColor(ButtonBg);
            }
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {
                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == 1)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(2, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(2, sf::Color::Black);
            if (visualizer.size())
            {
                visualizer[0].shape.setFillColor(sf::Color::Red);
                visualizer.back().shape.setFillColor(ButtonBg);
                if (visualizer.size() - 2 >= 0) visualizer[visualizer.size() - 2].shape.setFillColor(sf::Color::Red);
            }
            for (int i = 0; i < visualizer.size(); i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size(); i++)
            {
                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        if (currentStep == 2)
        {
            window.clear(bg);;
            Previous->render(window);
            Next->render(window);
            Previous->update(window);
            Next->update(window);
            a.changeLineColor(3, sf::Color::Red);
            a.changeLineColor(4, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(3, sf::Color::Black);
            a.changeLineColor(4, sf::Color::Black);
            for (int i = 0; i < visualizer.size() - 1; i++)
                visualizer[i].render(window);
            for (int i = 1; i < visualizer.size() - 1; i++)
            {
                int arrowX = visualizer[i].posX;
                int arrowY = visualizer[i].posY + height / 2;
                int prevArrowX = visualizer[i - 1].posX + width;
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }

        window.display();
    }
    delete Previous, Next;

}

void RenderDeletePositionDLL(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg, float speed) {
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 400.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex del = pre.next, aft = del.next", font, 16, sf::Color::Black);
    a.addLine("pre.next = aft, aft.prev = pre", font, 16, sf::Color::Black);
    a.addLine("delete del", font, 16, sf::Color::Black);
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

void RenderDeletePositionDLLStep(int index, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 200.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("if empty, do nothing", font, 16, sf::Color::Black);
    a.addLine("Vertex pre = head", font, 16, sf::Color::Black);
    a.addLine("for (k = 0; k < i-1; k++)", font, 16, sf::Color::Black);
    a.addLine(" pre = pre.next", font, 16, sf::Color::Black);
    a.addLine("Vertex del = pre.next, aft = del.next", font, 16, sf::Color::Black);
    a.addLine("pre.next = aft, aft.prev = pre", font, 16, sf::Color::Black);
    a.addLine("delete del", font, 16, sf::Color::Black);
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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
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
                    draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
                }
            }
            a.changeLineColor(6, sf::Color::Red);
            a.draw(window);
            a.changeLineColor(6, sf::Color::Black);
        }

        window.display();
    }
    delete Previous, Next;
}

void RenderSearchDLL(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, float speed)
{
    sf::Time sleepTime = sf::seconds(0.5f)/speed;
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    // Add the desired lines to the PseudoCodeBlock
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("temp = head", font, 16, sf::Color::Black);
    a.addLine("while (temp != NULL)", font, 16, sf::Color::Black);
    a.addLine("  if temp.item == v, temp.highlight = true", font, 16, sf::Color::Black);
    a.addLine("  temp = temp.next", font, 16, sf::Color::Black);

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
    x = 400.f; // Starting position of the first node
    y = 400.f;

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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }
        }

        window.display();
        sf::sleep(sleepTime);
    }
    sf::sleep(sleepTime);
}

void RenderSearchDLLStep(int value, doublyLinkedList& list, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window, sf::Color& bg) {
    sf::Time sleepTime = sf::seconds(0.5f);
    vector<Button> visualizer;
    Node* cur = list.pHead;
    float x = 400.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock a(font, 0.f, 0.f, 400.f, 200.f, sf::Color::White);

    // Add the desired lines to the PseudoCodeBlock
    a.addLine("temp = head", font, 16, sf::Color::Black);
    a.addLine("while (temp != NULL)", font, 16, sf::Color::Black);
    a.addLine("  if temp.item == v, temp.highlight = true", font, 16, sf::Color::Black);
    a.addLine("  temp = temp.next", font, 16, sf::Color::Black);
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
                draw2headArrowHorizontal(prevArrowX, arrowX, arrowY, window);
            }

        }
   

        window.display();
    }
    delete Previous, Next;
}






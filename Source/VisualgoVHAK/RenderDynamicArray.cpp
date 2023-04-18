#include "RenderDynamicArray.h"
#include "PseudoCodeBlock.h"

void renderDynamicArray(std::vector<int>& a, sf::Color ButtonBg, sf::Font& font, sf::RenderWindow& window)
{
    std::vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    for (int i = 0; i < a.size(); i++)
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

void RenderSearchDynamicArray(int value, std::vector<int> &a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, float speed)
{
    std::vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    std::string buttonText;
    PseudoCodeBlock b(font, 0.f, 0.f, 500.f, 200.f, sf::Color::White);

    b.addLine("for (int i = 0 ; (a + i) != null ; i++)", font, 16, sf::Color::Red);
    b.addLine(" if (*(a+i) == value))", font, 16, sf::Color::Red);
    b.addLine("  (a+i)->highlight = true", font, 16, sf::Color::Red);

    for (int i = 0; i < a.size(); i++)
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
    sf::Time sleepTime = sf::seconds(0.5f) / speed;
    for (int i = 1; i < visualizer.size(); i++)
    {
        b.draw(window);
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
        }
        window.display();
        sf::sleep(sleepTime);
    }
    sf::sleep(sleepTime);
}

void RenderSearchDynamicArrayStep(int value, std::vector<int> &a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, sf::Color bg)
{
    std::vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock b(font, 0.f, 0.f, 500.f, 200.f, sf::Color::White);

    b.addLine("for (int i = 0 ; (a + i) != null ; i++)", font, 16, sf::Color::Red);
    b.addLine(" if (*(a+i) == value))", font, 16, sf::Color::Red);
    b.addLine("  (a+i)->highlight = true", font, 16, sf::Color::Red);
    std::string buttonText;
    for (int i = 0; i < a.size(); i++)
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
            b.draw(window);
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

        }

        Last->update(window);
        Last->render(window);
        window.display();
    }
    delete Previous, Next, Last;
}

void RenderUpdateDynamicArray(int value, int index, std::vector<int> &a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, float speed)
{
    std::vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;
    PseudoCodeBlock b(font, 0.f, 0.f, 500.f, 200.f, sf::Color::White);

    b.addLine("(a + i)->value = value", font, 16, sf::Color::Red);
    std::string buttonText;
    sf::Time sleepTime = sf::seconds(0.5f)/speed;

    for (int i = 0; i < a.size(); i++)
    {
        int values = a[i];
        buttonText = std::to_string(values);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
    }


    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);

    }
    b.draw(window);
    window.display();
    sf::sleep(sleepTime);

    visualizer[index].shape.setFillColor(sf::Color::Yellow);
    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);

    }
    b.draw(window);
    window.display();
    sf::sleep(sleepTime);

    for (int i = 0; i < visualizer.size(); i++)
    {
        visualizer[i].render(window);

    }
    b.draw(window);
    window.display();
    x = visualizer[index].posX;
    y = visualizer[index].posY;
    buttonText = std::to_string(value);
    Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
    tmp.shape.setFillColor(sf::Color::Yellow);
    tmp.text.setFillColor(sf::Color::Black);
    tmp.render(window);
    b.draw(window);
    window.display();
    sf::sleep(sleepTime);
}

void RenderUpdateDynamicArrayStep(int value, int index, std::vector<int> &a, sf::Color ButtonBg, sf::Font font, sf::RenderWindow& window, sf::Color bg)
{
    std::vector<Button> visualizer;
    float x = 500.f; // Starting position of the first node
    float y = 300.f;
    float nodeWidth = 50.f; // Adjust this as needed
    float nodeHeight = 50.f;

    int width = (int)nodeWidth;
    int height = (int)nodeHeight;

    PseudoCodeBlock b(font, 0.f, 0.f, 500.f, 200.f, sf::Color::White);

    b.addLine("(a + i)->value = value", font, 16, sf::Color::Red);

    std::string buttonText;
    sf::Time sleepTime = sf::seconds(0.3f);
    for (int i = 0; i < a.size(); i++)
    {
        int values = a[i];
        buttonText = std::to_string(values);
        Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
        visualizer.push_back(tmp);
        x += nodeWidth * 2; // Increment the position for the next node
    }
    Button* Previous = new Button(900, 700, 200, 50, font, "Previous",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Next = new Button(1200, 700, 200, 50, font, "Next",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* Last = new Button(1050, 500, 200, 50, font, "Last",
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
            else if (Last->isClicked(window))
            {
                currentStep = 3;
            }
        }
        if (currentStep == 0)
        {
            window.clear(bg);
            Next->render(window);
            Next->update(window);
            Previous->render(window);
            Previous->update(window);
            visualizer[index].shape.setFillColor(visualizer[index].idleColor);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);
                
            }
            b.draw(window);
        }

        if (currentStep == 1)
        {
            window.clear(bg);
            Next->render(window);
            Next->update(window);
            Previous->render(window);
            Previous->update(window);
            visualizer[index].shape.setFillColor(sf::Color::Yellow);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);

            }
            b.draw(window);
        }

        if (currentStep == 2)
        {
            window.clear(bg);
            Next->render(window);
            Next->update(window);
            Previous->render(window);
            Previous->update(window);
            for (int i = 0; i < visualizer.size(); i++)
            {
                visualizer[i].render(window);

            }
            x = visualizer[index].posX;
            y = visualizer[index].posY;
            buttonText = std::to_string(value);
            Button tmp(x, y, nodeWidth, nodeHeight, font, buttonText, ButtonBg, ButtonBg, ButtonBg, sf::Color::Black);
            tmp.shape.setFillColor(sf::Color::Yellow);
            tmp.text.setFillColor(sf::Color::Black);
            tmp.render(window);
            b.draw(window);
        }
        Last->update(window);
        Last->render(window);
        window.display();
    }
    delete Previous, Next, Last;
}


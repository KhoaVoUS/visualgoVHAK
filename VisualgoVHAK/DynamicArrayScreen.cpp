#include "DynamicArrayScreen.h"
#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "RenderDynamicArray.h"

void InputHandleDynamicArray(bool& finished, TextBox* TextBox1, Button* EnterButton, sf::RenderWindow& window, sf::Color bg, sf::Font& font, std::string tmp)
{
    sf::Text txt(tmp, font, 20);
    while (!finished)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                finished = true;
            }
            TextBox1->handleEvent(event);
            if (EnterButton->isClicked(window))
            {
                // handle what happens when Enter is clicked here
                finished = true;
            }
        }

        window.clear(bg);

        txt.setPosition(sf::Vector2f(TextBox1->box.getPosition().x - 100, TextBox1->box.getPosition().y - 40));
        txt.setFillColor(sf::Color::Black);
        window.draw(txt);
        TextBox1->draw(window);
        EnterButton->update(window);
        EnterButton->render(window);

        window.display();
    }
}
void InitDynamicArray(std::string str, std::vector<int> &a)
{
    // Create a stringstream object from the string
    std::stringstream ss(str);
    a.clear();
    int value;
    // Iterate through each number in the stringstream
    int i = 0;
    while (ss >> value)
    {
        a.push_back(value);
        i++;
    }
}
void InitProgressArrayDynamic(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, std::vector<int> &a)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleDynamicArray(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    InitDynamicArray(str, a);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void UpdateProgressDynamic(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, std::vector<int>& a, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleDynamicArray(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleDynamicArray(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);
    if (fast) RenderUpdateDynamicArray(value, index, a, ButtonBg, font, window, speed); else RenderUpdateDynamicArrayStep(value, index, a, ButtonBg, font, window, bg);
    a[index] = value;
    delete EnterButton;
    delete TextBox1;
}
void SearchProgressArrayDynamic(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, std::vector<int> &a, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleDynamicArray(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderSearchDynamicArray(value, a, ButtonBg, font, window, speed);
    else RenderSearchDynamicArrayStep(value, a, ButtonBg, font, window, bg);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void DynamicArrayScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& DA, sf::Color bg, bool& darkMode, std::vector<int> &a, bool& fast, float speed)
{
    window.clear(bg);
    sf::Color ButtonBg;
    sf::Color darkBlue(0, 0, 128);
    sf::Color lightGreen(144, 238, 144);

    if (darkMode) ButtonBg = lightGreen;
    else ButtonBg = darkBlue;

    // Back button
    Button* BackButton = new Button(20, 20, 200, 50, font, "Back",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    BackButton->update(window);
    BackButton->render(window);
    if (BackButton->isClicked(window))
    {
        Menu = true;
        DA = false;
    }
    //SpeedButton
    Button* SpeedButton = new Button(1200, 100, 200, 50, font, "Auto",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    if (fast) SpeedButton->text.setString("Auto"); else
        SpeedButton->text.setString("Manual");
    SpeedButton->update(window);
    SpeedButton->render(window);
    if (SpeedButton->isClicked(window)) fast = !fast;

    // Init button
    Button* InitButton = new Button(50, 100, 200, 50, font, "Init",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    InitButton->update(window);
    InitButton->render(window);
    if (InitButton->isClicked(window))
    {
        InitProgressArrayDynamic(window, font, bg, ButtonBg, a);
    }
    //random
    std::srand(std::time(nullptr));
    Button* InitRandomButton = new Button(280, 100, 200, 50, font, "Init Randomly",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    InitRandomButton->update(window);
    InitRandomButton->render(window);
    if (InitRandomButton->isClicked(window))
    {
        int array_size = std::rand() % 10 + 1;
        a.clear();
        for (int i = 0; i < array_size; i++)
        {
            int value = std::rand() % 10 + 1;
            a.push_back(value);
        }
    }
    Button* SearchButton = new Button(50, 660, 200, 50, font, "Search",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    SearchButton->update(window);
    SearchButton->render(window);
    if (SearchButton->isClicked(window))
    {
        SearchProgressArrayDynamic(window, font, bg, ButtonBg, a, fast, speed);
    }

    Button* UpdateButton = new Button(50, 300, 200, 50, font, "Update",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    UpdateButton->update(window);
    UpdateButton->render(window);
    if (UpdateButton->isClicked(window))
    {
        UpdateProgressDynamic(window, font, bg, ButtonBg, a, fast, speed);
    }

    Button* Reset = new Button(50, 740, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        a.clear();
    }
    renderDynamicArray(a, ButtonBg, font, window);
    window.display();

    delete BackButton, Reset, InitRandomButton, SearchButton, InitButton;
}

#include "StaticArrayScreen.h"
#include "TextBox.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "RenderStaticArray.h"

void InputHandleStaticArray(bool& finished, TextBox* TextBox1, Button* EnterButton, sf::RenderWindow& window, sf::Color bg, sf::Font& font, std::string tmp)
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
void InitStaticArray(std::string str, int* a, int array_size)
{
    // Create a stringstream object from the string
    std::stringstream ss(str);

    int value;
    // Iterate through each number in the stringstream
    int i = 0;
    while (ss >> value)
    {
        a[i] = value;
        i++;
    }
}
void InitProgressArray(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, int* a, int array_size)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleStaticArray(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    InitStaticArray(str, a, array_size);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void UpdateProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, int* a, int array_size, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleStaticArray(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleStaticArray(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderUpdateStaticArray(value, index, a, array_size, ButtonBg, font, window, speed);
    else RenderUpdateStaticArrayStep(value, index, a, array_size, ButtonBg, font, window, bg);

    a[index] = value;
    delete EnterButton;
    delete TextBox1;
}
void SearchProgressArray(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, int* a, int array_size, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleStaticArray(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderSearchStaticArray(value, a, array_size, ButtonBg, font, window, speed);
    else RenderSearchStaticArrayStep(value, a, array_size, ButtonBg, font, window, bg);

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void StaticArrayScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& SA, sf::Color bg, bool& darkMode, int* a, int array_size, bool& fast, float speed)
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
        SA = false;
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
        InitProgressArray(window, font, bg, ButtonBg, a, array_size);
    }

    Button* LoadButton = new Button(510, 100, 200, 50, font, "Load From File",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    LoadButton->update(window);
    LoadButton->render(window);
    if (LoadButton->isClicked(window))
    {
        std::ifstream inputFile("input.inp");

        // Check if the file is open
        if (inputFile.is_open())
        {
            std::string line;
            // Read the first line of the file
            std::getline(inputFile, line);

            // Do something with the line
            std::cout << "First line of the file: " << line << std::endl;

            InitStaticArray(line, a, array_size);
            // Close the file
            inputFile.close();
        }
        else
        {
            std::cout << "Unable to open file" << std::endl;
        }
    }
    //random
    std::srand(std::time(nullptr));
    Button* InitRandomButton = new Button(280, 100, 200, 50, font, "Init Randomly",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    InitRandomButton->update(window);
    InitRandomButton->render(window);
    if (InitRandomButton->isClicked(window))
    {
        for (int i = 0; i < array_size; i++)
        {
            int value = std::rand() % 10 + 1;
            a[i] = value;
        }

    }
    Button* SearchButton = new Button(50, 660, 200, 50, font, "Search",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    SearchButton->update(window);
    SearchButton->render(window);
    if (SearchButton->isClicked(window))
    {
        SearchProgressArray(window, font, bg, ButtonBg, a, array_size, fast, speed);
    }

    Button* UpdateButton = new Button(50, 300, 200, 50, font, "Update",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    UpdateButton->update(window);
    UpdateButton->render(window);
    if (UpdateButton->isClicked(window))
    {
        UpdateProgress(window, font, bg, ButtonBg, a, array_size, fast, speed);
    }

    Button* Reset = new Button(50, 740, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        for (int i = 0; i < array_size; i++) a[i] = 0;
    }

    renderStaticArray(a, array_size, ButtonBg, font, window);
    window.display();

    delete BackButton, Reset, InitRandomButton, SearchButton, LoadButton;
}


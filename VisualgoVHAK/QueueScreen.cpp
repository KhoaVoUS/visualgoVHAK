#include "SinglyLinkedListScreen.h"
#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "RenderQueue.h"

void InitQueueList(std::string str, doublyLinkedList& list)
{
    while (list.pHead != nullptr) list.deleteHead();
    // Create a stringstream object from the string
    std::stringstream ss(str);

    int value;
    // Iterate through each number in the stringstream
    while (ss >> value) {
        // Create a new node with the value
        Node* newNode = create(value);
        // Add the node to the linked list
        list.addTail(newNode);
    }
    list.loadList();
}

void InputHandleQueue(bool& finished, TextBox* TextBox1, Button* EnterButton, sf::RenderWindow& window, sf::Color bg, sf::Font& font, std::string tmp)
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
void InitProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleQueue(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    InitQueueList(str, list);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}



void AddHeadProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";

    InputHandleQueue(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderAddHeadQueue(value, list, ButtonBg, font, window);
    else RenderAddHeadQueueStep(value, list, ButtonBg, font, window, bg);
    // Add the value to the linked list
    list.addHead(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddTailProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleQueue(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderAddTailQueue(value, list, ButtonBg, font, window, speed);
    else RenderAddTailQueueStep(value, list, ButtonBg, font, window, bg);
    // Add the value to the linked list
    list.addTail(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddPositionProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleQueue(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleQueue(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (index == 0) {
        if (fast) RenderAddHeadQueue(value, list, ButtonBg, font, window);
        else RenderAddHeadQueueStep(value, list, ButtonBg, font, window, bg);
    }
    else {
        if (fast) RenderAddIndexQueue(index, value, list, ButtonBg, font, window, bg);
        else RenderAddIndexQueueStep(index, value, list, ButtonBg, font, window, bg);
    }
    list.insertIndexK(index, value);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void DeleteHeadProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    if (fast) RenderDeleteHeadQueue(list, ButtonBg, font, window, bg, speed);
    else RenderDeleteHeadQueueStep(list, ButtonBg, font, window, bg);
    list.deleteHead();
}

void DeleteTailProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast)
{
    if (fast) RenderDeleteTailQueue(list, ButtonBg, font, window, bg);
    else RenderDeleteTailQueueStep(list, ButtonBg, font, window, bg);
    list.deleteTail();
}



void SearchProgressQueue(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleQueue(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderSearchQueue(value, list, ButtonBg, font, window); else
        RenderSearchQueueStep(value, list, ButtonBg, font, window, bg);

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void QueueScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& Queue, sf::Color bg, bool& darkMode, doublyLinkedList& list, bool& fast, float speed)
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

    // Init button
    Button* InitButton = new Button(50, 100, 200, 50, font, "Init",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    InitButton->update(window);
    InitButton->render(window);
    if (InitButton->isClicked(window))
    {
        InitProgressQueue(window, font, bg, ButtonBg, list);
    }
    std::srand(std::time(nullptr));
    Button* InitRandomButton = new Button(280, 100, 200, 50, font, "Init Randomly",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    InitRandomButton->update(window);
    InitRandomButton->render(window);
    if (InitRandomButton->isClicked(window))
    {
        while (list.pHead != nullptr) list.deleteHead();
        int sz = std::rand() % 10 + 1;
        while (sz--)
        {
            int val = std::rand() % 1000;
            list.addTail(create(val));
        }
    }

    Button* SpeedButton = new Button(1200, 100, 200, 50, font, "Auto",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    if (fast) SpeedButton->text.setString("Auto"); else
        SpeedButton->text.setString("Manual");
    SpeedButton->update(window);
    SpeedButton->render(window);
    if (SpeedButton->isClicked(window)) fast = !fast;

    // Add Tail button
    Button* AddTailButton = new Button(50, 260, 200, 50, font, "Push",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddTailButton->update(window);
    AddTailButton->render(window);

    if (AddTailButton->isClicked(window))
    {
        AddTailProgressQueue(window, font, bg, ButtonBg, list, fast, speed);
    }


    // Delete Head button
    Button* DeleteHeadButton = new Button(50, 420, 200, 50, font, "Pop",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteHeadButton->update(window);
    DeleteHeadButton->render(window);

    if (DeleteHeadButton->isClicked(window))
    {
        DeleteHeadProgressQueue(window, font, bg, ButtonBg, list, fast, speed);
    }



    // Handle button clicks
    if (BackButton->isClicked(window))
    {
        Menu = true;
        Queue = false;
    }

    Button* Reset = new Button(50, 740, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        while (list.pHead != nullptr) list.deleteHead();
    }
    renderQueue(list, ButtonBg, font, window);
    window.display();

    delete InitButton, InitRandomButton, AddTailButton, DeleteHeadButton, BackButton, Reset;
}


#include "DoublyLinkedListScreen.h"
#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "RenderDLL.h"

void InitDoublyLinkedList(std::string str, doublyLinkedList& list)
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

void InputHandle(bool &finished, TextBox* TextBox1, Button* EnterButton, sf::RenderWindow& window, sf::Color bg, sf::Font& font, std::string tmp)
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
void InitProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandle(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    InitDoublyLinkedList(str, list);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}



void AddHeadProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";

    InputHandle(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);
    
    RenderAddHeadDLL(value, list, ButtonBg, font, window);
    // Add the value to the linked list
    list.addHead(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddTailProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandle(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    RenderAddTailDLL(value, list, ButtonBg, font, window);
    // Add the value to the linked list
    list.addTail(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddPositionProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandle(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandle(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);

    RenderAddIndexDLL(index, value, list, ButtonBg, font, window, bg);
    list.insertIndexK(index, value);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void DeleteHeadProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    RenderDeleteHeadDLL(list, ButtonBg, font, window, bg);
    list.deleteHead();
}

void DeleteTailProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    RenderDeleteTailDLL(list, ButtonBg, font, window, bg);
    list.deleteTail();
}

void DeletePositionProgress(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandle(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);

    RenderDeletePositionDLL(index, list, ButtonBg, font, window, bg);;
    list.deleteIndexK(index);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void DLLScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& DLL, sf::Color bg, bool& darkMode, doublyLinkedList& list)
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
        InitProgress(window, font, bg, ButtonBg, list);
    }


    // Add Head button
    Button* AddHeadButton = new Button(50, 180, 200, 50, font, "Add Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddHeadButton->update(window);
    AddHeadButton->render(window);
    if (AddHeadButton->isClicked(window))
    {
        AddHeadProgress(window, font, bg, ButtonBg, list);
    }

    // Add Tail button
    Button* AddTailButton = new Button(50, 260, 200, 50, font, "Add Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddTailButton->update(window);
    AddTailButton->render(window);

    if (AddTailButton->isClicked(window))
    {
        AddTailProgress(window, font, bg, ButtonBg, list);
    }

    // Add Position button
    Button* AddPositionButton = new Button(50, 340, 200, 50, font, "Add Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddPositionButton->update(window);
    AddPositionButton->render(window);

    if (AddPositionButton->isClicked(window))
    {
        AddPositionProgress(window, font, bg, ButtonBg, list);
    }

    // Delete Head button
    Button* DeleteHeadButton = new Button(50, 420, 200, 50, font, "Delete Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteHeadButton->update(window);
    DeleteHeadButton->render(window);

    if (DeleteHeadButton->isClicked(window))
    {
        DeleteHeadProgress(window, font, bg, ButtonBg, list);
    }

    // Delete Tail button
    Button* DeleteTailButton = new Button(50, 500, 200, 50, font, "Delete Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteTailButton->update(window);
    DeleteTailButton->render(window);

    if (DeleteTailButton->isClicked(window))
    {
        DeleteTailProgress(window, font, bg, ButtonBg, list);
    }

    // Delete Position button
    Button* DeletePositionButton = new Button(50, 580, 200, 50, font, "Delete Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeletePositionButton->update(window);
    DeletePositionButton->render(window);

    if (DeletePositionButton->isClicked(window))
    {
        DeletePositionProgress(window, font, bg, ButtonBg, list);;
    }
    // Search button
    Button* SearchButton = new Button(50, 660, 200, 50, font, "Search",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    SearchButton->update(window);
    SearchButton->render(window);

    // Handle button clicks
    if (BackButton->isClicked(window))
    {
        Menu = true;
        DLL = false;
    }

    Button* Reset = new Button(50, 740, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        while (list.pHead != nullptr) list.deleteHead();
    }
    renderDLL(list, ButtonBg, font, window);
    window.display();
}


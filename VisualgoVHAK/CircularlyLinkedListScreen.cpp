#include "CircularlyLinkedListScreen.h"

#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "RenderCLL.h"

void InitCircularLinkedList(std::string str, doublyLinkedList& list)
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

void InputHandleCLL(bool& finished, TextBox* TextBox1, Button* EnterButton, sf::RenderWindow& window, sf::Color bg, sf::Font& font, std::string tmp)
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
void InitProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    InitCircularLinkedList(str, list);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}



void AddHeadProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";

    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (list.getSize())
    {
        if (fast) RenderAddHeadCLL(value, list, ButtonBg, font, window, bg, speed);
        else RenderAddHeadCLLStep(value, list, ButtonBg, font, window, bg, speed);
    }
    // Add the value to the linked list
    list.addHead(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddTailProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);
    
    if (list.getSize())
    {

        if (fast) RenderAddTailCLL(value, list, ButtonBg, font, window, bg, speed);
        else RenderAddTailCLLStep(value, list, ButtonBg, font, window, bg);
    }
    // Add the value to the linked list
    list.addTail(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddPositionProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (index >= list.getSize()) return;
    if (index == 0) {
        if (fast) RenderAddHeadCLL(value, list, ButtonBg, font, window, bg, speed);
        else RenderAddHeadCLLStep(value, list, ButtonBg, font, window, bg, speed);
    }
    else {
        if (fast) RenderAddIndexCLL(index, value, list, ButtonBg, font, window, bg, speed);
        else RenderAddIndexCLLStep(index, value, list, ButtonBg, font, window, bg);
    }
    list.insertIndexK(index, value);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void UpdatePositionProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);
    if (index >= list.getSize()) return;
    if (fast) RenderUpdateIndexCLL(index, value, list, ButtonBg, font, window, bg, speed);
    else RenderUpdateIndexCLLStep(index, value, list, ButtonBg, font, window, bg);
    list.updateIndexK(index, value);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void DeleteHeadProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    if (!list.getSize()) return;
    if (fast) RenderDeleteHeadCLL(list, ButtonBg, font, window, bg, speed);
    else RenderDeleteHeadCLLStep(list, ButtonBg, font, window, bg);
    list.deleteHead();
}

void DeleteTailProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    if (!list.getSize()) return;
    if (fast) RenderDeleteTailCLL(list, ButtonBg, font, window, bg, speed);
    else RenderDeleteTailCLLStep(list, ButtonBg, font, window, bg);
    list.deleteTail();
}

void DeletePositionProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);

    if (index >= list.getSize()) return;
    if (index == 0) {
        if (fast) RenderDeleteHeadCLL(list, ButtonBg, font, window, bg, speed);
        else RenderDeleteHeadCLLStep(list, ButtonBg, font, window, bg);

    }
    else {
        if (fast) RenderDeletePositionCLL(index, list, ButtonBg, font, window, bg, speed); else
            RenderDeletePositionCLLStep(index, list, ButtonBg, font, window, bg);
    }
    list.deleteIndexK(index);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void SearchProgressCLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleCLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderSearchCLL(value, list, ButtonBg, font, window, speed); else
        RenderSearchCLLStep(value, list, ButtonBg, font, window, bg);

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void CLLScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& CLL, sf::Color bg, bool& darkMode, doublyLinkedList& list, bool& fast, float speed)
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
        InitProgressCLL(window, font, bg, ButtonBg, list);
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

    // Add Head button
    Button* AddHeadButton = new Button(50, 180, 200, 50, font, "Add Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddHeadButton->update(window);
    AddHeadButton->render(window);
    if (AddHeadButton->isClicked(window))
    {
        AddHeadProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Add Tail button
    Button* AddTailButton = new Button(50, 260, 200, 50, font, "Add Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddTailButton->update(window);
    AddTailButton->render(window);

    if (AddTailButton->isClicked(window))
    {
        AddTailProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Add Position button
    Button* AddPositionButton = new Button(50, 340, 200, 50, font, "Add Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddPositionButton->update(window);
    AddPositionButton->render(window);

    if (AddPositionButton->isClicked(window))
    {
        AddPositionProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    //Update Position button
    Button* UpdatePositionButton = new Button(50, 740, 200, 50, font, "Update Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    UpdatePositionButton->update(window);
    UpdatePositionButton->render(window);

    if (UpdatePositionButton->isClicked(window))
    {
        UpdatePositionProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }
    // Delete Head button
    Button* DeleteHeadButton = new Button(50, 420, 200, 50, font, "Delete Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteHeadButton->update(window);
    DeleteHeadButton->render(window);

    if (DeleteHeadButton->isClicked(window))
    {
        DeleteHeadProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Delete Tail button
    Button* DeleteTailButton = new Button(50, 500, 200, 50, font, "Delete Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteTailButton->update(window);
    DeleteTailButton->render(window);

    if (DeleteTailButton->isClicked(window))
    {
        DeleteTailProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Delete Position button
    Button* DeletePositionButton = new Button(50, 580, 200, 50, font, "Delete Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeletePositionButton->update(window);
    DeletePositionButton->render(window);

    if (DeletePositionButton->isClicked(window))
    {
        DeletePositionProgressCLL(window, font, bg, ButtonBg, list, fast, speed);;
    }
    // Search button
    Button* SearchButton = new Button(50, 660, 200, 50, font, "Search",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    SearchButton->update(window);
    SearchButton->render(window);
    if (SearchButton->isClicked(window))
    {
        SearchProgressCLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Handle button clicks
    if (BackButton->isClicked(window))
    {
        Menu = true;
        CLL = false;
    }

    Button* Reset = new Button(50, 820, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        while (list.pHead != nullptr) list.deleteHead();
    }
    renderCLL(list, ButtonBg, font, window);
    window.display();

    delete InitButton, InitRandomButton, AddHeadButton, AddTailButton, AddPositionButton, UpdatePositionButton, DeleteHeadButton, DeleteTailButton, DeletePositionButton, SearchButton, BackButton, Reset;
}


#include "SinglyLinkedListScreen.h"
#include "TextBox.h"
#include <iostream>
#include <sstream>
#include "RenderSLL.h"
#include <fstream>

void InitSinglyLinkedList(std::string str, doublyLinkedList& list)
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

void InputHandleSLL(bool& finished, TextBox* TextBox1, Button* EnterButton, sf::RenderWindow& window, sf::Color bg, sf::Font& font, std::string tmp)
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
void InitProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    InitSinglyLinkedList(str, list);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}



void AddHeadProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";

    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (list.getSize())
    {
        if (fast) RenderAddHeadSLL(value, list, ButtonBg, font, window, speed);
        else RenderAddHeadSLLStep(value, list, ButtonBg, font, window, bg);
    }
    // Add the value to the linked list
    list.addHead(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddTailProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (list.getSize())
    {
        if (fast) RenderAddTailSLL(value, list, ButtonBg, font, window, speed);
        else RenderAddTailSLLStep(value, list, ButtonBg, font, window, bg);
    }
    // Add the value to the linked list
    list.addTail(create(value));

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void AddPositionProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (index < 0 || index >= list.getSize()) return;
    if (index == 0) {
        if (fast) RenderAddHeadSLL(value, list, ButtonBg, font, window, speed);
        else RenderAddHeadSLLStep(value, list, ButtonBg, font, window, bg);
    }
    else {
        if (fast) RenderAddIndexSLL(index, value, list, ButtonBg, font, window, bg, speed);
        else RenderAddIndexSLLStep(index, value, list, ButtonBg, font, window, bg);
    }
    list.insertIndexK(index, value);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void UpdatePositionProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);
    TextBox1->text.setString("");
    finished = false;
    tmp = "Input value";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);

    str = TextBox1->text.getString();
    int value = std::stoi(str);
    if (index >= list.getSize()) return;
    if (fast) RenderUpdateIndexSLL(index, value, list, ButtonBg, font, window, bg, speed);
    else RenderUpdateIndexSLLStep(index, value, list, ButtonBg, font, window, bg);
    list.updateIndexK(index, value);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void DeleteHeadProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    if (!list.getSize()) return;
    if (fast) RenderDeleteHeadSLL(list, ButtonBg, font, window, bg, speed);
    else RenderDeleteHeadSLLStep(list, ButtonBg, font, window, bg);
    list.deleteHead();
}

void DeleteTailProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    if (!list.getSize()) return;
    if (fast) RenderDeleteTailSLL(list, ButtonBg, font, window, bg, speed);
    else RenderDeleteTailSLLStep(list, ButtonBg, font, window, bg);
    list.deleteTail();
}

void DeletePositionProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input index";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int index = std::stoi(str);

    if (index < 0 || index >= list.getSize()) return;
    if (index == 0) {
        if (fast) RenderDeleteHeadSLL(list, ButtonBg, font, window, bg, speed);
        else RenderDeleteHeadSLLStep(list, ButtonBg, font, window, bg);

    }
    else {
        if (fast) RenderDeletePositionSLL(index, list, ButtonBg, font, window, bg, speed); else
            RenderDeletePositionSLLStep(index, list, ButtonBg, font, window, bg);
    }
    list.deleteIndexK(index);
    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}

void SearchProgressSLL(sf::RenderWindow& window, sf::Font& font, sf::Color bg, sf::Color& ButtonBg, doublyLinkedList& list, bool fast, float speed)
{
    Button* EnterButton = new Button(900, 700, 200, 50, font, "Enter",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

    TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

    bool finished = false;
    std::string tmp = "Input value";
    InputHandleSLL(finished, TextBox1, EnterButton, window, bg, font, tmp);
    std::string str = TextBox1->text.getString();
    int value = std::stoi(str);

    if (fast) RenderSearchSLL(value, list, ButtonBg, font, window, speed); else
        RenderSearchSLLStep(value, list, ButtonBg, font, window, bg);

    //std::cout << str << "\n";
    delete EnterButton;
    delete TextBox1;
}
void SLLScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& SLL, sf::Color bg, bool& darkMode, doublyLinkedList& list, bool& fast, float speed)
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
        InitProgressSLL(window, font, bg, ButtonBg, list);
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

            InitSinglyLinkedList(line, list);
            // Close the file
            inputFile.close();
        }
        else
        {
            std::cout << "Unable to open file" << std::endl;
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
        AddHeadProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Add Tail button
    Button* AddTailButton = new Button(50, 260, 200, 50, font, "Add Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddTailButton->update(window);
    AddTailButton->render(window);

    if (AddTailButton->isClicked(window))
    {
        AddTailProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Add Position button
    Button* AddPositionButton = new Button(50, 340, 200, 50, font, "Add Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddPositionButton->update(window);
    AddPositionButton->render(window);

    if (AddPositionButton->isClicked(window))
    {
        AddPositionProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }
    //Update Position button
    Button* UpdatePositionButton = new Button(50, 740, 200, 50, font, "Update Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    UpdatePositionButton->update(window);
    UpdatePositionButton->render(window);

    if (UpdatePositionButton->isClicked(window))
    {
        UpdatePositionProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Delete Head button
    Button* DeleteHeadButton = new Button(50, 420, 200, 50, font, "Delete Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteHeadButton->update(window);
    DeleteHeadButton->render(window);

    if (DeleteHeadButton->isClicked(window))
    {
        DeleteHeadProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Delete Tail button
    Button* DeleteTailButton = new Button(50, 500, 200, 50, font, "Delete Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteTailButton->update(window);
    DeleteTailButton->render(window);

    if (DeleteTailButton->isClicked(window))
    {
        DeleteTailProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Delete Position button
    Button* DeletePositionButton = new Button(50, 580, 200, 50, font, "Delete Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeletePositionButton->update(window);
    DeletePositionButton->render(window);

    if (DeletePositionButton->isClicked(window))
    {
        DeletePositionProgressSLL(window, font, bg, ButtonBg, list, fast, speed);;
    }
    // Search button
    Button* SearchButton = new Button(50, 660, 200, 50, font, "Search",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    SearchButton->update(window);
    SearchButton->render(window);
    if (SearchButton->isClicked(window))
    {
        SearchProgressSLL(window, font, bg, ButtonBg, list, fast, speed);
    }

    // Handle button clicks
    if (BackButton->isClicked(window))
    {
        Menu = true;
        SLL = false;
    }

    Button* Reset = new Button(50, 820, 200, 50, font, "Reset",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    Reset->update(window);
    Reset->render(window);

    if (Reset->isClicked(window))
    {
        while (list.pHead != nullptr) list.deleteHead();
    }
    renderSLL(list, ButtonBg, font, window);
    window.display();

    delete InitButton, InitRandomButton, LoadButton, AddHeadButton, AddTailButton, AddPositionButton, DeleteHeadButton, DeleteTailButton, DeletePositionButton, SearchButton, BackButton, Reset, UpdatePositionButton;
}


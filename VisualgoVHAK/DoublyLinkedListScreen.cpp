#include "DoublyLinkedListScreen.h"
#include "TextBox.h"
#include <iostream>
void DLLScreen(sf::RenderWindow& window, sf::Font& font, bool& Menu, bool& DLL, sf::Color bg, bool& darkMode, doublyLinkedList& dLinkedList)
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
        Button* EnterButton = new Button(900, 500, 200, 50, font, "Enter",
            ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

        sf::Vector2f textBoxPos(EnterButton->shape.getPosition().x - 250, EnterButton->shape.getPosition().y);

        TextBox* TextBox1 = new TextBox(sf::Vector2f(200.f, 50.f), textBoxPos, font);

        bool finished = false;

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

            TextBox1->draw(window);
            EnterButton->update(window);
            EnterButton->render(window);

            window.display();
        }
        delete EnterButton;
        delete TextBox1;
    }


    // Add Head button
    Button* AddHeadButton = new Button(50, 180, 200, 50, font, "Add Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddHeadButton->update(window);
    AddHeadButton->render(window);

    // Add Tail button
    Button* AddTailButton = new Button(50, 260, 200, 50, font, "Add Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddTailButton->update(window);
    AddTailButton->render(window);

    // Add Position button
    Button* AddPositionButton = new Button(50, 340, 200, 50, font, "Add Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    AddPositionButton->update(window);
    AddPositionButton->render(window);

    // Delete Head button
    Button* DeleteHeadButton = new Button(50, 420, 200, 50, font, "Delete Head",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteHeadButton->update(window);
    DeleteHeadButton->render(window);

    // Delete Tail button
    Button* DeleteTailButton = new Button(50, 500, 200, 50, font, "Delete Tail",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeleteTailButton->update(window);
    DeleteTailButton->render(window);

    // Delete Position button
    Button* DeletePositionButton = new Button(50, 580, 200, 50, font, "Delete Position",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);
    DeletePositionButton->update(window);
    DeletePositionButton->render(window);

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

    window.display();
}

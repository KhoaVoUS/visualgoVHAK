#include "WelcomeScreen.h"

void WelcomeScreen(sf::RenderWindow& window, sf::Font& font, bool& Welcome, bool& Menu, bool& fast, sf::Color bg, bool& darkMode)
{
    window.clear(bg);
    sf::Color ButtonBg(173, 216, 230);

    Button* StartButton = new Button(600, 300, 200, 50, font, "Start",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* DarkMode = new Button(1300, 100, 200, 50, font, "Dark mode : On",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


    if (darkMode) DarkMode->text.setString("Dark mode : On"); else 
        DarkMode->text.setString("Dark mode : Off");


    DarkMode->update(window);
    StartButton->update(window);

    if (DarkMode->isClicked(window)) darkMode = !darkMode;


    if (StartButton->isClicked(window))
    {
        Welcome = 0;
        Menu = 1;
    }

    DarkMode->render(window);
    StartButton->render(window);
    
    window.display();
    delete StartButton, DarkMode;
}

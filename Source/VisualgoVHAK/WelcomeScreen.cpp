#include "WelcomeScreen.h"

void WelcomeScreen(sf::RenderWindow& window, sf::Font& font, bool& Welcome, bool& Menu, bool& fast, sf::Color bg, bool& darkMode, float& speed)
{
    window.clear(bg);
    sf::Color ButtonBg(173, 216, 230);

    Button* StartButton = new Button(600, 300, 200, 50, font, "Start",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* DarkMode = new Button(1300, 100, 200, 50, font, "Dark mode : On",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);

    Button* SpeedButton = new Button(1300, 300, 200, 50, font, "Speed : 1x",
        ButtonBg, sf::Color::Red, sf::Color::Blue, sf::Color::Black);


    if (darkMode) DarkMode->text.setString("Dark mode : On"); else 
        DarkMode->text.setString("Dark mode : Off");

    if ((int)speed == 1) SpeedButton->text.setString("Speed : 1x"); else
        SpeedButton->text.setString("Speed : 2x");


    DarkMode->update(window);
    StartButton->update(window);
    SpeedButton->update(window);

    if (DarkMode->isClicked(window)) darkMode = !darkMode;

    if (SpeedButton->isClicked(window))
    {
        if ((int)speed == 1) speed = 2.0;
        else speed = 1.0;
    }

    if (StartButton->isClicked(window))
    {
        Welcome = 0;
        Menu = 1;
    }

    DarkMode->render(window);
    StartButton->render(window);
    SpeedButton->render(window);
    
    window.display();
    delete StartButton;
    delete DarkMode;
    delete SpeedButton;
}

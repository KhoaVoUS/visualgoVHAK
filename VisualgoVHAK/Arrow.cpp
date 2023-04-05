#include "Arrow.h"

void draw2headArrowHorizontal(int x, int x1, int y, sf::RenderWindow& window) {
    // Create arrow body
    int length = abs(x1 - x);
    sf::RectangleShape body(sf::Vector2f(length - 10, 4));
    body.setPosition(x, y);
    body.setFillColor(sf::Color::White);

    // Create arrow head 1
    sf::ConvexShape head1(3);
    head1.setPoint(0, sf::Vector2f(0, 0));
    head1.setPoint(1, sf::Vector2f(10, -10));
    head1.setPoint(2, sf::Vector2f(10, 10));
    head1.setFillColor(sf::Color::White);
    head1.setPosition(x, y);

    // Create arrow head 2
    sf::ConvexShape head2(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(-10, -10));
    head2.setPoint(2, sf::Vector2f(-10, 10));
    head2.setFillColor(sf::Color::White);
    head2.setPosition(x1, y);

    // Draw arrow body and heads
    window.draw(body);
    window.draw(head1);
    window.draw(head2);
}

void draw1headArrowHorizontal(int x, int x1, int y, sf::RenderWindow& window) {
    // Create arrow body
    int length = abs(x1 - x);
    sf::RectangleShape body(sf::Vector2f(length - 10, 4));
    body.setPosition(x, y);
    body.setFillColor(sf::Color::White);

    // Create arrow head 1
    sf::ConvexShape head1(3);
    head1.setPoint(0, sf::Vector2f(0, 0));
    head1.setPoint(1, sf::Vector2f(10, -10));
    head1.setPoint(2, sf::Vector2f(10, 10));
    head1.setFillColor(sf::Color::White);
    head1.setPosition(x, y);

    // Create arrow head 2
    sf::ConvexShape head2(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(-10, -10));
    head2.setPoint(2, sf::Vector2f(-10, 10));
    head2.setFillColor(sf::Color::White);
    head2.setPosition(x1, y);

    // Draw arrow body and heads
    window.draw(body);
    window.draw(head2);
}
void drawArrowHorizontal(int x, int x1, int y, sf::RenderWindow& window) {
    // Create arrow body
    int length = abs(x1 - x);
    sf::RectangleShape body(sf::Vector2f(length - 10, 4));
    body.setPosition(x, y);
    body.setFillColor(sf::Color::White);

    // Create arrow head 1
    sf::ConvexShape head1(3);
    head1.setPoint(0, sf::Vector2f(0, 0));
    head1.setPoint(1, sf::Vector2f(10, -10));
    head1.setPoint(2, sf::Vector2f(10, 10));
    head1.setFillColor(sf::Color::White);
    head1.setPosition(x, y);

    // Create arrow head 2
    sf::ConvexShape head2(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(-10, -10));
    head2.setPoint(2, sf::Vector2f(-10, 10));
    head2.setFillColor(sf::Color::White);
    head2.setPosition(x1, y);

    // Draw arrow body and heads
    window.draw(body);
}

void draw2headArrowVertical(int x, int y, int y1, sf::RenderWindow& window) {
    // Create arrow body
    int length = abs(y1 - y);
    sf::RectangleShape body(sf::Vector2f(4, length));
    body.setPosition(x, std::min(y, y1));
    body.setFillColor(sf::Color::White);

    // Create arrow head 1
    sf::ConvexShape head1(3);
    head1.setPoint(0, sf::Vector2f(0, 0));
    head1.setPoint(1, sf::Vector2f(10, 10));
    head1.setPoint(2, sf::Vector2f(10, -10));
    head1.setFillColor(sf::Color::White);
    head1.setPosition(x , y );
    head1.setRotation(-90);

    // Create arrow head 2
    sf::ConvexShape head2(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(-10, 10));
    head2.setPoint(2, sf::Vector2f(-10, -10));
    head2.setFillColor(sf::Color::White);
    head2.setPosition(x, y1 );
    head2.setRotation(-90);

    // Draw arrow body and heads
    window.draw(body);
    window.draw(head1);
    window.draw(head2);
}

void draw1headArrowVertical(int x, int y, int y1, sf::RenderWindow& window) {
    // Create arrow body
    int length = abs(y1 - y);
    sf::RectangleShape body(sf::Vector2f(4, length));
    body.setPosition(x, std::min(y, y1));
    body.setFillColor(sf::Color::White);

    // Create arrow head 1
    sf::ConvexShape head1(3);
    head1.setPoint(0, sf::Vector2f(0, 0));
    head1.setPoint(1, sf::Vector2f(10, 10));
    head1.setPoint(2, sf::Vector2f(10, -10));
    head1.setFillColor(sf::Color::White);
    head1.setPosition(x, y);
    head1.setRotation(-90);

    // Create arrow head 2
    sf::ConvexShape head2(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(-10, 10));
    head2.setPoint(2, sf::Vector2f(-10, -10));
    head2.setFillColor(sf::Color::White);
    head2.setPosition(x, y1);
    head2.setRotation(-90);

    // Draw arrow body and heads
    window.draw(body);
    window.draw(head2);
}

void drawArrowVertical(int x, int y, int y1, sf::RenderWindow& window) {
    // Create arrow body
    int length = abs(y1 - y);
    sf::RectangleShape body(sf::Vector2f(4, length));
    body.setPosition(x, std::min(y, y1));
    body.setFillColor(sf::Color::White);

    // Create arrow head 1
    sf::ConvexShape head1(3);
    head1.setPoint(0, sf::Vector2f(0, 0));
    head1.setPoint(1, sf::Vector2f(10, 10));
    head1.setPoint(2, sf::Vector2f(10, -10));
    head1.setFillColor(sf::Color::White);
    head1.setPosition(x, y);
    head1.setRotation(-90);

    // Create arrow head 2
    sf::ConvexShape head2(3);
    head2.setPoint(0, sf::Vector2f(0, 0));
    head2.setPoint(1, sf::Vector2f(-10, 10));
    head2.setPoint(2, sf::Vector2f(-10, -10));
    head2.setFillColor(sf::Color::White);
    head2.setPosition(x, y1);
    head2.setRotation(-90);

    // Draw arrow body and heads
    window.draw(body);
}



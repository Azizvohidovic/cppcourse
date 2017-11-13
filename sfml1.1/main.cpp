#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    window.clear();

    sf::RectangleShape shape0;
    shape0.setSize({90, 270});
    shape0.setRotation(0);
    shape0.setPosition({195, 115});
    shape0.setFillColor(sf::Color(0x20, 0x20, 0X20));
    window.draw(shape0);

    sf::CircleShape shape1(40);
    shape1.setPosition({200, 120});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    sf::CircleShape shape2(40);
    shape2.setPosition({200, 300});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(40);
    shape3.setPosition({200, 210});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    window.display();

    sf::sleep(sf::seconds(10));
}
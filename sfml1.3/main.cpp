#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1024, 768}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape2;
    shape2.setSize({500, 300});
    shape2.setRotation(0);
    shape2.setPosition({90, 300});
    shape2.setFillColor(sf::Color(153, 77, 0));
    window.draw(shape2);

    sf::RectangleShape shape1;
    shape1.setSize({90, 190});
    shape1.setRotation(0);
    shape1.setPosition({140, 410});
    shape1.setFillColor(sf::Color(0x10, 0x10, 0X10));
    window.draw(shape1);

    sf::ConvexShape trapeze;
    trapeze.setPointCount(4);
    trapeze.setPosition({335, 240});
    trapeze.setFillColor(sf::Color(77, 0, 0));
    trapeze.setPoint(0, {-120, -80});
    trapeze.setPoint(1, {+120, -80});
    trapeze.setPoint(2, {+300, 60});
    trapeze.setPoint(3, {-300, 60});

    window.draw(trapeze);

    sf::RectangleShape shape0;
    shape0.setSize({40, 60});
    shape0.setRotation(0);
    shape0.setPosition({405, 150});
    shape0.setFillColor(sf::Color(0x20, 0x20, 0X20));
    window.draw(shape0);
    
    sf::RectangleShape shape3;
    shape3.setSize({60, 40});
    shape3.setRotation(0);
    shape3.setPosition({395, 110});
    shape3.setFillColor(sf::Color(0x20, 0x20, 0X20));
    window.draw(shape3);

    sf::CircleShape shape4(20);
    shape4.setPosition({420, 75});
    shape4.setFillColor(sf::Color(0xD0D0D0,0xD0D0D0,0xD0D0D0));
    window.draw(shape4);

    sf::CircleShape shape5(25);
    shape5.setPosition({430, 40});
    shape5.setFillColor(sf::Color(0xD0D0D0, 0xD0D0D0, 0xD0D0D0));
    window.draw(shape5);

    sf::CircleShape shape6(25);
    shape6.setPosition({440, 10});
    shape6.setFillColor(sf::Color(0xD0D0D0, 0xD0D0D0, 0xD0D0D0));
    window.draw(shape6);

    sf::CircleShape shape7(30);
    shape7.setPosition({445, -15});
    shape7.setFillColor(sf::Color(0xD0D0D0, 0xD0D0D0, 0xD0D0D0));
    window.draw(shape7);

    window.display();

    sf::sleep(sf::seconds(5));
}
#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    window.clear();

    sf::RectangleShape shape0;
    shape0.setSize({20, 280});
    shape0.setRotation(0);
    shape0.setPosition({40, 115});
    shape0.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape0);

    sf::RectangleShape shape1;
    shape1.setSize({110, 120});
    shape1.setRotation(0);
    shape1.setPosition({60, 120});
    shape1.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape1);

    sf::RectangleShape shape3;
    shape3.setSize({20, 180});
    shape3.setRotation(-25);
    shape3.setPosition({70, 230});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape3);

    sf::RectangleShape shape2;
    shape2.setSize({90, 100});
    shape2.setRotation(0);
    shape2.setPosition({70, 130});
    shape2.setFillColor(sf::Color(0x0, 0x0, 0X0));
    window.draw(shape2);

    sf::RectangleShape shape4;
    shape4.setSize({20, 280});
    shape4.setRotation(13);
    shape4.setPosition({240, 120});
    shape4.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({20, 280});
    shape5.setRotation(-13);
    shape5.setPosition({240, 120});
    shape5.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({80, 20});
    shape6.setRotation(0);
    shape6.setPosition({210, 280});
    shape6.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape6);

    sf::RectangleShape shape8;
    shape8.setSize({20, 280});
    shape8.setRotation(13);
    shape8.setPosition({425, 120});
    shape8.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape8);

    sf::RectangleShape shape7;
    shape7.setSize({20, 280});
    shape7.setRotation(-13);
    shape7.setPosition({300, 120});
    shape7.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    window.draw(shape7);

    window.display();

    sf::sleep(sf::seconds(10));
}
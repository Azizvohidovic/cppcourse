#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "1.1");
    
    sf::ConvexShape shape;
    shape.setPosition(400, 300);
    shape.setPointCount(7);
    shape.setPoint(0, {-40, 0});
    shape.setPoint(1, {0, 40});
    shape.setPoint(2, {40, 0});
    shape.setPoint(3, {20, 0});
    shape.setPoint(4, {20, -40});
    shape.setPoint(5, {-20, -40});
    shape.setPoint(6, {-20, 0});
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    shape.setOutlineColor(sf::Color(0x0, 0x0, 0x0));
    shape.setOutlineThickness(2);
    
    while (window.isOpen())
     {
         sf::Event event;
         while (window.pollEvent(event))
         {
             if (event.type == sf::Event::Closed)
             {
                 window.close();
             }
         }
         window.clear(sf::Color(255, 255, 255));
         window.draw(shape);
         window.display();
     }
    
}
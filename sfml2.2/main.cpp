#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    const sf::Vector2f ellipseRadius = {200.f, 160.f};
    constexpr int pointCount = 600;
    float amplitude = 100.f;
    constexpr float period = 2.f;
    const sf::Vector2f position{400, 300};

    float time = 0;
    // Создаём окно с параметрами сглаживания
    sf::ContextSettings settings;
    settings.antialiasingLevel = 5000;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "rose",
        sf::Style::Default, settings);

    //объявляем фигуру, которая будет выглядет как РОЗА
    sf::Clock clock;
    sf::ConvexShape rose;
    rose.setPosition({360, 280});
    rose.setFillColor(sf::Color(255, 210, 0));

    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float radius = 200 * std::sin(6 * angle);
        sf::Vector2f point = sf::Vector2f{
            radius * std::sin(angle),
            radius * std::cos(angle)};
        rose.setPoint(pointNo, point);
    };
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
        const float deltaTime = clock.restart().asSeconds();

        time += deltaTime;

        const float wavePhase = time * float(2 * M_PI);
        const float y = amplitude * std::sin(wavePhase / period);
        const float x = amplitude * std::cos(wavePhase / period);
        const sf::Vector2f offset = {x, y};

        rose.setPosition(position + offset);

        window.clear(sf::Color::White);
        window.draw(rose);
        window.display();
    }
}
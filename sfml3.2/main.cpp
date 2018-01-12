#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Eye
{
    sf::ConvexShape pupil;
    sf::ConvexShape sclera;
    sf::Vector2f position;
    float rotation = 0;
};

// Переводит полярные координаты в декартовы
sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * std::cos(angle),
        radiusY * std::sin(angle)};
}

// Переводит радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обновляет состояние глаза
void updateEye(Eye &eye)
{
    const sf::Vector2f PupilOffset = toEuclidean(20, 40, eye.rotation);
    eye.pupil.setPosition(eye.position + PupilOffset);

    eye.sclera.setPosition(eye.position);
}

// Инициализирует зрачок
void initPupil(Eye &eye)
{
    eye.pupil.setFillColor(sf::Color(0, 0, 0));

    constexpr int pointCount = 200;
    sf::Vector2f ellipseRadius = {12.f, 20.f};
    eye.pupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::cos(angle),
            ellipseRadius.y * std::sin(angle)};
        eye.pupil.setPoint(pointNo, point);
    }
}

// Инициализирует глаз
void initEye(Eye &eye, const float x, const float y)
{
    eye.position = {x, y};

    eye.sclera.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    constexpr int pointCount = 200;
    sf::Vector2f ellipseRadius = {50.f, 100.f};
    eye.sclera.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::cos(angle),
            ellipseRadius.y * std::sin(angle)};
        eye.sclera.setPoint(pointNo, point);
    }

    initPupil(eye);
    updateEye(eye);
}

// Обрабатывает событие MouseMove, обновляя позицию мыши
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

// Опрашивает и обрабатывает доступные события в цикле.
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

// Обновляет зрачки, указывающие на мышь
void update(const sf::Vector2f &mousePosition, Eye &firstEye, Eye &secondEye)
{
    sf::Vector2f delta = mousePosition - firstEye.position;
    firstEye.rotation = atan2(delta.y, delta.x);
    updateEye(firstEye);

    delta = mousePosition - secondEye.position;
    secondEye.rotation = atan2(delta.y, delta.x);
    updateEye(secondEye);
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, Eye &firstEye, Eye &secondEye)
{
    window.clear();
    window.draw(firstEye.sclera);
    window.draw(firstEye.pupil);
    window.draw(secondEye.sclera);
    window.draw(secondEye.pupil);
    window.display();
}

// Программа рисует в окне глаза, у которых зрачки поворачиваются
// вслед за курсором мыши.
int main()
{
    constexpr unsigned W = 800;
    constexpr unsigned H = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;
    sf::RenderWindow window(
        sf::VideoMode({W, H}),
        "moving eyes", sf::Style::Default, settings);

    Eye firstEye;
    Eye secondEye;

    sf::Vector2f mousePosition;

    initEye(firstEye, 325, 300);
    initEye(secondEye, 445, 300);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, firstEye, secondEye);
        redrawFrame(window, firstEye, secondEye);
    }
}
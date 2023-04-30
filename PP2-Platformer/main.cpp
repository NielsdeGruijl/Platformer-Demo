#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    Scene* currentScene;
    Scene scene1("Scene1");

    currentScene = &scene1;

    Player player("player", "Fighter.png", 300);
    player.SetPos(sf::Vector2f(100, 300));
    scene1.AddGameObject(player);

    Sprite sprite("Square", "Square.png");
    sprite.SetPos(sf::Vector2f(500, 300));
    scene1.AddGameObject(sprite);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.setFramerateLimit(144);
        currentScene->Update();
        currentScene->Render(&window);
        window.display();
    }

    return 0;
}
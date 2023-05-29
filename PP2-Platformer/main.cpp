#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    Scene* currentScene;
    Scene scene1("Scene1");

    currentScene = &scene1;

    
    Sprite platform("PlatformLeft", "Square.png");
    platform.SetPosition(Vector2(150, 500));
    platform.SetSize(Vector2(3, 0.25f));
    scene1.AddGameObject(platform);

    Sprite platform1("PlatformRight", "Square.png");
    platform1.SetPosition(Vector2(1130, 500));
    platform1.SetSize(Vector2(3, 0.25f));
    scene1.AddGameObject(platform1);

    Sprite platform2("PlatformMiddle", "Square.png");
    platform2.SetPosition(Vector2(640, 320));
    platform2.SetSize(Vector2(5, 0.25f));
    scene1.AddGameObject(platform2);

    Enemy enemy("Enemy", "Enemy.png", 390, 890);
    enemy.SetPosition(Vector2(640, 280));
    scene1.AddGameObject(enemy);

    Sprite floor("Floor", "Square.png");
    floor.SetPosition(Vector2(640, 670));
    floor.SetSize(Vector2(12.8f, 1));
    floor.SetColor(sf::Color::Green);
    scene1.AddGameObject(floor);

    Player player("Player", "Square.png");
    player.SetMovementValues(300, 1000);
    player.SetPosition(Vector2(150, 360));
    player.SetColor(sf::Color::Blue);
    scene1.AddGameObject(player);

    //std::cout << player.sprite.getGlobalBounds().width << player.sprite.getGlobalBounds().height << '\n';

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //window.setFramerateLimit(144);
        currentScene->Update();
        currentScene->Render(&window);
        window.display();
    }

    return 0;
}
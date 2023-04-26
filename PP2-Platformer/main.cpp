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

    //Sprite sprite1("Sprite1", "Tofu.png");
    //sprite1.SetValues(sf::Vector2f(0, 0), sf::Vector2f(1, 1));
    //scene1.AddGameObject(sprite1);

    Player player("player", "Fighter.png", 300, true);
    player.SetValues(sf::Vector2f(640, 360));
    scene1.AddGameObject(player);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.setFramerateLimit(60);
        currentScene->Update();
        currentScene->Render(&window);
        window.display();
    }

    return 0;
}
# Platformer Demo

NOTE: This project is still in development!

INTRODUCTION

This project is a platformer demo showing off a rudimentary framework I wrote in C++ using SFML 2.5.1 to render the sprites.

The framework contains the following classes:
Scene  
GameObject  
Sprite  
Pawn  
Vector2  
AABBCollision  
Observable  

The way it is set up is as follows: the Scene class is a level that contains a list of all GameObjects added to it. A GameObject is the base class for any object created, the Sprite class inherrits from GameObject and the Pawn class inherrits from the Sprite class. The Sprite class is intended to be used for simple static objects, the Pawn class is intended to be inherrited by dynamic objects such as the player and enemy classes. The AABBCollision class loops through the list of GameObjects in the Scene and checks and handles collisions between them, more speicifc ways to handle collisions can be done with the Observable class. The Observable class is an event system akin to UnityEvents, create an observable in the script of the class you want to invoke the event and have other objects that should subscribe to it obtain a reference to it, most easily done using the extern keyword. Make sure to subscribe and unsubscribe the function you want to be called when the event gets invoked in the constructor and destructor respectively. In the subscribed function you can add specific ways to handle collisions for a specific object or class.

To take a look at the demo simply download the project and run the executable.

CONTROLS  
A - move left  
D - move right  
Spacebar - Jump  


#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class resourceManager;

enum class backgroundState
{
    SHOW_MISSION_BACKGROUND,
    SHOW_CREATE_CHARACTER_BACKGROUND
};

enum class audioState
{
    PLAY_MENU_MUSIC,
    PLAY_MISSION_MUSIC,
    PLAY_CHARACTER_CREATION_MUSIC
};

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    backgroundState backgroundState; // estados del background
    audioState musicState;           // estados del audio
    
    resourceManager *manager;
    //FALTA AUDIOMANAGER

    sf::RenderWindow window;
    void Render();
    void audioUpdater();
    void handleEvents();
};
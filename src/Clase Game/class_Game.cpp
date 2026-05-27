#include "class_Game.h"
#include "../Clase resourceManager/class_resourceManager.h"
#include "../Clase Logger/class_Logger.h"

Game::Game() : backgroundState(backgroundState::SHOW_MISSION_BACKGROUND), window(sf::VideoMode({800, 600}), "Metroid"), manager(nullptr)
{
    Logger::Init();
    manager = &resourceManager::getInstance();
}

Game::~Game()
{
    Logger::logFileClose();
    manager = nullptr;
}

void Game::handleEvents()
{

    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        // Cuando se toca el botón de cerrado
        if (event->is<sf::Event::Closed>())
        {
            // Cerrar Ventana
            window.close();
        }

        if (const sf::Event::KeyPressed *KeyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            // TRUE --> asifna dirección mem. de donde se guardo toda la info del teclazo al puntero Keypressed
            // FALSE --> asigna al puntero KeyPressed nullptr porque no fue de tipo Event::Keypressed (false)
            // Si el resultado del if == false, salta el bloque, de lo contrarario, lo ejecuta.
            if (KeyPressed->code == sf::Keyboard::Key::M) // because of "Misión" menu option
            {
                backgroundState = backgroundState::SHOW_MISSION_BACKGROUND;
            }

            if (KeyPressed->code == sf::Keyboard::Key::C) // because of "Crear Personaje" menu option
            {
                backgroundState = backgroundState::SHOW_CREATE_CHARACTER_BACKGROUND;
            }
        }
    }
}

void Game::Render()
{
    manager->addResource("../../ASSETS/menuSprites/Mission.png");
    manager->addResource("../../ASSETS/menuSprites/characterCreation.png");
    window.clear();

    switch (backgroundState)
    {
    case backgroundState::SHOW_MISSION_BACKGROUND:
    {
        window.draw(manager->getSprite("../../ASSETS/menuSprites/Mission.png"));
        break;
    }

    case backgroundState::SHOW_CREATE_CHARACTER_BACKGROUND:
    {
        window.draw(manager->getSprite("../../ASSETS/menuSprites/characterCreation.png"));
        break;
    }
    }
    window.display();
}

void Game::audioUpdater()
{
}

void Game::run()
{
    handleEvents(); // Game::handleEvents, cambia estado de Game::backgroundState -> tipo de dato backgroundState
}

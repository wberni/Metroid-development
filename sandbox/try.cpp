#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <optional>
#include <iostream>

enum class BackgroundState
{
    SHOW_MISSION_BACKGROUND,
    SHOW_CREATE_CHARACTER_BACKGROUND
};

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Metroid");

    // background actual 
    BackgroundState currentBackground = BackgroundState::SHOW_MISSION_BACKGROUND;

    
    sf::Music audio;
    if(!audio.openFromFile("ASSETS/Music/Crimewave.mp3")) {
        std::cerr << "NO SE PUDO ABRIR EL ARCHIVO\n";
    } else {
        audio.play();
    }

    // Textura y sprite de Misión
    sf::Texture textureMenu_mission;
    if(!textureMenu_mission.loadFromFile("ASSETS/menuSprites/missionBackground.png")) {
        std::cerr << "Error al cargar missionBackground.png\n";
    }
    sf::Sprite spriteMenu_mission(textureMenu_mission);

   
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize_mission = textureMenu_mission.getSize();
    spriteMenu_mission.setScale(
        static_cast<float>(windowSize.x) / textureSize_mission.x,
        static_cast<float>(windowSize.y) / textureSize_mission.y
    );

    
    sf::Texture textureMenu_character;
    if(!textureMenu_character.loadFromFile("ASSETS/menuSprites/characterCreation.png")) {
        std::cerr << "Error al cargar characterCreation.png\n";
    }
    sf::Sprite spriteMenu_character(textureMenu_character);

    sf::Vector2u textureSize_character = textureMenu_character.getSize();
    spriteMenu_character.setScale(
        static_cast<float>(windowSize.x) / textureSize_character.x,
        static_cast<float>(windowSize.y) / textureSize_character.y
    );

    // Loop principal
    while(window.isOpen()) {
        // Eventos
        while(const std::optional<sf::Event> event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }

            if(const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if(keyPressed->code == sf::Keyboard::M) {
                    currentBackground = BackgroundState::SHOW_MISSION_BACKGROUND;
                }
                if(keyPressed->code == sf::Keyboard::C) {
                    currentBackground = BackgroundState::SHOW_CREATE_CHARACTER_BACKGROUND;
                }
            }
        }

       
        window.clear();
        switch (currentBackground) {
            case BackgroundState::SHOW_MISSION_BACKGROUND:
                window.draw(spriteMenu_mission);
                break;
            case BackgroundState::SHOW_CREATE_CHARACTER_BACKGROUND:
                window.draw(spriteMenu_character);
                break;
        }
        window.display();
    }

    return 0;
}
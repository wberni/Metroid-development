#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <optional>
#include <iostream>

enum class backgroundState
{
    SHOW_MISSION_BACKGROUND,
    SHOW_CREATE_CHARACTER_BACKGROUND
};

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Metroid");
    backgroundState backgroundState;
    sf::Music audio;
    try
    {
        audio.openFromFile("ASSETS/Music/Crimewave.mp3");
    }
    catch(const std::exception& e)
    {
        std::cerr << "NO SE PUDO ABRIR EL ARCHIVO: " << e.what() << '\n';
    }
    audio.play();

//-------

sf::Texture textureMenu_mission;
if(!textureMenu_mission.loadFromFile("ASSETS/menuSprites/characterCreation.png")) {
    std::cerr << "an error ocurred while loading file";
}
sf::Sprite spraitMenu_mission(textureMenu_mission);

sf::Vector2u windowSize_mission = window.getSize();
sf::Vector2u textureSize_mission = textureMenu_mission.getSize();
float ScaleX_mission = static_cast<float>(windowSize_mission.x) / textureSize_mission.x;
float ScaleY_mission = static_cast<float>(windowSize_mission.y) / textureSize_mission.y;

spraitMenu_mission.setScale(sf::Vector2f{ScaleX_mission, ScaleY_mission});

//-------
sf::Texture textureMenu_character;
if(!textureMenu_character.loadFromFile("ASSETS/menuSprites/characterCreation.png")) {
    std::cerr << "an error ocurred while loading file";
}
sf::Sprite spraitMenu_character(textureMenu_character);

sf::Vector2u windowSize_character = window.getSize();
sf::Vector2u textureSize_character = textureMenu_character.getSize();
float ScaleX_character = static_cast<float>(windowSize_character.x) / textureSize_character.x;
float ScaleY_character = static_cast<float>(windowSize_character.y) / textureSize_character.y;

spraitMenu_character.setScale(sf::Vector2f{ScaleX_character, ScaleY_character});


//-------

while(window.isOpen()) {
    while(const std::optional event = window.pollEvent()) {
        if(event->is<sf::Event::Closed>()) {
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
        switch (backgroundState) {
            case backgroundState::SHOW_MISSION_BACKGROUND: {
                window.draw(spraitMenu_mission);
                break;
            }

            case backgroundState::SHOW_CREATE_CHARACTER_BACKGROUND: {
                window.draw(spraitMenu_character);
                break;
            }
        }
    window.clear();
    window.display();

}

return 0;
}


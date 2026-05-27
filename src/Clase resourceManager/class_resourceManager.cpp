#include "class_resourceManager.h"
#include "../Clase Logger/class_Logger.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>

resources_components::resources_components() : texture(), sprite(texture) {} //initializing 'resources' struct. 


//Now the resourceManager definitions, blonde girls are the best by the way
resourceManager::resourceManager() : errorMessage("") {}


resourceManager& resourceManager::getInstance() {
    static resourceManager instance; //global instance: Singleton
    return instance;
}


void resourceManager::addResource(const std::string& img_path) { //puto el que lee menos yo (bernal santino) jaja salu2
    resources_components masivo_bro;
    resourceManager& mgr = getInstance();
    if (!masivo_bro.texture.loadFromFile(img_path)) {
        mgr.errorMessage = std::string("Error occurred while loading path: ") + img_path;
        Logger::logError(mgr.errorMessage);
    }
    masivo_bro.sprite = sf::Sprite(masivo_bro.texture);
    mgr.resources.insert({img_path, masivo_bro});
}


const sf::Sprite& resourceManager::getSprite(const std::string& img_path) {
    try {
        resourceManager& mgr = getInstance();
        return mgr.resources.at(img_path).sprite;
    } catch (std::exception& e) {
        resourceManager& mgr = getInstance(); //getSprite() is 'static'; it cannot access to an atribute of an object that doesn't exist (atr = errorMessage)
        mgr.errorMessage = std::string("Error ocurred, Sprite doesn't exist: ") + e.what(); // i created instance 'mgr' by the return of 'static' [getInstance()]
        Logger::logError(mgr.errorMessage); //all of this sh¨t is Singleton pattern, one instance for all the methods. aaaaah se ree hacia el yankee el putoo
        const static sf::Texture empty_texture;
        const static sf::Sprite empty_sprite(empty_texture);
        return empty_sprite;
    }
}
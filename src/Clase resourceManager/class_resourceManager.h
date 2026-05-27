#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "SFML/Graphics.hpp"

struct resources_components
{
    sf::Texture texture;
    sf::Sprite sprite;
    resources_components();
};

class resourceManager
{
public:
    resourceManager();
    static void addResource(const std::string &img_path);
    static const sf::Sprite& getSprite(const std::string &img_path);
    static resourceManager& getInstance();
private:
    std::string errorMessage;
    std::unordered_map<std::string, resources_components> resources;
};
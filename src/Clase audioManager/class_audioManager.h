#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include <optional>
#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;

class audioManager {
    public:
        audioManager();
        static audioManager& getInstance();
        static void addAudio(fs::path& audioPath);
        static const sf::Music& getAudio_obj(fs::path& audioPath);
    private:
        std::string errorMessage;
        std::unordered_map<fs::path, sf::Music> audios;
};
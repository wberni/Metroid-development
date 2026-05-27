#include "class_audioManager.h"

//Constructor of audioManager class
audioManager::audioManager() : errorMessage("") {}

audioManager& audioManager::getInstance() { //Singleton Instance
    static audioManager instance;
    return instance;
}

void audioManager::addAudio(fs::path& audioPath) { //a real problem here
    audioManager& audioMgr = getInstance(); //i've no clue how to manage the memory in this case
    sf::Music audioMusic(audioPath); //i'm gonna stop here, i'll rest for 2days, study memory deeply:
    audioMgr.audios.emplace({audioPath, audioMusic}); // and then, i'll get back stronger
}
//Esto es una mierda, es muy frustante pero es parte del proceso. La fricción dice que estoy Avanzando.
//Si alguien ve esto, ignore estos comentarios del dev y lea el código🍄
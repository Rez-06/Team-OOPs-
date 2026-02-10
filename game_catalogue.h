
#ifndef GAME_CATALOGUE_H
#define GAME_CATALOGUE_H

#include <vector>
#include <string>
using namespace std;

struct Game {
    int id;
    string name;
    string genre;
    string description;
    string releaseDate;
};

class GameCatalogue {
private:
    vector<Game> games;

public:
    void addGame();
    void removeGame(int id);
    void viewGames() const;
    Game getGameById(int id) const;
};

#endif

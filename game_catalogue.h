
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
    void addGame(int id,string name,string genre,string description,string releaseDate,AuthorizedPerson *authorized_person);
    void addGame(Game game,AuthorizedPerson *authorized_person);
    void removeGame(int id,AuthorizedPerson *authorized_person);
    void viewAllGames() const;
    void GameInfo(Game g) const;
    Game getGameById(int id) const;
};

#endif

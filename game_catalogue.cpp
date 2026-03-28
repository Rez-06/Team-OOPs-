#include "game_catalogue.h"
#include "AuthorizedPerson.h"
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
GameCatalogue::GameCatalogue(){
   ifstream file("GameCatalogue.txt");
   string line;
   while(getline(file,line)){
        Game g=deserialization(line);
        games.push_back(g);
   }
   file.close();
}
string GameCatalogue::serialization(Game g){
   string s;
   s=g.description+"*"+g.genre+"*"+to_string(g.id)+"*"+g.name+"*"+g.releaseDate+"*";
   return s;
}
Game GameCatalogue::deserialization(string s){
    Game g;
    int count=0;
    for(int i=0;i<s.size();i++){
        string temp="";
        while(i<s.size() && s[i]!='*'){
            temp+=s[i];
            i++;
        }
        if(count==0){
            g.description=temp;
        }
        if(count==1){
            g.genre=temp;
        }
        if(count==2){
            g.id=stoi(temp);
        }
        if(count==3){
            g.name=temp;
        }
        if(count==4){
            g.releaseDate=temp;
        }
        count++;
    }
    return g;
}
void GameCatalogue::addGame(Game game,AuthorizedPerson *authorized_person){
   if(authorized_person->post()=="Admin"){ 
    games.push_back(game);
   }
   else{
     cout << authorized_person->post() << " can not modify games" << endl;
   } 
}
void GameCatalogue::addGame(int id,string name,string genre,string description,string releaseDate,AuthorizedPerson *authorized_person){
    if(authorized_person->post()=="Admin"){
        Game g;
        g.id=id;
        g.name=name;
        g.description=description;
        g.genre=genre;
        g.releaseDate=releaseDate;
        games.push_back(g);
    }
    else{
     cout << authorized_person->post() << " can not modify games" << endl;
   } 
} 
void GameCatalogue::removeGame(int id,AuthorizedPerson *authorized_person){
    if(authorized_person->post()=="Admin"){
        int i=0;
        for(;i<games.size();i++){
            if(games[i].id==id){
                cout << "Successfully Deleted:" <<games[i].name << endl;
                games.erase(games.begin()+i);
                return;
            }
        }
        cout << "Game not found" << endl;
    }
    else{
     cout << authorized_person->post() << " can not modify games" << endl;
    } 
}
void GameCatalogue:: GameInfo(Game g) const{
      cout << "GameId:" << g.id << endl;
      cout << "Game  :"  << g.name << endl;
      cout << "genre :" << g.genre << endl;
      cout << "description:" << endl;
      cout << g.description << endl;
      cout << "Released:" << g.releaseDate << endl;
}
void GameCatalogue::viewAllGames() const{
     for(int i=0;i<games.size();i++){
        GameInfo(games[i]);
        cout << endl;
     } 
}
Game GameCatalogue::getGameById(int id) const{
    for(int i=0;i<games.size();i++){
        if(games[i].id==id){
            return games[i];
        }
    }
}
GameCatalogue::~GameCatalogue(){
    ofstream file("GameCatalogue.txt");
    for(int i=0;i<games.size();i++){
        string s=serialization(games[i]);
        file << s << endl;
    }
    file.close();
}


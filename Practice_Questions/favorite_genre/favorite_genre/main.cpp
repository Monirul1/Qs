#include<unordered_map>
#include<map>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

map<string, vector<string>> getUserFavouriteGenres(map<string, vector<string>> userSongs, map<string, vector<string>> songGenres){
    map<string, vector<string>> userFavGenres;

    map<string, string> songToGenre; // maps the song name to its genre
    for (auto it = songGenres.begin(); it != songGenres.end(); ++it){
        string genre = it->first;
        vector<string> songs = it->second;

        for (string song : songs){
            songToGenre[song] = genre;
        }
    }

    for (auto it = userSongs.begin(); it != userSongs.end(); ++it){
        string user = it->first;
        vector<string> userFavSongs = it->second;
        unordered_map<string, int> songGenresCount;
        int maxCount = 0;
        for (string song : userFavSongs){
            string songGenre = songToGenre[song];
            songGenresCount[songGenre]++;
            maxCount = max(maxCount, songGenresCount[songGenre]);
        }

        for (auto ii = songGenresCount.begin(); ii != songGenresCount.end(); ++ii){
            if(ii->second == maxCount){
                if(userFavGenres.find(user) == userFavGenres.end())
                    userFavGenres[user] = {};
                userFavGenres[user].push_back(ii->first);
            }
        }
    }
    return userFavGenres;
}

int main(void){
    map<string, vector<string>> userSongs;
    map<string, vector<string>> songGenres;

    userSongs["David"] = {"song1", "song2", "song3", "song4", "song8"};
    userSongs["Emma"] = {"song5", "song6", "song7"};

    
    songGenres["Rock"] = {"song1", "song3"};
    songGenres["Dubstep"] = {"song7"};
    songGenres["Techno"] = {"song2", "song4"};
    songGenres["Pop"] = {"song5", "song6"};
    songGenres["Jazz"] = {"song8", "song9"};
    

    map<string, vector<string>> result = getUserFavouriteGenres(userSongs, songGenres);
    for (auto it = result.begin(); it != result.end(); ++it){
        cout << it->first << ": ";
        for (string g : it->second){
            cout << g << ", ";
        }
        cout << endl;
    }

    return 0;
}

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//unordered_map<string,vector<string>> songsAndGenre(unordered_map<string,vector<string>>& users, unordered_map<string,vector<string>>& genres){
//    unordered_map<string,string> songToGenre;
//    unordered_map<string,unordered_map<string,int>> userToGenre;
//    unordered_map<string,vector<string>> result;
//    unordered_map<string,int> max;
//    for(auto genre:genres)
//    {
//        for(auto song: genre.second)
//        {
//            songToGenre[song] = genre.first;
//        }
//    }
//
//    for(auto user:users)
//    {
//        for(auto item:user.second)
//        {
//            userToGenre[user.first][songToGenre[item]]++;
//            auto tempMax = userToGenre.at(user.first).at(songToGenre[item]);
//            max[user.first] = std::max(tempMax,max[user.first]);
//        }
//    }
//
//    for(auto user:userToGenre)
//    {
//        for(auto genre:user.second)
//        {
//            if(genre.second==max.at(user.first))
//            {
//                result[user.first].push_back(genre.first);
//            }
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    unordered_map<string,vector<string>> users;
//    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
//    users["Emma"] = {"song5", "song6", "song7"};
//
//    unordered_map<string,vector<string>> songs;
//    songs["Rock"] = {"song1", "song3"};
//    songs["Dubstep"] = {"song7"};
//    songs["Techno"] = {"song2", "song4"};
//    songs["Pop"] = {"song5", "song6"};
//    songs["Jazz"] = {"song8", "song9"};
//
//    unordered_map<string, vector<string>> result = songsAndGenre(users,songs);
//
//    for(auto it = result.begin(); it!=result.end(); it++)
//    {
//        cout << it->first << ": ";
//        for(int i = 0; i < it->second.size(); i++)
//        {
//            cout << it->second[i] << ", ";
//        }
//        cout << endl;
//    }
//
//
//}

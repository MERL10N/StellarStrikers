#pragma once


#include <string>
#include <vector>
#include <raylib.h>


struct PlayerScore {
    std::string name;
    int score;
};


class Leaderboard{
    public:
        Leaderboard();
        void SaveToFile() const;
        void LoadFromFile();
        void SortLeaderboard();
        void DrawLeaderboard(int, int) const;
        void AddPlayerScore(int);
        const std::vector<PlayerScore>& GetScores() const {
            return playerScores;
        }


    private:
    std::vector<PlayerScore> playerScores;
    int playerNumber = 0;
       
};

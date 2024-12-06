#include "Leaderboard.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>


Leaderboard::Leaderboard(){
    playerScores.push_back({"test1", 0});
}
void Leaderboard::SaveToFile() const{
    std::ofstream file("Leaderboard.txt");
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file for writing!\n";
            return;
        }
        for (const auto& playerScores : playerScores) {
            file << playerScores.name << " " << playerScores.score << "\n"; // Each player on a new line
        }
        file.close();
}
void Leaderboard::LoadFromFile(){
    std::ifstream file("Leaderboard.txt");
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file for reading!\n";
            return;
        }
        playerScores.clear(); // Clear existing data
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            PlayerScore player;
            iss >> player.name >> player.score;
            playerScores.push_back(player);
            playerNumber++;
        }
        file.close();
}


    // Sorts the leaderboard by score in descending order
void Leaderboard::SortLeaderboard() {
    std::sort(playerScores.begin(), playerScores.end(), [](const PlayerScore& a, const PlayerScore& b) {
            return a.score > b.score; // Higher scores first
    });
}

void Leaderboard::DrawLeaderboard(int x, int y) const {
    DrawText("Leaderboard", x, y, 30, WHITE); // Title

    int yOffset = y + 50; // Start below the title
    for (const auto& player : playerScores) {
        std::string text = player.name + ": " + std::to_string(player.score);
        DrawText(text.c_str(), x, yOffset, 20, LIGHTGRAY); // Adjust text size and color
        yOffset += 30; // Spacing between entries
    }
}

void Leaderboard::AddPlayerScore(int score){
    std::string currName = "Player" + std::to_string(playerNumber);
    playerScores.push_back({currName, score});
}
#pragma once
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <fstream>
#include <string>
#include <list>

using namespace sf;
using namespace std;

#include "Entity.h"

class Engine
{
    public:
        Engine();
        void Run();
    private:
        Direction playerDirection;
        Direction prev_Direction;
        Direction wantedDirection;
        RenderWindow m_Window;
        Vector2f resolution;
        string m_Scoreboard;
        int m_Lives;
        bool levelUp = false;
        bool dead = false;
        //text overlay
        Text feed;
        Text levelTitle;
        Text escape;
        Text countdown;
        Text gameover;
        Text newHS;
        Text endHS;
        int countdownNum;
        Font font;
        Player *m_Player;
        vector<Enemy> m_Enemies;
        //vector<Rect<float>> m_Map; //Changed  from vector<RectangleShape> m_Map;
	    void Input();
	    void Update();
	    void Draw();
        int m_level;
        list<Rect<float>> m_fruitMap;
        list<Rect<float>> m_dotsMap;
        vector<Rect<float>> m_wallsMap;
        vector<Rect<float>> GenerateWalls();
        list<Rect<float>> GenerateDots();
        list<Rect<float>> GenerateFruit();
        void DrawWalls(vector<Rect<float>> walls);
        void DrawItems(list<Rect<float>> dots, list<Rect<float>> fruit);
        ifstream m_InputFile;
        ofstream m_OutputFile;
        int m_HighScore;
        int currentScore;
        void CheckHighScore(int newScore);
        void WallCollision();
        bool EnemyCollision(Rect<float> playerRect);
        bool ItemCollision(Rect<float> playerRect);
        void BoarderDetection();
        Vector2f spaces;
        void DrawEnemies();
        void GenerateText();
        void reset();
};
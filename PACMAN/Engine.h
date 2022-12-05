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

#include "Item.h"
#include "Entity.h"
#include <list>

class Engine
{
    public:
        Engine();
        void Run();
    private:
        Direction playerDirection;
        RenderWindow m_Window;
        Vector2f resolution;
        View m_Scoreboard;

        //text overlay
        Text feed;
        Font font;
        Player *m_Player;
        vector<Enemy> m_Enemies;
        //vector<Rect<float>> m_Map; //Changed  from vector<RectangleShape> m_Map;
	    void Input();
	    void Update();
	    void Draw();
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

};
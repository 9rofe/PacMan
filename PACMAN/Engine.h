#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
//#include <thread>

using namespace sf;
using namespace std;

#include "Item.h"
#include "Entity.h"

class Engine
{
public:
    Engine();
    void Run();
private:
    Direction playerDirection;
    RenderWindow m_Window;
    Vector2f resolution;
    View m_MainView;
    //scoreboard with score lives level and countdown 
    View m_HudView;
    //text overlay
    Text feed;
    bool loaded = false;
    Font font;
    Player *m_Player;
    vector<Rect<float>> m_Map; //Changed  from vector<RectangleShape> m_Map;
	void Input();
	void Update();
	void Draw();
    vector<Rect<float>> m_fruitMap;
    vector<Rect<float>> m_dotsMap;
    vector<Rect<float>> m_wallsMap;
    vector<Rect<float>> GenerateWalls();
    vector<Rect<float>> GenerateDots();
    vector<Rect<float>> GenerateFruit();
    void DrawWalls(vector<Rect<float>> walls);
    void DrawItems(vector<Rect<float>> dots, vector<Rect<float>> fruit);
    

};
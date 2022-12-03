#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <sstream>
#include <thread>

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
    Font font;
    Player *m_Player;
    vector<RectangleShape> m_Map;
	void Input();
	void Update();
	void Draw();
};
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
	void run();
private:
    Direction playerDirection;   
    RenderWindow m_Window;
    View m_MainView;
    //scoreboard with score lives level and countdown 
    View m_HudView;
    //text overlay
    Text feed;
    Font font;
    //Player m_Player(0.0,0.0);
    //vector<RectangleShape> m_map;
	void input();
	void update();
	void draw();
};
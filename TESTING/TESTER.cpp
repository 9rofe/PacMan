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

int main()  {
    //setup window
    RenderWindow m_Window;
    View m_MainView;
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "PacMan",
        Style::Fullscreen);
    m_MainView.setSize(resolution);

    //RUN TESTS BELOW
    vector<RectangleShape> m_Map;
    for (int counter = 0; counter < m_Map.size(); counter++)
	    {
		    if (counter < 2)
		    {   
			    cout << "0" << endl;
			    m_Map.at(counter).setSize(sf::Vector2f(500, 50));
		    }
	        else if (counter > 2 && counter < 4) { m_Map.at(counter).setSize(sf::Vector2f(50, 500)); }

	    m_Map.at(counter).setPosition(0.0, 0.0);
	    m_Map.at(counter).setFillColor(Color::White);
	    m_Window.draw(m_Map.at(counter));
        }
    return 0;
}
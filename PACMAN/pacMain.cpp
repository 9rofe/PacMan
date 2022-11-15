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



int main()
{
    enum class State {
        CALCULATING, DISPLAYING
    };
    State state = State::CALCULATING;

    Vector2f resolution;
    resolution.y = VideoMode::getDesktopMode().height;
    resolution.x = VideoMode::getDesktopMode().width;
    VideoMode vm(resolution.x, resolution.y);
    // Create and open a window for the game
    RenderWindow window(vm, "-----", Style::Fullscreen);
    
    Text feed;
    Font font;
    font.loadFromFile("fonts/TitilliumWeb-Regular.ttf");
    if (!font.loadFromFile("fonts/TitilliumWeb-Regular.ttf"))
    {
        // error
    }
    FloatRect textRect = feed.getLocalBounds();
    feed.setFont(font);
    feed.setCharacterSize(20);
    feed.setFillColor(Color::White);
    feed.setOutlineColor(Color::Blue);
    feed.setOutlineThickness(2.0);
    feed.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    feed.setPosition(textRect.height / 10.0f, textRect.width / 20.0f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                // Quit the game when the window is closed
                window.close();
            }

            //read mouse moved event
            if (event.type == sf::Event::MouseMoved)
            {
               
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //update
        //if CALCUATING
        if (state == State::CALCULATING)
        {
            
        }
        
        //set state to DISPLAYING
        state = State::DISPLAYING;

        imaginaryPlane.loadText(feed);
        
        window.clear();
        

        window.display();
    }
    return 0;
}

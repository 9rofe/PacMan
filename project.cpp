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

#include "ComplexPlane.h"

/*
void calculate(Vector2f resolution, VertexArray& pixels, RenderWindow& window, ComplexPlane imaginaryPlane, int num_of_threads, int p)
{
    for (int j = p; j < resolution.x; j += num_of_threads)
    {
        for (int i = 0; i < resolution.y; i++)
        {
            pixels[j + i * resolution.x].position = { (float)j,(float)i };
            Vector2f pixelPosition = window.mapPixelToCoords(Vector2i{ j , i }, imaginaryPlane.getView());
            size_t numIterations = imaginaryPlane.countIterations(pixelPosition);
            Uint8 r, g, b;
            imaginaryPlane.iterationsToRGB(numIterations, r, g, b);
            pixels[j + i * resolution.x].color = { r,g,b };
        }
    }
}
*/

int main()
{
    //set states
    enum class State {
        CALCULATING, DISPLAYING
    };
    State state = State::CALCULATING;

    Vector2f resolution;
    resolution.y = VideoMode::getDesktopMode().height;
    resolution.x = VideoMode::getDesktopMode().width;
    VideoMode vm(resolution.x, resolution.y);
    // Create and open a window for the game
    RenderWindow window(vm, "Mandelbrot", Style::Fullscreen);

    float aspectRatio = resolution.y / resolution.x;
    ComplexPlane imaginaryPlane(aspectRatio);

    //cout << imaginaryPlane.getView().getCenter().x << endl;
    //cout << imaginaryPlane.getView().getCenter().y << endl;
    //cout << imaginaryPlane.getView().getSize().x << endl;
    //cout << imaginaryPlane.getView().getSize().y << endl;

    cout << resolution.x << endl;
    cout << resolution.y << endl;
    cout << aspectRatio << endl;

    VertexArray pixels;
    pixels.setPrimitiveType(Points);
    pixels.resize(resolution.x * resolution.y);

    //Vector2f mouseWorldPosition;
    //Vector2f mouseScreenPosition;

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
               //update mouse position member variable
                Vector2f mouseScreenPosition = window.mapPixelToCoords(Mouse::getPosition(), imaginaryPlane.getView());
                imaginaryPlane.setMouseLocation(mouseScreenPosition);
            }

            

            if (event.type == sf::Event::MouseButtonPressed)
            {
                Vector2f mouseWorldPosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y), imaginaryPlane.getView());
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x (left): " << mouseWorldPosition.x << std::endl;
                    std::cout << "mouse y (left): " << mouseWorldPosition.y << std::endl;
                    
                    imaginaryPlane.zoomIn();
                    imaginaryPlane.setCenter(mouseWorldPosition);
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x (right): " << mouseWorldPosition.x << std::endl;
                    std::cout << "mouse y (right): " << mouseWorldPosition.y << std::endl;
                    
                    imaginaryPlane.zoomOut();
                    imaginaryPlane.setCenter(mouseWorldPosition);
                }
                //set state variable to CALCULATING
                state = State::CALCULATING;
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
            /*
            //update your vertex array
            for (int j = 0; j < resolution.x; j++)
            {
                for (int i = 0; i < resolution.y; i++)
                {
                    pixels[j + i * resolution.x].position = { (float)j,(float)i };
                    Vector2f pixelPosition = window.mapPixelToCoords(Vector2i{ j , i }, imaginaryPlane.getView());
                    size_t numIterations = imaginaryPlane.countIterations(pixelPosition);
                    Uint8 r, g, b;
                    imaginaryPlane.iterationsToRGB(numIterations, r, g, b);
                    pixels[j + i * resolution.x].color = { r,g,b };
                }
            }
            */
            
            //multithreading
            const int num_of_threads = 8;
            vector<thread> THREADS(num_of_threads);
            const int num_of_elements = resolution.x + resolution.y;
            const int step = (num_of_elements / num_of_threads);

            for (int i = 0; i < THREADS.size(); i++)
            {
                THREADS.at(i) = thread(calculate, resolution, ref(pixels), ref(window), imaginaryPlane, num_of_threads, i);   
            }
            for (int i = 0; i < THREADS.size(); i++)
            {
                THREADS.at(i).join();
            }
            
            
        }
        
        //set state to DISPLAYING
        state = State::DISPLAYING;

        imaginaryPlane.loadText(feed);
        
        window.clear();

        window.draw(pixels);
        window.draw(feed);
        

        window.display();
    }
    return 0;
}

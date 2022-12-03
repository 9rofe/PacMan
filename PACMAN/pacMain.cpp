#include "Engine.h"

int main()
{
    /*
    Direction playerDirection = Direction::RIGHT;
    Direction enemyDirection;

    Vector2f resolution;
    resolution.y = VideoMode::getDesktopMode().height;
    resolution.x = VideoMode::getDesktopMode().width;
    VideoMode vm(resolution.x, resolution.y);
    // Create and open a window for the game
    RenderWindow window(vm, "PacMan", Style::Fullscreen);
    
    Text feed;
    Font font;
    font.loadFromFile("fonts/CrackMan.TTF");
    if (!font.loadFromFile("fonts/CrackMan.TTF"))
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

            if (event.type == sf::Event::KeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    playerDirection = Direction::UP;              
                }
                if (Keyboard::isKeyPressed(Keyboard::Down))
                {
                    playerDirection = Direction::DOWN;
                }
                if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    playerDirection = Direction::LEFT;
                }
                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    playerDirection = Direction::RIGHT;
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //countdown (start direction NONE for countdown)
        
        //check if no wall in selected direction
            //player.move
            
        //if player collision with wall
            //check playerDirection
            //if it cant go that way
                //set playerDirection NONE
            //else
                //player.Move()

        //if enemy collision
            //if collision with wall
                //switch direction
            //if collision with character
                //lives--
                //if lives == 0
                    //game over
                    //MAYBE PLAY AGAIN
                //else
                    //reset player location
        
        //if player collision with item location
            //if dot
                //add m_points to score
            //if fruit
                //add m_points to score
            //delete item from vector
            //if item vector size == 0
                //rerun game
                //increase ghost speed
                //"level 2"


        
        imaginaryPlane.loadText(feed);
        
        window.clear();
        

        window.display();
    }*/

    //FULL CODE
    Engine engine;

    engine.Run();

    return 0;
}

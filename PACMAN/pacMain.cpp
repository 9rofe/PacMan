#include "Engine.h"

int main()
{
    /*
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
    }*/
    //FULL CODE
    Engine engine;

    engine.Run();

    return 0;
}
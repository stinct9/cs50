//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    double dx = drand48()/25;
    double dy = drand48()/25;
  
    // keep playing until game over
    while (lives > 0 && bricks > 0 && lives < 4)
    {
        // TODO           
        GEvent event = getNextEvent(KEY_EVENT); 
        if (event != NULL)
        {   
            //printf("%d %.0f %.0f\n",getKeyCode(event), getX(paddle), getY(paddle));               
            if (getX(paddle) < 325)
               if (getKeyCode(event) == RIGHT_ARROW_KEY)
                    move(paddle, 20, 0);  
            
            if (getX(paddle) > 0)
               if (getKeyCode(event) == LEFT_ARROW_KEY)
                    move(paddle, -20, 0);                       
        }
                   
        move(ball, dx, dy);            
        //printf("%.0f\n", getX(ball));
        if (getX(ball) < 0 || getX(ball) > 380)
            dx = -dx;
        if (getY(ball) < 0)
            dy = -dy; 
        
        GObject object = detectCollision(window, ball);
        
        if (object != NULL)
             if (strcmp(getType(object), "GRect") == 0)
                 if (strcmp(getType(object), "GLabel") != 0)
                 {  
                     if (object == paddle)
                     {                        
                        //dx = -dx + 0.002;
                        dy = -dy - 0.001;
                     } 
                     else
                     {
                        removeGWindow(window, object);
                        //dx = -dx + .01;
                        dy = -dy + .002;
                        points++;
                     }                
                 }
         if (getY(ball) > 600)
         {
            lives--;
            if (lives == 0)
            {
                GLabel lostlife = newGLabel("YOU'VE LOST ALL LIFE. CLICK TO END.");
                setFont(lostlife, "SansSerif-18");
                setLocation(lostlife, 20, 500);
                add(window, lostlife);
                break;
            }
            else
            {
            GLabel lostlife = newGLabel("YOU'VE LOST A LIFE");
            setFont(lostlife, "SansSerif-18");
            setLocation(lostlife, 110, 500);
            add(window, lostlife);
            pause(500);
            removeGWindow(window, lostlife);
            
            setLocation(ball, WIDTH/2-RADIUS, HEIGHT/2);
            waitForClick();
            }
         }
         
         updateScoreboard(window, label, points);                
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
        int x = 20;
        int y = 50;
        int len = 31;
        int wid = 20;
        int gap = 5;
        
        GRect grid = newGRect(x, y, len, wid);
        
        for(int i = 0; i < COLS; i++)
        {          
            for(int j = 0; j < ROWS; j++)
            {
                y = y + wid + gap;
                grid = newGRect(x, y, len, wid);
                setColor(grid, "LIGHT_GRAY");
                setFilled(grid, true);
                add(window, grid);
            }            
            x = x + len + gap;
            y = 50;          
        }       
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(WIDTH/2-RADIUS, HEIGHT/2, RADIUS*2, RADIUS*2);
    
    setColor(ball, "DARK_GRAY");
    setFilled(ball, true);
    add(window, ball);    
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect rect = newGRect(175, 570, 75, 5);
    setFilled(rect, true);
    setColor(rect, "BLACK");
    add(window, rect);
    
    return rect;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("");
    setFont (label, "SansSerif-36");
    add(window, label);
     
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}

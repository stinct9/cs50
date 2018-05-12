
// standard libraries
#include <stdio.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

int main(void)
{
    GWindow window = newGWindow(320, 240);
    
    GRect rect = newGRect(0, 110, 20, 20);
    setColor(rect, "BLUE");
    setFilled(rect, true);
    add(window, rect);
    
    double movepaddle = 10;
        
    while (true)
    {
        GEvent event = getNextEvent(KEY_EVENT);
        
        if (event != NULL)

            {
                printf("%d %.0f %.0f\n",getKeyCode(event), getX(rect), getY(rect));
                
                if (getX(rect) > 0)
                    if (getKeyCode(event) == LEFT_ARROW_KEY)
                        move(rect, -movepaddle, 0);
                if (getX(rect) < 300)
                    if (getKeyCode(event) == RIGHT_ARROW_KEY)
                        move(rect, movepaddle, 0);
            }        
    }
}

//
//  Game.cpp
//
//
//  Created by Zach Yuzon on 10/10/17.
// 
//

#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;


//Tractor Class functions
int x;                      // x coordinate of tractor
int y;                      // y coordinate of tractor
unsigned short size;        // size of the tractor.
Activity activity;          // current activity
    

    
// all the accessor methods
int Tractor::GetX() const
{
    return x;
}
    
int Tractor::GetY() const
{
    return y;
}
    
unsigned short Tractor::GetSize() const
{
    return size;
}
    
Activity Tractor::GetActivity() const
{
    return activity;
}
    
// all the mutator methods
void Tractor::SetX(const int x_val)
{
    x = x_val;
}
    
void Tractor::SetY(const int y_val)
{
    y = y_val;
}
    
void Tractor::SetSize(const unsigned short size_val)
{
    size = size_val;
}
    
void Tractor::SetActivity(const Activity& act)
{
    activity = act;
}
    
// Constructors
Tractor::Tractor()
{
    x = 0;
    y = 0;
    size = 2;
    activity = IDLE;
}
    
Tractor::Tractor(int x_val, int y_val, unsigned short size_val, Activity activity_val)
{
    x = x_val;
    y = y_val;
    size = size_val;
    activity = activity_val;
}
    
    



    

//Game Class functions
unsigned int map_size;          // size of the game map
vector<Tractor> all;            // list of all tractors on the map
vector<int> selected;           // indexes of all units currently selected in the "all"
    

    
Game::Game(unsigned int new_size)
{
    map_size = new_size;
}
    
int Game::GetTractor(int x, int y) const
{
    unsigned int x1 = x;
    unsigned int y1 = y;
        
    if(x1 > map_size - 1 ||  y1 > map_size - 1)
    {
        return -1;
    }
        
    int i = 0;
    
    //while-loop checks if the x,y parameters are inside a Tractor's square in the all vector.
    while(i < all.size())
    {
            
        if(x1 >= all.at(i).GetX() - (all.at(i).GetSize() / 2.0) && x1 <= all.at(i).GetX() + (all.at(i).GetSize() / 2.0) && y1 >= all.at(i).GetY() - (all.at(i).GetSize() / 2.0) && y1 <= all.at(i).GetY() + (all.at(i).GetSize() / 2.0))
        {
            return i;
        }
        i++;
            
    }
        
    return -1;
}
    
void Game::SelectTractor(int x, int y)
{
        
    while(selected.size() != 0)     //this while loop empties the selected vector
    {
        selected.pop_back();
    }
        
        
    int i = 0;
    int j = 0;
    
     //checks if the x,y parameters are inside a Tractor's square in the "all" vector
    while( i < all.size())
    {
        if(x >= all.at(i).GetX() - (all.at(i).GetSize() / 2.0) && x <= all.at(i).GetX() + (all.at(i).GetSize() / 2.0) && y >= all.at(i).GetY() - (all.at(i).GetSize() / 2.0) && y<= all.at(i).GetY() + (all.at(i).GetSize() / 2.0))
        {
            selected.push_back(i);
                
        }
        i++;
            
    }
        
        
}
    
void Game::SelectTractors(int x1, int y1, int x2, int y2)
{
    while(selected.size() != 0)     //this while loop empties the selected vector
    {
        selected.pop_back();
    }
        
    int bigX, smallX, bigY, smallY;
        
    if(x1 > x2)
    {
        bigX = x1;
        smallX = x2;
    } else
    {
        bigX = x2;
        smallX = x1;
    }
        
    if(y1 > y2)
    {
        bigY = y1;
        smallY = y2;
    } else
    {
        bigY = y2;
        smallY = y1;
    }
        
    int i = 0;
    
    //while-loop checks if Tractor's square in all vector is at least partially intersecting with rectangle
    while(i < all.size())
    {
            
        if( (all.at(i).GetX() +  (all.at(i).GetSize() / 2.0) >= smallX && all.at(i).GetX() - (all.at(i).GetSize() / 2.0) <= bigX) && (all.at(i).GetY() +  (all.at(i).GetSize() / 2.0) >= smallY && all.at(i).GetY() - (all.at(i).GetSize() / 2.0) <= bigY) )
        {
            selected.push_back(i);
        }
        i++;
    }
        
}
    
void Game::AddTractor(const Tractor& new_unit)
{
    /*  this for-loop checks if the new Tractor's square overlaps another Tractor's square. commented out after Professor said this check wasn't necessary.
     
    for(int j = 0; j < all.size(); j++)
    {
        
         
        if( (new_unit.GetX() + (new_unit.GetSize() / 2.0) >= all.at(j).GetX() - (all.at(j).GetSize() / 2.0) && new_unit.GetX() - (new_unit.GetSize() / 2.0) <= all.at(j).GetX() + (all.at(j).GetSize() / 2.0)) && (new_unit.GetY() + (new_unit.GetSize() / 2.0) >= all.at(j).GetY() - (all.at(j).GetSize() / 2.0) && new_unit.GetY() - (new_unit.GetSize() / 2.0) <= all.at(j).GetY() + (all.at(j).GetSize() / 2.0)) )
        {
            cout << "The Tractor could not be added because its square overlaps with another Tractor's square inside the \"all\" vector." << endl;
            return;
        }
         
            
    }
        */
    
    all.push_back(new_unit);
}
    
bool Game::MoveTractor(int i, int new_x, int new_y)
{
    unsigned int newX = new_x;
    unsigned int newY = new_y;
        
    //if statement checks if new coordinates are within the boundaries of the map
    if (newX > map_size - 1 || newY > map_size - 1)
    {
        return false;
    }
        
        
    //if statement checks to see if the Tractor's size will still allow it to fit into the map if it is moved to the new coordinates
    if(newX + (all.at(i).GetSize() / 2.0) > (map_size - 1) && newX - (all.at(i).GetSize() / 2.0) < (map_size - 1) && newY + (all.at(i).GetSize() / 2.0) > (map_size - 1) && newY - (all.at(i).GetSize() / 2.0) < (map_size - 1))
    {
        return false;
    }
        
        
    //for-loop checks if the Tractor's square new coordinates overlap another Tractor's square
    for(int j = 0; j < all.size(); j++)
    {
        if(j != i)
        {
            if( (newX + (all.at(i).GetSize() / 2.0) >= all.at(j).GetX() - (all.at(j).GetSize() / 2.0) && newX - (all.at(i).GetSize() / 2.0) <= all.at(j).GetX() + (all.at(j).GetSize() / 2.0)) && (newY + (all.at(i).GetSize() / 2.0) >= all.at(j).GetY() - (all.at(j).GetSize() / 2.0) && newY - (all.at(i).GetSize() / 2.0) <= all.at(j).GetY() + (all.at(j).GetSize() / 2.0)))
            {
                return false;
            }
        }
            
    }
        
    // moves the Tractor to the new location after succeeding all checks
    all.at(i).SetX(newX);
    all.at(i).SetY(newY);
        
    return true;
}
    
void Game::AssignTractorsActivity(const Activity& new_activity)
{
    for(int i = 0; i < selected.size(); i++)
    {
        all.at(selected.at(i)).SetActivity(new_activity);
    }
}
    
void Game::PrintTractor(int i) const
{
        
    cout << "The x-coordinate of Tractor " << i << " is " << all.at(i).GetX() << endl;
    cout << "The y-coordinate of Tractor " << i << " is " << all.at(i).GetY() << endl;
    cout << "The size of Tractor " << i << " is " << all.at(i).GetSize() << endl;
    cout << "The possible Activities: SEEDING = 0, HARVESTING = 1, MOVING = 2, and IDLE = 3" << endl;
    cout << "The current Activity of Tractor " << i << " is " << all.at(i).GetActivity() << endl;
    cout << "\n";
}
    
void Game::PrintSelectedTractors() const
{
    for(int i = 0; i < selected.size(); i++)
    {
        cout << "Here are the coordinates, size, and current Activity of Tractor " << selected.at(i) << endl;
        cout << "X-Coordinate: " << all.at(selected.at(i)).GetX() << endl;
        cout << "Y-Coordinate: " << all.at(selected.at(i)).GetY() << endl;
        cout << "Size: " << all.at(selected.at(i)).GetSize() << endl;
        cout << "The possible Activities: SEEDING = 0, HARVESTING = 1, MOVING = 2, and IDLE = 3" << endl;
        cout << "Tractor's Current Activity: " << all.at(selected.at(i)).GetActivity() << endl;
        cout << "\n";
    }
}
    
void Game::PrintAllTractors() const
{
    for(int i = 0; i < all.size(); i++)
    {
        cout << "Here are the coordinates, size, and current Activity of Tractor " << i << endl;
        cout << "X-Coordinate: " << all.at(i).GetX() << endl;
        cout << "Y-Coordinate: " << all.at(i).GetY() << endl;
        cout << "Size: " << all.at(i).GetSize() << endl;
        cout << "The possible Activities are: SEEDING = 0, HARVESTING = 1, MOVING = 2, and IDLE = 3" << endl;
        cout << "Tractor's Current Activity: " << all.at(i).GetActivity() << endl;
        cout << "\n";
    }
}


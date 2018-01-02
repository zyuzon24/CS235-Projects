//
//  Game.h
//  
//
//  Created by Zach Yuzon on 10/10/17.
//
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include <vector>
using namespace std;

enum Activity {SEEDING, HARVESTING, MOVING, IDLE};

class Tractor
{
private:
    
    int x;                      // x coordinate of tractor
    int y;                      // y coordinate of tractor
    unsigned short size;        // size of the tractor.
    Activity activity;          // current activity
    
public:
    int GetX() const;
    int GetY() const;
    unsigned short GetSize() const;
    Activity GetActivity() const;
    
    void SetX(const int x_val);
    void SetY(const int y_val);
    void SetSize(const unsigned short size_val);
    void SetActivity(const Activity& act);
    
    Tractor();
    Tractor(int x_val, int y_val, unsigned short size_val, Activity activity_val);
};

class Game
{
private:
    
    unsigned int map_size;          // size of the game map
    vector<Tractor> all;            // list of all tractors on the map
    vector<int> selected;           // indexes of all units currently selected in the "all"
    
public:
    Game(unsigned int new_size);
    
    int GetTractor(int x, int y) const;
    
    void SelectTractor(int x, int y);
    void SelectTractors(int x1, int y1, int x2, int y2);
    void AddTractor(const Tractor& new_unit);
    bool MoveTractor(int i, int new_x, int new_y);
    void AssignTractorsActivity(const Activity& new_activity);
    
    void PrintTractor(int i) const;
    void PrintSelectedTractors() const;
    void PrintAllTractors() const;
};
#endif /* Game_h */

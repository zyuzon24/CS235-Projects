//
//  main.cpp
//  
//
//  Created by Zach Yuzon on 10/15/17.
//
//

#include "Game.h"
#include <iostream>
using namespace std;

int main()
{
    Game game(100);
    Tractor t1(5,4,4,IDLE);
    Tractor t2(76,80,6,SEEDING);
    Tractor t3(83,85,6,MOVING);
    game.AddTractor(t1);
    game.AddTractor(t2);
    game.AddTractor(t3);
    
    Tractor t4;
    t4.SetX(50);
    t4.SetY(50);
    t4.SetActivity(HARVESTING);
    t4.SetSize(4);
    game.AddTractor(t4);
    game.PrintTractor(3);
    
    Tractor t5;
    game.AddTractor(t5);
    game.PrintTractor(4);
    
    
    cout << game.GetTractor(50,30) << endl;
    
    game.SelectTractor(3,2);
    game.PrintSelectedTractors();
    game.SelectTractor(78,78);
    game.PrintSelectedTractors();
    
    
    
    game.SelectTractors(79,83,80,77);
    game.PrintSelectedTractors();
    game.AssignTractorsActivity(HARVESTING);
    game.PrintSelectedTractors();
    
    
    
    cout << game.MoveTractor(0,71,75) << endl;
    game.PrintTractor(0);
    
    
    
    
    
    
    /*
     vector<int> all;
     all.push_back(2);
     all.push_back(2);
     all.push_back(2);
     all.push_back(2);
     
     
     while (all.size() != 0)
     {
     cout << all.size() << endl;
     all.pop_back();
     }
     
     cout << all.size() << endl;
     
     unsigned int x = 2;
     int test= 100;
     bool isC = test/x;
     if(isC){
     cout << "The test worked" << endl;
     }
     */
    
    return 0;
}

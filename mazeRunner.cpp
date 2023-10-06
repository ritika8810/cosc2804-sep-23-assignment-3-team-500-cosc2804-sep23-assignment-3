#include <iostream>

#include <mcpp/mcpp.h>

#include "menuUtils.h"
#include "Maze.h"
#include "Agent.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

enum States{
    ST_Main,
    ST_GetMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(void){

    bool mode = NORMAL_MODE;
    //read Mode
    printStartText();

    mcpp::MinecraftConnection mc; 
    mc.doCommand("time set day"); 

    States curState = ST_Main;

    //State machine for menu 
    int getMenuNum;
    int getMazeNum;       
    int getSolveNum;
    while (curState != ST_Exit)
    {
        
        //Do something
        if(curState == ST_Main){
            MainMenu:
            printMainMenu();
            std::cin >> getMenuNum;
            if(getMenuNum == 1){
                MazeMenu:
                printGenerateMazeMenu();
                std::cin >> getMazeNum;
                if (getMazeNum == 1){
                    //TODO Read Maze from terminal
                }
                else if(getMazeNum == 2){
                    //TODO Generate Random Maze
                }
                else if(getMazeNum == 3){
                    goto MainMenu;
                }
                else {
                    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                    goto MazeMenu;
                }    
            }
            else if(getMenuNum == 2){ 
                curState = ST_GetMaze;
            }
            else if(getMenuNum == 3){
                curState = ST_SolveMaze;
            }
            else if(getMenuNum == 4){
                curState = ST_Creators;
            }
            else if(getMenuNum == 5){
                //TODO WorldCleaning code
                curState = ST_Exit;
            }
            else {
                std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
                goto MainMenu;
            }
        }
        else if(curState == ST_GetMaze){
            //TODO check if a maze already exists
            //TODO Teleport Player to the location
            //TODO flatten the terrain
            //TODO Make maze  
            goto MainMenu;

        }
        else if(curState == ST_SolveMaze){
            SolveMenu:
                printSolveMazeMenu();
                std::cin >> getSolveNum;
                if (getSolveNum == 1){
                    //TODO Solve Manually
                }
                else if(getSolveNum == 2){
                    //TODO show Escape Route
                }
                else if(getSolveNum == 3){
                    goto MainMenu;
                }
                else {
                    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                    goto SolveMenu;
                }
        }
        else if(curState == ST_Creators){
            printTeamInfo();
            goto MainMenu;
        }

    }

    printExitMassage();


    return EXIT_SUCCESS;


    //checklist
    //mainmenu 1 2 3 4 5 else             // remaining : 1 , 2 , 3 , 5
    //1 generatemazemenu 1 2 3 else       // remaining : 1 and 2
    //2 buildmaze                         // remaining : all
    //3 solvemazemenu 1 2 3 else          // remaining : 1 and 2
    //4 teaminfo                          // remaining : done
    //5 exit                              // remaining :worldcleaning



}
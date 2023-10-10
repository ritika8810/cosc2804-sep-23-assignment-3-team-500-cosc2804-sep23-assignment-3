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

    //bool mode = NORMAL_MODE;
    //read Mode
    printStartText();

    mcpp::MinecraftConnection mc; 
    mc.doCommand("time set day"); 

    States curState = ST_Main;

    //State machine for menu 
    char getACSIImenu;
    std::string getStringmenu;
    int getMenuNum = 0;
    char getACSIImaze;
    std::string getStringmaze;
    int getMazeNum = 0;
    char getACSIIsolve; 
    std::string getStringsolve;      
    int getSolveNum = 0;

    int build_x = 0;
    int build_y = 0;
    int build_z = 0;
    int envLength = 0;
    int envWidth = 0;
    
    int check = 0;
    int check2 = 0;
    int main = 0;
    int num = 0;
     
    while (curState != ST_Exit)
    {
        while(main == 0){
            main = 0;
            num = 0;
            check2 = 0;
            //check = 0;
        if(curState == ST_Main){
            //MainMenu:
            
            while(check == 0){
            check = 0;
            num = 0;
            check2 = 0;
            printMainMenu();
            std::cin >> getStringmenu;
            if (getStringmenu.length() != 1){
                std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
                //goto MainMenu;
                check = 0;
            }
            else{
            getACSIImenu = getStringmenu[0];
            getMenuNum = int(getACSIImenu);
            if(getMenuNum == 49){
                //MazeMenu:
                while(check2 == 0){
                check2 = 0;
                printGenerateMazeMenu();
                std::cin >> getStringmaze;
                if (getStringmaze.length() != 1){
                std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                //goto MazeMenu;
                check2 = 0;
                }
                else{
                getACSIImaze = getStringmaze[0];
                getMazeNum = int(getACSIImaze);
                if (getMazeNum == 49){
                    std::cout << "Enter the basePoint of maze: " << std::endl;
                    std::cin >> build_x;
                    std::cin >> build_y;
                    std::cin >> build_z;

                    std::cout << "Enter the length and width of maze: " << std::endl;
                    std::cin >> envLength;
                    std::cin >> envWidth;

                    std::cout << "Enter the maze structure: " << std::endl;
                    char envStructure[envLength][envWidth];
                    char readChar;
                    for (int row = 0; row < envLength; row++) {
                        for (int col = 0; col < envWidth; col++) {
                            std::cin >> readChar;
                            envStructure[row][col] = readChar;
                            }
                            }    
                    std::cout << "Maze read successfully" << std::endl;
                    std::cout << "**Printing Maze**" << std::endl;
                    std::cout << "BasePoint: (" << build_x << ", " << build_y << ", " << build_z << ")" << std::endl;
                    std::cout << "Structure: " << std::endl;

                    for (int row = 0; row < envLength; row++) {
                        for (int col = 0; col < envWidth; col++) {
                            std::cout << envStructure[row][col];
                            }
                            std::cout << std::endl;
                            }
                    
                    std::cout << "**End Printing Maze**" << std::endl;
                    //goto MainMenu;
                    check2 = 1;
                    check = 0;
                }
                else if(getMazeNum == 50){
                    std::cout << "Enter the basePoint of maze: " << std::endl;
                    std::cin >> build_x;
                    std::cin >> build_y;
                    std::cin >> build_z;

                    std::cout << "Enter the length and width of maze: " << std::endl;
                    std::cin >> envLength;
                    std::cin >> envWidth;

                    std::cout << "Maze read successfully" << std::endl;
                    std::cout << "**Printing Maze**" << std::endl;
                    std::cout << "BasePoint: (" << build_x << ", " << build_y << ", " << build_z << ")" << std::endl;
                    std::cout << "Structure: " << std::endl;

                    char envStructure[envLength][envWidth];

                    for (int row = 0; row < envLength; row++) {
                        for (int col = 0; col < envWidth; col++) {
                            std::cout << envStructure[row][col];
                            }
                            std::cout << std::endl;
                            }
                    
                    std::cout << "**End Printing Maze**" << std::endl;
                    //goto MainMenu;
                    check2 = 1;
                    check = 0;


                    //TODO Generate Random Maze
                }
                else if(getMazeNum == 51){
                    //goto MainMenu;
                    check2 = 1;
                    check = 0;
                }
                else {
                    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                    //goto MazeMenu;
                    check2 = 0;
                }   
            } 
            }
            }
            else if(getMenuNum == 50){ 
                curState = ST_GetMaze;
                check = 1;
            }
            else if(getMenuNum == 51){
                curState = ST_SolveMaze;
                check = 1;
            }
            else if(getMenuNum == 52){
                curState = ST_Creators;
                check = 1;
            }
            else if(getMenuNum == 53){
                //TODO WorldCleaning code
                curState = ST_Exit;
                check = 1;
                main = 1;
            }
            // else if (getMenuNum != 1 && getMenuNum != 2 && getMenuNum != 3 && getMenuNum != 4 && getMenuNum != 5){
            //     std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
            //     //goto MainMenu;
            // }
        }
        }
        }
        else if(curState == ST_GetMaze){
            //TODO check if a maze already exists
            //TODO Teleport Player to the location
            //TODO flatten the terrain
            //TODO Make maze  
            //goto MainMenu;
            check = 0;
            curState = ST_Main;

        }
        else if(curState == ST_SolveMaze){
            //SolveMenu:
            while(num == 0){
                num = 0;
                printSolveMazeMenu();
                std::cin >> getStringsolve;
                if (getStringsolve.length() != 1){
                std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                //goto SolveMenu;
                num = 0;
                }
                else{
                getACSIIsolve = getStringsolve[0];
                getSolveNum = int(getACSIIsolve);
                if (getSolveNum == 49){
                    //TODO Solve Manually
                    //main = 0;
                    num = 1;
                    check = 0;
                    curState = ST_Main;
                    //check = 1;
                }
                else if(getSolveNum == 50){
                    //TODO show Escape Route
                    //main = 1;
                    num = 1;
                    check = 0;
                    curState = ST_Main;
                    //check = 1;
                }
                else if(getSolveNum == 51){
                    //goto MainMenu;
                    //main = 0;
                    num = 1;
                    check = 0;
                    curState = ST_Main;
                    //check = 1;
                } 
                else {
                    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                    //goto SolveMenu;
                    num = 0;
                }
        }
        }
        }
        else if(curState == ST_Creators){
            printTeamInfo();
            //goto MainMenu;
            //main = 0;
            check = 0;
            curState = ST_Main;
        }

    }

    }

    printExitMassage();


    return EXIT_SUCCESS;


    //checklist
    //mainmenu 1 2 3 4 5 else             // remaining : 1 , 2 , 3 , 5
    //1 generatemazemenu 1 2 3 else       // remaining : 2
    //2 buildmaze                         // remaining : all
    //3 solvemazemenu 1 2 3 else          // remaining : 1 and 2
    //4 teaminfo                          // remaining : done  .....................................
    //5 exit                              // remaining :worldcleaning



}
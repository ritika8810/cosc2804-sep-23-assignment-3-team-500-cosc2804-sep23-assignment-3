#include <iostream>

#include <mcpp/mcpp.h>

#include "menuUtils.h"
#include "Maze.h"
#include "Agent.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1
#define Option_1 49
#define Option_2 50
#define Option_3 51
#define Option_4 52
#define Option_5 53

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

    // Variables to check that input is firstly not a word and secondly not any character other than 1 2 3 4 or 5
    char Get_Ascii_Menu;
    std::string Get_String_Menu;
    int Get_Menu_Num = 0;
    char Get_Ascii_Maze;
    std::string Get_String_Maze;
    int Get_Maze_Num = 0;
    char Get_Ascii_Solve; 
    std::string Get_String_Solve;      
    int Get_Solve_Num = 0;


    // The input variables
    int build_x = 0;
    int build_y = 0;
    int build_z = 0;
    int Maze_Length = 0;
    int Maze_Width = 0;
    
    // The condition variables for while loops
    int MainMenu = 0;
    int MazeMenu = 0;
    int MainLoop = 0;
    int SolveMenu = 0;
    
    while (curState != ST_Exit)
    {
        while(MainLoop == 0)
        {
            SolveMenu = 0;
            MazeMenu = 0;

        if(curState == ST_Main)
        {

            while(MainMenu == 0)
            {
            SolveMenu = 0;
            MazeMenu = 0;
            printMainMenu();
            std::cin >> Get_String_Menu;
            if (Get_String_Menu.length() != 1)
            {
                std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
                MainMenu = 0;
            }
            else
            {
            Get_Ascii_Menu = Get_String_Menu[0];
            Get_Menu_Num = int(Get_Ascii_Menu);
            if(Get_Menu_Num == Option_1)
            {
                while(MazeMenu == 0)
                {
                printGenerateMazeMenu();
                std::cin >> Get_String_Maze;
                if (Get_String_Maze.length() != 1)
                {
                std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                MazeMenu = 0;
                }
                else
                {
                Get_Ascii_Maze = Get_String_Maze[0];
                Get_Maze_Num = int(Get_Ascii_Maze);
                if (Get_Maze_Num == Option_1)
                {
                    std::cout << "Enter the basePoint of maze: " << std::endl;
                    std::cin >> build_x;
                    std::cin >> build_y;
                    std::cin >> build_z;

                    std::cout << "Enter the length and width of maze: " << std::endl;
                    std::cin >> Maze_Length;
                    std::cin >> Maze_Width;

                    std::cout << "Enter the maze structure: " << std::endl;
                    char Maze_Structure[Maze_Length][Maze_Width];
                    char readChar;
                    for (int row = 0; row < Maze_Length; row++) 
                    {
                        for (int col = 0; col < Maze_Width; col++) 
                        {
                            std::cin >> readChar;
                            Maze_Structure[row][col] = readChar;
                            }
                            }    
                    std::cout << "Maze read successfully" << std::endl;
                    std::cout << "**Printing Maze**" << std::endl;
                    std::cout << "BasePoint: (" << build_x << ", " << build_y << ", " << build_z << ")" << std::endl;
                    std::cout << "Structure: " << std::endl;

                    for (int row = 0; row < Maze_Length; row++) 
                    {
                        for (int col = 0; col < Maze_Width; col++) 
                        {
                            std::cout << Maze_Structure[row][col];
                            }
                            std::cout << std::endl;
                            }
                    
                    std::cout << "**End Printing Maze**" << std::endl;
                    MazeMenu = 1;
                    MainMenu = 0;
                }
                else if(Get_Maze_Num == Option_2)
                {
                    std::cout << "Enter the basePoint of maze: " << std::endl;
                    std::cin >> build_x;
                    std::cin >> build_y;
                    std::cin >> build_z;

                    std::cout << "Enter the length and width of maze: " << std::endl;
                    std::cin >> Maze_Length;
                    std::cin >> Maze_Width;

                    std::cout << "Maze read successfully" << std::endl;
                    std::cout << "**Printing Maze**" << std::endl;
                    std::cout << "BasePoint: (" << build_x << ", " << build_y << ", " << build_z << ")" << std::endl;
                    std::cout << "Structure: " << std::endl;

                    char Maze_Structure[Maze_Length][Maze_Width];

                    for (int row = 0; row < Maze_Length; row++) 
                    {
                        for (int col = 0; col < Maze_Width; col++) 
                        {
                            std::cout << Maze_Structure[row][col];
                            }
                            std::cout << std::endl;
                            }
                    
                    std::cout << "**End Printing Maze**" << std::endl;
                    MazeMenu = 1;
                    MainMenu = 0;

                    //TODO Generate Random Maze

                }
                else if(Get_Maze_Num == Option_3)
                {
                    MazeMenu = 1;
                    MainMenu = 0;
                }
                else 
                {
                    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                    MazeMenu = 0;
                }   
            } 
            }
            }
            else if(Get_Menu_Num == Option_2)
            { 
                curState = ST_GetMaze;
                MainMenu = 1;
            }
            else if(Get_Menu_Num == Option_3)
            {
                curState = ST_SolveMaze;
                MainMenu = 1;
            }
            else if(Get_Menu_Num == Option_4)
            {
                curState = ST_Creators;
                MainMenu = 1;
            }
            else if(Get_Menu_Num == Option_5)
            {
                //TODO WorldCleaning code
                curState = ST_Exit;
                MainMenu = 1;
                MainLoop = 1;
            }
            else if (Get_Menu_Num != Option_1 && Get_Menu_Num != Option_2 && Get_Menu_Num != Option_3 && Get_Menu_Num != Option_4 && Get_Menu_Num != Option_5)
            {
                std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
                MainMenu = 0;
            }
        }
        }
        }
        else if(curState == ST_GetMaze)
        {
            //TODO check if a maze already exists
            //TODO Teleport Player to the location
            //TODO flatten the terrain
            //TODO Make maze  
            MainMenu = 0;
            curState = ST_Main;

        }
        else if(curState == ST_SolveMaze)
        {
            while(SolveMenu == 0)
            {
                printSolveMazeMenu();
                std::cin >> Get_String_Solve;
                if (Get_String_Solve.length() != 1)
                {
                std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                SolveMenu = 0;
                }
                else
                {
                Get_Ascii_Solve = Get_String_Solve[0];
                Get_Solve_Num = int(Get_Ascii_Solve);
                if (Get_Solve_Num == Option_1)
                {
                    //TODO Solve Manually
                    SolveMenu = 1;
                    MainMenu = 0;
                    curState = ST_Main;
                }
                else if(Get_Solve_Num == Option_2)
                {
                    //TODO show Escape Route
                    SolveMenu = 1;
                    MainMenu = 0;
                    curState = ST_Main;
                }
                else if(Get_Solve_Num == Option_3)
                {
                    SolveMenu = 1;
                    MainMenu = 0;
                    curState = ST_Main;
                } 
                else 
                {
                    std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                    SolveMenu = 0;
                }
        }
        }
        }
        else if(curState == ST_Creators)
        {
            printTeamInfo();
            MainMenu = 0;
            curState = ST_Main;
        }

    }

    }

    printExitMassage();


    return EXIT_SUCCESS;


    //checklist
    //mainmenu 1 2 3 4 5 else             // remaining : 1 , 2 , 3 , 5
    //1 generatemazemenu 1 2 3 else       // remaining : 1 and 2
    //2 buildmaze                         // remaining : 1
    //3 solvemazemenu 1 2 3 else          // remaining : 1 and 2
    //5 exit                              // remaining :worldcleaning



}
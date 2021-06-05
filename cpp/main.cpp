#include <iostream>
#include "maze.h"
#include <stdlib.h>



int main(int argc, char **argv)
{
     
    printf(NC "Welcome to Maze project :  " CYN":)\n");
    
    int w{} ,l{} ;
    int startx{} ,starty{} ,endx{} ,endy{};
    char db{} , yn{};
    // Maze::Cell n(1,2);
    // std::cout << n.getcolumn() << "," << n.getrow() <<std::endl;
    printf(NC"please enter your dimensions, first width : \n");
    // std::cout << "please enter your dimensions, first width : \n";
    std::cin >> w ;
    printf(NC"now length : \n");
    std::cin >>  l;
    Maze a(w,l);
    a.Show_maze();
    printf(GRN"Start Point -> x:\n" );
    std::cin >> startx ;
    if (startx > l -1){
        std::cout << "your number was out of range !!!!! \n";
        return 0;
    }
    printf(GRN"Start Point -> y:\n" );
    std::cin >> starty ;
    if (starty > w -1)
    {
        std::cout << "your number was out of range !!!!! \n";
        return 0;
    }
    printf(RED"End Point -> x:\n" );
    std::cin >> endx ;
    if (endx > l -1)
    {
        std::cout << "your number was out of range !!!!! \n";
        return 0;
    }
    printf(RED"End Point -> y:\n" );
    std::cin >> endy ;
    if (endy > w -1)
    {
        std::cout << "your number was out of range !!!!! \n";
        return 0;
    }
    std::shared_ptr<Maze::Cell> startp {a.numtoCell(startx,starty)};
    std::shared_ptr<Maze::Cell> endp {a.numtoCell(endx,endy)};
    a.bfs_search(startp , endp);
    a.dfs_search(startp ,endp);
    printf(NC"for " CYN"BFS " NC"enter " CYN"b" NC", for " CYN"DFS " NC"enter" CYN" d" NC": \n" );
    std::cin >> db ;
    if (db == 'd')
    {
        a.Show_solved_maze(a.DFS_cells);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else if (db == 'b')
    {
        a.Show_solved_maze(a.BFS_cells);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    if(db == 'd')
    {
        printf(NC"Show" CYN" BFS " NC" y or n ? :\n");
        std::cin >> yn ;
        if (yn == 'y')
        {
            a.Show_solved_maze(a.BFS_cells);
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        else if (yn == 'n')
        {
            printf(CYN"THANKS!!!!!!!");
        }
    }
    else if (db == 'b'){
        printf(NC"Show" CYN" DFS " NC" y or n ? :\n");
        std::cin >> yn ;
        if (yn == 'y')
        {
            a.Show_solved_maze(a.DFS_cells);
        }
        else if (yn == 'n')
        {
            printf(CYN"THANKS!!!!!!!");
        }
    }
    // std::shared_ptr<Maze::Cell> q {a.numtoCell(0,1)};
    // std::shared_ptr<Maze::Cell> q1 {a.numtoCell(2,4)};
    // a.bfs_search(q,q1);
    // std::cout << q->getrow() << "," << q->getcolumn() << "  !\n";
    // std::cout << q1->getrow() << "," << q1->getcolumn() << "  !\n";
    // a.dfs_search(q,q1);
    // int z{};
    // for(auto i : a.BFS_cells)
    // {
    //     z++;
    //     std::cout << z << "   :    " <<i->getrow() << "," << i->getcolumn() << "  !\n";
    // }
    
    return 0;

}

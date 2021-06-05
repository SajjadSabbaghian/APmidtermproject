#include "maze.h"
#include <iostream>


Maze::Cell::Cell(size_t _row, size_t _column)
:row{_row},
column{_column}
{
    // std::cout << "constructor of cell is completed!!!" << std::endl;
}




Maze::Maze(size_t _width, size_t _height)
:width{_width},
height{_height}
{
    mat = this->Make_matrix() ;
    for (size_t i{} ; i < height ; i++)
    {
        std::vector<std::shared_ptr<Cell>> row{};
        for(size_t j{}; j < width ; j++)
        {
            auto c{std::make_shared<Maze::Cell>(i,j)}; ;
            c->way = mat[i][j] ; 
            row.push_back(c);

        }
        cellsOfMaze.push_back(row);
    }
    this ->Make_connection();
    // std::cout << cellsOfMaze[height-1][width-1]->leftneighbor->getcolumn() << "= 4 ," <<cellsOfMaze[height-1][width-1]->leftneighbor->getrow() << "= 4\n"<<cellsOfMaze[height-1][width-1]->topneighbor->getcolumn() << "= 5 ," <<cellsOfMaze[height-1][width-1]->topneighbor->getrow() << "= 3\n";
    // std::cout << "Maze constructor is completed!!!!!" <<std::endl;
}



Matrix Maze::Make_matrix()
{
    Matrix maze_maker{};
    for(size_t i{} ; i < height ; i++ )
    {
        std::vector<int> row{};
        for (size_t j{} ; j < width ; j++)
        {
            int rand01 { rand() % 2};
            row.push_back(rand01);
            if(rand() % 2)
            {
                row[j] = 0;
            }
        }
        maze_maker.push_back(row);
    }

    // for(size_t i{} ; i < height ; i++ )
    // {
        
    //     for (size_t j{} ; j < width ; j++)
    //     {
    //         std::cout << maze_maker[i][j] << " " ;
    //     }
    //     std::cout <<std::endl;
    // }
    
    return maze_maker;
}



void Maze::Make_connection()
{
    //make connection of first row :
    if(!(cellsOfMaze[0][1]->way)){
       cellsOfMaze[0][0]->rightneighbor=cellsOfMaze[0][1];
    }
    if(!(cellsOfMaze[1][0]->way)){
       cellsOfMaze[0][0]->downneighbor=cellsOfMaze[1][0];
    }
    if(!(cellsOfMaze[0][width-2]->way)){
       cellsOfMaze[0][width-1]->leftneighbor=cellsOfMaze[0][width-2];
    }
    if(!(cellsOfMaze[1][width-1]->way)){
       cellsOfMaze[0][width-1]->downneighbor=cellsOfMaze[1][width-1];
    }
    // std ::cout << "safkngjkrnkjnrganrgj\n";
    for(size_t i{1}; i< width-1 ; i++)
    {
        if(!(cellsOfMaze[1][i]->way))
        {
            cellsOfMaze[0][i]->downneighbor = cellsOfMaze[1][i];
        }
        if(!(cellsOfMaze[0][i+1]->way))
        {
            cellsOfMaze[0][i]->rightneighbor = cellsOfMaze[0][i+1];
        }
        if(!(cellsOfMaze[0][i-1]->way))
        {
            cellsOfMaze[0][i]->leftneighbor = cellsOfMaze[0][i-1];
        }

    }
    // std ::cout << "safkngjkrnkjnrganrgj2\n";
    //make connection of first column :
     for(size_t i{1} ; i < height-1 ; i++)
     {
         if(!(cellsOfMaze[i-1][0]->way))
         {
             cellsOfMaze[i][0]->topneighbor = cellsOfMaze[i-1][0];
         }
         if(!(cellsOfMaze[i][1]->way))
         {
             cellsOfMaze[i][0]->rightneighbor = cellsOfMaze[i][1];
         }
         if(!(cellsOfMaze[i+1][0]->way))
         {
             cellsOfMaze[i][0]->downneighbor = cellsOfMaze[i+1][0];
         }
     }
    // std ::cout << "safkngjkrnkjnrganrgj3\n";
     // make connection of last column
     for(size_t i{1} ; i < height-1 ; i++)
     {
         if(!(cellsOfMaze[i-1][width-1]->way))
         {
             cellsOfMaze[i][width-1]->topneighbor = cellsOfMaze[i-1][width-1];
         }
         if(!(cellsOfMaze[i][width-2]->way))
         {
             cellsOfMaze[i][width-1]->leftneighbor = cellsOfMaze[i][width-2];
         }
         if(!(cellsOfMaze[i+1][width-1]->way))
         {
             cellsOfMaze[i][width-1]->downneighbor = cellsOfMaze[i+1][width-1];
         }
     }
    //  std ::cout << "safkngjkrnkjnrganrgj4\n";
     //make connection of last row 
     if(!(cellsOfMaze[height-1][1]->way)){
       cellsOfMaze[height-1][0]->rightneighbor=cellsOfMaze[height-1][1];
    }
    if(!(cellsOfMaze[height-2][0]->way)){
       cellsOfMaze[height-1][0]->topneighbor=cellsOfMaze[height-2][0];
    }
    if(!(cellsOfMaze[height-1][width-2]->way)){
       cellsOfMaze[height-1][width-1]->leftneighbor=cellsOfMaze[height-1][width-2];
    }
    if(!(cellsOfMaze[height-2][width-1]->way)){
       cellsOfMaze[height-1][width-1]->topneighbor=cellsOfMaze[height-2][width-1];
    }

    for(size_t i{1}; i< width-1 ; i++)
    {
        if(!(cellsOfMaze[height-2][i]->way))
        {
            cellsOfMaze[height-1][i]->topneighbor = cellsOfMaze[height-2][i];
        }
        if(!(cellsOfMaze[height-1][i+1]->way))
        {
            cellsOfMaze[height-1][i]->rightneighbor = cellsOfMaze[height-1][i+1];
        }
        if(!(cellsOfMaze[height-1][i-1]->way))
        {
            cellsOfMaze[height-1][i]->leftneighbor = cellsOfMaze[height-1][i-1];
        }

    }
    // std ::cout << "safkngjkrnkjnrganrgj5\n";
    //make connection of the others cell 

    for (size_t i{1} ; i < height-1 ; i++)
    {
        for(size_t j{1}; j < width-1; j++ )
        {
            if(!(cellsOfMaze[i][j-1]->way))
            {
                cellsOfMaze[i][j]->leftneighbor = cellsOfMaze[i][j-1];
            }
            if(!(cellsOfMaze[i][j+1]->way))
            {
                cellsOfMaze[i][j]->rightneighbor = cellsOfMaze[i][j+1];
                
            }
            if(!(cellsOfMaze[i+1][j]->way))
            {
                cellsOfMaze[i][j]->downneighbor = cellsOfMaze[i+1][j];
                
            }
            if(!(cellsOfMaze[i-1][j]->way))
            {
                cellsOfMaze[i][j]->topneighbor = cellsOfMaze[i-1][j];
                
            }
            
        }
    }
    
    // std ::cout << "safkngjkrnkjnrganrgj6\n";
    for(size_t i{} ; i < height ; i++){
        for(size_t j{} ; j < width; j++){
            cellsOfMaze[i][j]->children.push_back(cellsOfMaze[i][j]->rightneighbor);
            cellsOfMaze[i][j]->children.push_back(cellsOfMaze[i][j]->topneighbor);
            cellsOfMaze[i][j]->children.push_back(cellsOfMaze[i][j]->leftneighbor);
            cellsOfMaze[i][j]->children.push_back(cellsOfMaze[i][j]->downneighbor);
        }
    }

}

std::shared_ptr<Maze::Cell> Maze::numtoCell(size_t row,size_t column)
{
    return cellsOfMaze[row][column];
}


void Maze::dfs_search(std::shared_ptr<Cell> start ,std::shared_ptr<Cell> end)
{
    DFS_cells.push_back(start);
    // std::cout << start->getrow() << "," << start->getcolumn() << "  !\n";
    // std::cout <<"_________________\n" ;
    for (auto i : start->children)
    {
        if(!find_end_dfs){
        
        if (i != nullptr && i->dfs_visited == false && i !=end )
        {
            i->dfs_visited = true ;
            this->dfs_search(i,end);
        }

        if (i == end)
        {
            // std::cout << i->getrow() << "," << i->getcolumn() << "  !\n";
            DFS_cells.push_back(i);
            find_end_dfs = true;
            return ;
        }
        }
        
    }
    if(!find_end_dfs)
    {
    std::vector<std::shared_ptr<Cell>>::iterator it;
    for(it = DFS_cells.begin() ; it != DFS_cells.end() ;++it)
    {
        if (*it == start)
        {
            // std::cout <<"erase : "<< (*it)->getrow() << "," << (*it)->getcolumn() << "!\n";

            DFS_cells.erase(it);
            break;
        }
    }
    }

}




void Maze::bfs_start(std::shared_ptr<Cell> start ,std::shared_ptr<Cell> end)
{
    // BFS_cells.push_back(start);
    // std::cout << start->getrow() << "," << start->getcolumn() << "  !\n";
    // std::cout <<"_________________\n" ;
    start ->bfs_visited = true;
    std::vector<std::shared_ptr<Cell>> row{};
    for (auto i : start ->children)
    {
        if (i && i->bfs_visited != true)
        {
           i->bfs_visited = true;
           row.push_back(i);
        //    std::cout << i->getrow() << "," << i->getcolumn() << "  !\n";
        //    std::cout <<"_________________\n" ;
        }
        if(i == end)
        {
            find_end_bfs =true;
            break;
        }
    }
    level_bfs.push_back(row);
}


void Maze::child(std::vector<std::shared_ptr<Cell>> p , std::shared_ptr<Maze::Cell> end)
{
    if(!find_end_bfs){
    std::vector<std::shared_ptr<Maze::Cell>> a {};
    for (auto x : p){
    if(x->rightneighbor && x->rightneighbor->bfs_visited != true)
    {
        a.push_back(x->rightneighbor);
        x->rightneighbor->bfs_visited = true;
        if (x->rightneighbor == end)
        {
        find_end_bfs = true;
        break;
        }
    }
    if(x->leftneighbor && x->leftneighbor->bfs_visited != true)
    {
        a.push_back(x->leftneighbor );
        x->leftneighbor->bfs_visited = true;
        if (x->leftneighbor == end)
        {
        find_end_bfs = true;
        break;
        }
    }
    if(x->topneighbor  && x->topneighbor->bfs_visited != true)
    {
        a.push_back(x->topneighbor);
        x->topneighbor->bfs_visited = true;
        if (x->topneighbor == end)
        {
        find_end_bfs = true;
        break;
        }
    }

    if(x->downneighbor  && x->downneighbor->bfs_visited != true)
    {
        a.push_back(x->downneighbor);
        x->downneighbor->bfs_visited = true;
        if (x->downneighbor == end){
        find_end_bfs = true;
        break;
        }
    }

    }
     
    // for (auto i : a)
    // {
    //     std::cout << i->getrow() << "," << i->getcolumn() << "!\n";
    // }
    // std::cout << "_______------_______\n";
    level_bfs.push_back(a);
    if (a.size() != 0) {
    this->child(a,end);
    }
    }
}

// std::list<std::shared_ptr<Maze::Cell>> Maze::backtrack(std::vector<std::shared_ptr<Cell>> x , std::shared_ptr<Cell> y)
// {
//     for (auto i : x)
//     {
//         if(y == i)
//         {
//             return i->children;
//         }
//     }
// }

void Maze::bfs_search(std::shared_ptr<Cell> start ,std::shared_ptr<Cell> end)
{
  this ->bfs_start(start , end);
  if(level_bfs[0].size() != 0)
  {
    this->child(level_bfs[0],end);
    std::vector<std::vector<std::shared_ptr<Cell>>>::reverse_iterator it;
    std::shared_ptr<Cell> buf{end};
// //   std::list<std::shared_ptr<Cell>> bufvec{end->children};
    BFS_cells.push_front(buf);
    // std::cout << "size of level : " << level_bfs.size() <<std::endl;
    for(it = level_bfs.rbegin() ; it != level_bfs.rend() ; ++it)
    {
      bool x{false};
      for(auto i : buf->children )
      {
         for(auto j : *it)
         {
            if(i == j )
            {
                buf = i;
                BFS_cells.push_front(i);
                x=true;
                break;
            }
        } 
        if (x)
        {
            break;
        }
      }
   }
   BFS_cells.push_front(start);

  }
}

void Maze::Show_maze()
{
    for(size_t i{} ; i < height ; i++ )
    {
        
        for (size_t j{} ; j < width ; j++)
        {
            if (mat[i][j] == 1){
            printf(CYN"1 ");
            }
            else{
                printf(NC"0 ");
            }
        }
        std::cout <<std::endl;
    }
}

void Maze::Show_solved_maze(std::vector<std::shared_ptr<Maze::Cell>> z)
{
    if(z.size() > 0){
    for(size_t i{} ; i < height ; i++ )
    {
        
        for (size_t j{} ; j < width ; j++)
        {
            if (mat[i][j] == 1){
            printf(CYN"1 ");
            continue;
            }
            else {
                bool aa{false};
                for(auto p : z)
                {
                    if(p->getrow() == i && p->getcolumn() ==j)
                    {
                        printf(GRN"0 ");
                        aa = true;
                        break;
                    }
                }
                if(!aa)
                printf(NC"0 ");
            }
            
        }
        std::cout <<std::endl;

    
    }
    for (auto k : z){
        std::cout << "--> (" << k->getrow() << "," << k->getcolumn() << ") \n";
    }
    }
    else{
        std::cout << "There is No way from Start and end point :( !!!!!!!\n";
    }
}


void Maze::Show_solved_maze(std::list<std::shared_ptr<Maze::Cell>> z)
{
    if(z.size() > 2 ){
        if(z.size()== 2)
        {
            bool x{true};
            for (auto q : (*z.begin())->children)
            {
                if (q == (*(z.begin()++ ))){
                   x= false;
                }
                
            }
            if(x)
            {
               std::cout << "There is No way from Start and end point :( !!!!!!!\n";
                return;
            }
         }
        
    for(size_t i{} ; i < height ; i++ )
    {
        
        for (size_t j{} ; j < width ; j++)
        {
            if (mat[i][j] == 1){
            printf(CYN"1 ");
            continue;
            }
            else {
                bool aa{false};
                for(auto p : z)
                {
                    if(p->getrow() == i && p->getcolumn() ==j)
                    {
                        printf(GRN"0 ");
                        aa = true;
                        break;
                    }
                }
                if(!aa)
                printf(NC"0 ");
            }
            
        }
        std::cout <<std::endl;
    }
    }
    else{
        std::cout << "There is No way from Start and end point :( !!!!!!!\n";
    }

}
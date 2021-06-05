#ifndef Maze_H
#define Maze_H

#include<list>
#include<vector>
#include<memory>
#include<cstdio>
using Matrix = std::vector<std::vector<int>>;

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Maze{

    public:
        class Cell{
            public:
                std::list<std::shared_ptr<Cell>> children{};  
                // std::shared_ptr<Cell*> parent;
                std::shared_ptr<Cell> leftneighbor{nullptr};
                std::shared_ptr<Cell> rightneighbor{nullptr};
                std::shared_ptr<Cell> topneighbor{nullptr};
                std::shared_ptr<Cell> downneighbor{nullptr};
                Cell(size_t _row, size_t _column);
                size_t getrow(){return row;}
                size_t getcolumn(){return column;} 
        
                // int id ;
                bool way ;
                bool dfs_visited{false};
                bool bfs_visited{false};
        private:
            size_t row ;
            size_t column ;


        };

        Maze(size_t _width, size_t _height);
        Matrix Make_matrix();
        std::vector<std::vector<std::shared_ptr<Cell>>> cellsOfMaze;
        void Make_connection();
        std::shared_ptr<Maze::Cell> numtoCell(size_t row,size_t column);
        void dfs_search(std::shared_ptr<Cell> start ,std::shared_ptr<Cell> end);
        std::vector<std::shared_ptr<Cell>> DFS_cells;
        bool find_end_dfs{false};
        void bfs_start(std::shared_ptr<Cell> start ,std::shared_ptr<Cell> end);
        void bfs_search(std::shared_ptr<Cell> start ,std::shared_ptr<Cell> end);
        std::list<std::shared_ptr<Cell>> BFS_cells;
        void child(std::vector<std::shared_ptr<Cell>> p, std::shared_ptr<Maze::Cell> end);
        std::vector<std::vector<std::shared_ptr<Cell>>> level_bfs;
        bool find_end_bfs{false};
        // std::list<std::shared_ptr<Cell>> backtrack(std::vector<std::shared_ptr<Cell>> x , std::shared_ptr<Cell> y);
        void Show_maze();
        Matrix mat{};
        void Show_solved_maze(std::vector<std::shared_ptr<Cell>> z);
        void Show_solved_maze(std::list<std::shared_ptr<Cell>> z);
        


    private:
        size_t width ;
        size_t height ;

};


#endif
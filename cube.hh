#ifndef CUBE_H
#define CUBE_H


#include <bits/stdc++.h>
#include <string>
#include <time.h>

using namespace std;

class Cube{
    public:

        int pieces[6][9];
        int fitness;
        string solver_alg;
        string scramble_alg;
      
        map<string, function<string(int (*)[9])>> moves_map;
        Cube(){
            solver_alg = "";
            scramble_alg = "";
            fitness = 1000;
            for(int c = 0; c < 6; c++)
                for(int p = 0; p < 9; p++){
                    pieces[c][p] = c;
                }
            initMapMoves();
        }

        void ApplyMove(string move, int type);
        void scramble(int moves);
        void rnd_permutation(int type);
        void rnd_simple_move(int type);
        void rnd_rotation(int type);
        void rnd_orientation(int type);
        void print();
        string get_algorithm();
        string get_scramble();
        int is_solved();
        void calculate_fitness();
        Cube *return_copy();
        int return_size_solution();


    private:
        void initMapMoves();
};

#endif
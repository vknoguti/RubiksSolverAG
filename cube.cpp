#include <bits/stdc++.h>
#include <string>
#include <time.h>
#include "cube.hh"

using namespace std;


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[38;5;226m"//"\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White *

#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define ORANGE  "\033[38;5;214m"


void SwitchColors(int *oldPiece, int *newPiece){
    int temp = *oldPiece;
    *oldPiece = *newPiece;
    *newPiece = temp;
}

string U(int (*actualCube)[9]){

    SwitchColors(&actualCube[1][0], &actualCube[4][0]);
    SwitchColors(&actualCube[1][0], &actualCube[3][0]);
    SwitchColors(&actualCube[1][0], &actualCube[2][0]);

    SwitchColors(&actualCube[1][1], &actualCube[4][1]);
    SwitchColors(&actualCube[1][1], &actualCube[3][1]);
    SwitchColors(&actualCube[1][1], &actualCube[2][1]);

    SwitchColors(&actualCube[1][2], &actualCube[4][2]);
    SwitchColors(&actualCube[1][2], &actualCube[3][2]);
    SwitchColors(&actualCube[1][2], &actualCube[2][2]);


    //Switch colors of Top Face
    SwitchColors(&actualCube[5][0], &actualCube[5][2]);
    SwitchColors(&actualCube[5][0], &actualCube[5][8]);
    SwitchColors(&actualCube[5][0], &actualCube[5][6]);

    SwitchColors(&actualCube[5][1], &actualCube[5][5]);
    SwitchColors(&actualCube[5][1], &actualCube[5][7]);
    SwitchColors(&actualCube[5][1], &actualCube[5][3]);
    return "U";
}

string U2(int (*actualCube)[9]){
    U(actualCube); 
    U(actualCube);
    return "U2";
}

string U_(int (*actualCube)[9]){
    U2(actualCube);
    U(actualCube);
    return "U_";
}

string R(int (*actualCube)[9]){
    SwitchColors(&actualCube[1][2], &actualCube[5][2]);
    SwitchColors(&actualCube[1][2], &actualCube[3][6]);
    SwitchColors(&actualCube[1][2], &actualCube[0][2]);

    SwitchColors(&actualCube[1][5], &actualCube[5][5]);
    SwitchColors(&actualCube[1][5], &actualCube[3][3]);
    SwitchColors(&actualCube[1][5], &actualCube[0][5]);

    SwitchColors(&actualCube[1][8], &actualCube[5][8]);
    SwitchColors(&actualCube[1][8], &actualCube[3][0]);
    SwitchColors(&actualCube[1][8], &actualCube[0][8]);

    //Switch colors of Right Face
    SwitchColors(&actualCube[2][0], &actualCube[2][2]);
    SwitchColors(&actualCube[2][0], &actualCube[2][8]);
    SwitchColors(&actualCube[2][0], &actualCube[2][6]);

    SwitchColors(&actualCube[2][1], &actualCube[2][5]);
    SwitchColors(&actualCube[2][1], &actualCube[2][7]);
    SwitchColors(&actualCube[2][1], &actualCube[2][3]);
    return "R";
}

string R2(int (*actualCube)[9]){
    R(actualCube);
    R(actualCube);
    return "R2";
}

string R_(int (*actualCube)[9]){
    R2(actualCube);
    R(actualCube);
    return "R_";
}

string L(int (*actualCube)[9]){
    SwitchColors(&actualCube[1][0], &actualCube[0][0]);
    SwitchColors(&actualCube[1][0], &actualCube[3][8]);
    SwitchColors(&actualCube[1][0], &actualCube[5][0]);

    SwitchColors(&actualCube[1][3], &actualCube[0][3]);
    SwitchColors(&actualCube[1][3], &actualCube[3][5]);
    SwitchColors(&actualCube[1][3], &actualCube[5][3]);

    SwitchColors(&actualCube[1][6], &actualCube[0][6]);
    SwitchColors(&actualCube[1][6], &actualCube[3][2]);
    SwitchColors(&actualCube[1][6], &actualCube[5][6]);


    //Switch colors of Left Face
    SwitchColors(&actualCube[4][0], &actualCube[4][2]);
    SwitchColors(&actualCube[4][0], &actualCube[4][8]);
    SwitchColors(&actualCube[4][0], &actualCube[4][6]);

    SwitchColors(&actualCube[4][1], &actualCube[4][5]);
    SwitchColors(&actualCube[4][1], &actualCube[4][7]);
    SwitchColors(&actualCube[4][1], &actualCube[4][3]);
    return "L";

}

string L2(int (*actualCube)[9]){
    L(actualCube);
    L(actualCube);
    return "L2";
}

string L_(int (*actualCube)[9]){
    L(actualCube);
    L2(actualCube);
    return "L_";
}

string D(int (*actualCube)[9]){
    SwitchColors(&actualCube[1][6], &actualCube[2][6]);
    SwitchColors(&actualCube[1][6], &actualCube[3][6]);
    SwitchColors(&actualCube[1][6], &actualCube[4][6]);

    SwitchColors(&actualCube[1][7], &actualCube[2][7]);
    SwitchColors(&actualCube[1][7], &actualCube[3][7]);
    SwitchColors(&actualCube[1][7], &actualCube[4][7]);

    SwitchColors(&actualCube[1][8], &actualCube[2][8]);
    SwitchColors(&actualCube[1][8], &actualCube[3][8]);
    SwitchColors(&actualCube[1][8], &actualCube[4][8]);

    //Switch colors of Down Face
    SwitchColors(&actualCube[0][0], &actualCube[0][2]);
    SwitchColors(&actualCube[0][0], &actualCube[0][8]);
    SwitchColors(&actualCube[0][0], &actualCube[0][6]);

    SwitchColors(&actualCube[0][1], &actualCube[0][5]);
    SwitchColors(&actualCube[0][1], &actualCube[0][7]);
    SwitchColors(&actualCube[0][1], &actualCube[0][3]);
    return "D";
}

string D2(int (*actualCube)[9]){
    D(actualCube);
    D(actualCube);
    return "D2";
}

string D_(int (*actualCube)[9]){
    D2(actualCube);
    D(actualCube);
    return "D_";
}

string F(int (*actualCube)[9]){

    SwitchColors(&actualCube[5][6], &actualCube[2][0]);
    SwitchColors(&actualCube[5][6], &actualCube[0][2]);
    SwitchColors(&actualCube[5][6], &actualCube[4][8]);

    SwitchColors(&actualCube[5][7], &actualCube[2][3]);
    SwitchColors(&actualCube[5][7], &actualCube[0][1]);
    SwitchColors(&actualCube[5][7], &actualCube[4][5]);

    SwitchColors(&actualCube[5][8], &actualCube[2][6]);
    SwitchColors(&actualCube[5][8], &actualCube[0][0]);
    SwitchColors(&actualCube[5][8], &actualCube[4][2]);


    //Switch colors of Front Face
    SwitchColors(&actualCube[1][0], &actualCube[1][2]);
    SwitchColors(&actualCube[1][0], &actualCube[1][8]);
    SwitchColors(&actualCube[1][0], &actualCube[1][6]);

    SwitchColors(&actualCube[1][1], &actualCube[1][5]);
    SwitchColors(&actualCube[1][1], &actualCube[1][7]);
    SwitchColors(&actualCube[1][1], &actualCube[1][3]);
    return "F";
}

string F2(int (*actualCube)[9]){
    F(actualCube);
    F(actualCube);
    return "F2";
}

string F_(int (*actualCube)[9]){
    F2(actualCube);
    F(actualCube);
    return "F_";
}

string B(int (*actualCube)[9]){

    SwitchColors(&actualCube[5][0], &actualCube[4][6]);
    SwitchColors(&actualCube[5][0], &actualCube[0][8]);
    SwitchColors(&actualCube[5][0], &actualCube[2][2]);

    SwitchColors(&actualCube[5][1], &actualCube[4][3]);
    SwitchColors(&actualCube[5][1], &actualCube[0][7]);
    SwitchColors(&actualCube[5][1], &actualCube[2][5]);

    SwitchColors(&actualCube[5][2], &actualCube[4][0]);
    SwitchColors(&actualCube[5][2], &actualCube[0][6]);
    SwitchColors(&actualCube[5][2], &actualCube[2][8]);

    //Switch colors of Back Face
    SwitchColors(&actualCube[3][0], &actualCube[3][2]);
    SwitchColors(&actualCube[3][0], &actualCube[3][8]);
    SwitchColors(&actualCube[3][0], &actualCube[3][6]);

    SwitchColors(&actualCube[3][1], &actualCube[3][5]);
    SwitchColors(&actualCube[3][1], &actualCube[3][7]);
    SwitchColors(&actualCube[3][1], &actualCube[3][3]);
    return "B";
}

string B2(int (*actualCube)[9]){
    B(actualCube);
    B(actualCube);
    return "B2";
}

string B_(int (*actualCube)[9]){
    B2(actualCube);
    B(actualCube);
    return "B_";
}

string M(int (*actualCube)[9]){
    SwitchColors(&actualCube[1][1], &actualCube[0][1]);
    SwitchColors(&actualCube[1][1], &actualCube[3][7]);
    SwitchColors(&actualCube[1][1], &actualCube[5][1]);

    SwitchColors(&actualCube[1][4], &actualCube[0][4]);
    SwitchColors(&actualCube[1][4], &actualCube[3][4]);
    SwitchColors(&actualCube[1][4], &actualCube[5][4]);

    SwitchColors(&actualCube[1][7], &actualCube[0][7]);
    SwitchColors(&actualCube[1][7], &actualCube[3][1]);
    SwitchColors(&actualCube[1][7], &actualCube[5][7]);
    return "M";
}

string M2(int (*actualCube)[9]){
    M(actualCube);
    M(actualCube);
    return "M2";
}

string M_(int (*actualCube)[9]){
    M2(actualCube);
    M(actualCube);
    return "M_";
}

string E(int (*actualCube)[9]){
    SwitchColors(&actualCube[1][3], &actualCube[2][3]);
    SwitchColors(&actualCube[1][3], &actualCube[3][3]);
    SwitchColors(&actualCube[1][3], &actualCube[4][3]);

    SwitchColors(&actualCube[1][4], &actualCube[2][4]);
    SwitchColors(&actualCube[1][4], &actualCube[3][4]);
    SwitchColors(&actualCube[1][4], &actualCube[4][4]);

    SwitchColors(&actualCube[1][5], &actualCube[2][5]);
    SwitchColors(&actualCube[1][5], &actualCube[3][5]);
    SwitchColors(&actualCube[1][5], &actualCube[4][5]);
    return "E";
}

string E2(int (*actualCube)[9]){
    E(actualCube);
    E(actualCube);
    return "E2";
}

string E_(int (*actualCube)[9]){
    E2(actualCube);
    E(actualCube);
    return "E_";
}

string X(int (*actualCube)[9]){
    M_(actualCube);
    L_(actualCube);
    R(actualCube);
    return "X";
}

string X2(int (*actualCube)[9]){
    X(actualCube);
    X(actualCube);
    return "X2";
}

string X_(int (*actualCube)[9]){
    X2(actualCube);
    X(actualCube);
    return "X_";
}

string Y(int (*actualCube)[9]){
    U(actualCube);
    D_(actualCube);
    E_(actualCube);
    return "Y";
}

string Y2(int (*actualCube)[9]){
    Y(actualCube);
    Y(actualCube);
    return "Y2";
}

string Y_(int (*actualCube)[9]){
    Y2(actualCube);
    Y(actualCube);
    return "Y_";
}

string Z(int (*actualCube)[9]){
    X(actualCube);
    Y(actualCube);
    X_(actualCube);
    return "Z";
}

string Z2(int (*actualCube)[9]){
    Z(actualCube);
    Z(actualCube);
    return "Z2";
}

string Z_(int (*actualCube)[9]){
    Z2(actualCube);
    Z(actualCube);
    return "Z_";
}


using CallbackFunction = string (*)(int(*)[9]);
vector<vector <CallbackFunction>> permutations = {
    //Permutate Two edges
    {&F_, &L_, &B_, &R_, &U_, &R, &U_, &B, &L, &F, &R, &U, &R_, &U},
    //Permutate Two edges
    {&F, &R, &B, &L, &U, &L_, &U, &B_, &R_, &F_, &L_, &U_, &L, &U_, &L, &U_},
    //Permutate Two corners
    {&U2, &B, &U2, &B_, &R2, &F, &R_, &F_, &U2, &F_, &U2, &F, &R_},
    //Permutate Three corners
    {&U2, &R, &U2, &R_, &F2, &L, &F_, &L_, &U2, &L_, &U2, &L, &F},
    //Permutate Three centers
    {&U_, &B2, &D2, &L_, &F2, &D2, &B2, &R_, &U_},
    //Permutate Three centers
    {&U, &B2, &D2, &R, &F2, &D2, &B2, &L, &U},

    //Two edges and two corners
    {&D_, &R_, &D, &R2, &U_, &R, &B2, &L, &U_, &L_, &B2, &U, &R2},
    {&D, &L, &D_, &L2, &U, &L_, &B2, &R_, &U, &R, &B2, &U_, &L2},

    //PLL 
    {&R_, &U, &L_, &U2, &R, &U_, &L, &R_, &U, &L_, &U2, &R, &U_, &L, &U_},
    //PLL inversa
    {&L, &U_, &R, &U2, &L_, &U, &R_, &L, &U_, &R, &U2, &L_, &U, &R_, &U},
    
    //Permutate Three corners
    {&F_, &U, &B, &U_, &F, &U, &B_, &U_},
    //Clock-wise
    {&F, &U_, &B_, &U, &F_, &U_, &B, &U},

    //Permutate Three edges
    {&L_, &U2, &L, &R_, &F2, &R},
    {&R_, &U2, &R, &L_, &B2, &L},

    //PLL H
    {&M2, &U, &M2, &U2, &M2, &U, &M2}
};
vector <CallbackFunction> rotations = {&X, &X2, &X_, &Y, &Y2, &Y_};
vector <CallbackFunction> orientations = {&Z, &Z2, &Z_};
vector<CallbackFunction> single_moves = {&U, &U2, &U_, &R, &R2, &R_, &L, &L2, &L_, &F, &F2, &F_, &D, &D2, &D_, &B, &B2, &B_};


void Cube::ApplyMove(string move, int type){
    moves_map[move](pieces);
    move += " ";
    type == 0 ? (scramble_alg += move) : (solver_alg += move);
}

void Cube::scramble(int moves){
    string move = "";
    for(int i = 0; i < moves; i++){
        move += single_moves[rand()%single_moves.size()](pieces) + " ";
    }
    scramble_alg += move;
}

void Cube::rnd_simple_move(int type){
    string move = single_moves[rand() % single_moves.size()](pieces) + " ";
    type == 0 ? (scramble_alg += move) : (solver_alg += move); 
}

void Cube::rnd_permutation(int type){
    int index = rand() % permutations.size();
    // index = 14;
    for(int x = 0; x < permutations[index].size(); x++){
        string move = permutations[index][x](pieces) + " ";
        type == 0 ? (scramble_alg += move) : (solver_alg += move);
    }
}        

void Cube::rnd_rotation(int type){
    string move = rotations[rand() % rotations.size()](pieces) + " ";
    type == 0 ? (scramble_alg += move) : (solver_alg += move);
}

void Cube::rnd_orientation(int type){
    string move = orientations[rand() % orientations.size()](pieces) + " ";
    type == 0 ? (scramble_alg += move) : (solver_alg += move);
}

void Cube::print(){
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 9; y++){
            if(y % 3 == 0) cout << "\n";
            switch(pieces[x][y]){
                case 0:
                    cout << WHITE << "\u25A0 " << RESET;
                    break;
                case 1:
                    cout << BLUE << "\u25A0 " << RESET;
                    break;
                case 2:
                    cout << RED << "\u25A0 " << RESET;
                    break;
                case 3:
                    cout << GREEN << "\u25A0 " << RESET;
                    break;
                case 4:
                    cout << ORANGE << "\u25A0 " << RESET;
                    break;
                case 5:
                    cout << YELLOW << "\u25A0 " << RESET;
                    break;
                default:
                    break;
            }
            
        }
        cout << "\n";
    }
    cout << "\n\n";
}

string Cube::get_algorithm(){
    return solver_alg;
}

string Cube::get_scramble(){
    return scramble_alg;
}

int Cube::is_solved(){
    return fitness == 0 ? 1 : 0; 
}

void Cube::calculate_fitness(){
    int off_stickers = 0;
    for(int x = 0; x < 6; x++){
        int center = pieces[x][4];
        for(int i = 0; i < 9; i++){
            if(pieces[x][i] != center)
                off_stickers++;
        }
    }
    fitness = off_stickers;
}

void Cube::initMapMoves(){
    moves_map["U"] = U;
    moves_map["U2"] = U2;
    moves_map["U_"] = U_;
    moves_map["R"] = R;
    moves_map["R2"] = R2;
    moves_map["R_"] = R_;
    moves_map["L"] = L;
    moves_map["L2"] = L2;
    moves_map["L_"] = L_;
    moves_map["F"] = F;
    moves_map["F2"] = F2;
    moves_map["F_"] = F_;
    moves_map["B"] = B;
    moves_map["B2"] = B2;
    moves_map["B_"] = B_;
    moves_map["D"] = D;
    moves_map["D2"] = D2;
    moves_map["D_"] = D_;
    moves_map["M"] = M;
    moves_map["M2"] = M2;
    moves_map["M_"] = M_;
    moves_map["E"] = E;
    moves_map["E2"] = E2;
    moves_map["E_"] = E_;
    moves_map["X"] = X;
    moves_map["X2"] = X2;
    moves_map["X_"] = X_;
    moves_map["Y"] = Y;
    moves_map["Y2"] = Y2;
    moves_map["Y_"] = Y_;
    moves_map["Z"] = Z;
    moves_map["Z2"] = Z2;
    moves_map["Z_"] = Z_;
}


Cube* Cube::return_copy(){
    Cube *copy = new Cube();
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 9; y++){
            copy->pieces[x][y] = pieces[x][y];
        }
    }
    copy->fitness = fitness;
    copy->solver_alg = solver_alg;
    copy->scramble_alg = scramble_alg;

    return copy;
}

int Cube::return_size_solution(){
    int cont = 0;
    //Apply scramble for every individual
    for(int x = 0; x < solver_alg.size();){
        string aux1(1, solver_alg.at(x+1));
        string aux2 = " ";

        if (aux1 == aux2) {
            aux1 = string(1, solver_alg[x]);
            x += 2;
        }
        else{
            aux1 = string(1, solver_alg[x]) + string(1, solver_alg[x + 1]);
            x += 3;
        } 
        aux1 = "";
        cont++;
    }
    return cont;
}
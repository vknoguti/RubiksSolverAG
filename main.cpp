#include <bits/stdc++.h>
#include <string>
#include "cube.hh"

using namespace std;

//using permutations algorithm to solve
class Solver1{
    public:
        int population, max_generations, max_resets, preserve_pop;
        Solver1(int pop, int max_gens, int max_res, int preser_pop){
            population = pop;
            max_generations = max_gens;
            max_resets = max_res;
            preserve_pop = preser_pop;
        }

        void solve(string applied_scramble){
            for(int r = 0; r < max_resets; r++){
                vector<Cube *> cubes;
                //Iterate through all population and applying its initial state (original cube with scramble)
                for(int p = 0; p < population; p++){
                    Cube *cube = new Cube();
                    //Apply scramble for every individual
                    for(int x = 0; x < applied_scramble.size();){
                        string aux1(1, applied_scramble.at(x+1));
                        string aux2 = " ";
                
                        if (aux1 == aux2) {
                            aux1 = string(1, applied_scramble[x]);
                            x += 2;
                        }
                        else{
                            aux1 = string(1, applied_scramble[x]) + string(1, applied_scramble[x + 1]);
                            x += 3;
                        } 
                        cube->ApplyMove(aux1, 0);
                        aux1 = "";
                    }
                    cube->calculate_fitness();
                    cubes.push_back(cube);
                }
            
                //Evolve population
                for(int g = 0; g < max_generations; g++){
                    //Display data about fitness and generation
                    if(g % 10 == 0){
                        cout << "Generation " << g << endl;
                        cout << "Current Fitness " << cubes[0]->fitness << endl << endl;
                    }
                    
                    //Metholody evolutive that uses a list of algorithms(permutations), no limit in size to solutions and elitism in selection
                    if(evolve1(&cubes, g) == 1) return;

                }  
                //Genocide if passes max_generations
                cubes.clear();
            }
        }

    private:
        int evolve1(vector <Cube *> *cubes, int g){
            //Evolve selected individuals
            for(int i = 0; i < cubes->size(); i++){
                if((*cubes)[i]->fitness == 0){
                    cout << "Solution found: " << endl;
                    cout << "Generation: " << g << endl;
                    cout << "Qtt movements Solution " << (*cubes)[i]->return_size_solution() << endl; 
                    cout << "Scramble: " << (*cubes)[i]->get_scramble() << endl;
                    cout << "Solution: " << (*cubes)[i]->get_algorithm() << endl;
                    return 1;
                }
                //Elitism
                //Keep the top-most best solutions unchanged
                //Just mutate the worst individuals of population
                if(i > preserve_pop){
                    //Mutation of population
                    
                    Cube *copy = (*cubes)[rand() % preserve_pop]->return_copy();
                    int old_fitness = copy->fitness;

                    int operation = rand() % 4;
                    switch(operation){
                        case 0:
                            copy->rnd_permutation(1);
                            break;
                        case 1:
                            copy->rnd_orientation(1);
                            copy->rnd_permutation(1);
                            break;
                        case 2:
                            copy->rnd_orientation(1);
                            copy->rnd_rotation(1);
                            copy->rnd_permutation(1);
                            break;
                        case 3: 
                            copy->rnd_rotation(1);
                            copy->rnd_orientation(1);
                            copy->rnd_permutation(1);
                            break;
                    }

                    //OBS: It was verified that if we try to get a better solution everytime, the genetic algorithm 
                    //tends to keep steady without improving
                    // int new_fitness;
                    // copy->calculate_fitness();
                    // new_fitness = copy->fitness;

                    // //If the solution deteriorate, get back the original solution
                    // if(old_fitness > new_fitness){
                    //     copy = cubes[rand() % preserve_pop]->return_copy();
                    // }

                    delete (*cubes)[i];
                    (*cubes)[i] = copy;
                }

                (*cubes)[i]->calculate_fitness();
            }

            //Sort population by fitness
            sort(cubes->begin(), cubes->end(), [](const Cube* lhs, const Cube* rhs){
                return lhs->fitness < rhs->fitness;
            });

            return 0;
        }

};


int main(){
    srand(time(NULL));

    Cube *original = new Cube();
    
    int population = 10000;
    int max_generations = 2000;
    int max_resets = 20;
    int preserve_pop = (population * 0.1);

    original->scramble(30);
    original->print();

    string applied_scramble = original->get_scramble();

    Solver1 *s1 = new Solver1(population, max_generations, max_resets, preserve_pop);
    s1->solve(applied_scramble);


    return 0;
}
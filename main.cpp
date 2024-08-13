#include <iostream>
#include <random>
#include <ctime>


//Struct for init particles
struct Sol {
  std::vector<std::vector<bool>> particles;
  std::vector<bool> g_best;
  int g_best_fitness;
  std::vector<int> p_best_fitness;
};

// generate random number
bool generate_random_value_0_or_1(int seed, int probability)
{
  std::time_t t = std::time(0); // t is an integer type
  seed = seed *  t;
  srand(seed);                     // Seed with current time

  // Generate a random number between 0 and 99
  int randomNumber = rand() % 100;

  if (randomNumber < probability)
  {
    return 1;
  }
  else
  {
    return 0;
  };
};

// function to print a particle
void print_particle(std::vector<bool> p)
{
  int vector_size = p.size();
  for (int i = 0; i < vector_size; i++)
  {
    std::cout << p[i];
  }
  std::cout << std::endl;
}


int fitness(std::vector<bool>& p, int values[]){
  int total = 0;
  for (int i=0; i< p.size(); i++){
      int p_int = (int) p[i];
      total += p[i] * values[i];
  }
  return total;
}



// Here we define the init_particles function
Sol init_particles(int nb_particles, int nb_obj, int values[])
{
  Sol init_solution;
  int g_best_fitness=0;
  std::vector<int> p_best_fitness;

  std::vector<std::vector<bool>> particles;
  int p_fitness;
  std::vector<bool> g_best;
  for (int i = 0; i < nb_particles; i++)
  {
    std::vector<bool> p = {};
    for (int j = 0; j < nb_obj; j++)
    {

      bool r = generate_random_value_0_or_1(j*i, 50);
      p.push_back(r);
    } // here we have genrated a particle

    particles.push_back(p);

    // get particle fitness
    p_fitness = fitness(p, values);

    p_best_fitness.push_back(p_fitness);

    if (p_fitness > g_best_fitness){
      g_best_fitness = p_fitness;
      g_best = p;
    }

  }

  init_solution.particles = particles;
  init_solution.g_best = g_best;
  init_solution.g_best_fitness = g_best_fitness;
  init_solution.p_best_fitness = p_best_fitness;
  return init_solution;
}


// run function
void run(int dim,int nb_objects, int values[], int capacities[], int *weights, int nb_particles)
{
  Sol init_solution = init_particles(nb_particles, nb_objects, values);

  std::vector<bool> g_best =  init_solution.g_best;
  print_particle(g_best);
}


int main()
{
  int dim = 2;
  int nb_obj = 3;
  int nb_particles = 5;
  int values[3] = {10, 11, 12};
  int capacities[2] = {8, 7};
  int weights[3][2] = {{3, 2}, {5, 4}, {4, 3}};
  run(dim, nb_obj,values, capacities, *weights, nb_particles);
}
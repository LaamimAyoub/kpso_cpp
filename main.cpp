#include <bits/stdc++.h>
#include <random>
#include <ctime>


//Struct for init particles
struct Sol {
  std::vector<std::vector<bool>> particles;
  std::vector<bool> g_best;
  double g_best_fitness;
  std::vector<double> p_best_fitness;
};

// generate random number
bool generate_random_value_0_or_1(int seed, int probability)
{
  std::time_t t = std::time(0); // t is an integer type
  seed = seed + t;
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

// Here we define the init_particles function
Sol init_particles(int nb_particles, int dim)
{
  Sol init_solution;
  double g_best_fitness;
  std::vector<double> p_best_fitness;

  std::vector<std::vector<bool>> particles;
  for (int i = 0; i < nb_particles; i++)
  {
    std::vector<bool> p;
    for (int j = 0; j < dim; j++)
    {

      bool r = generate_random_value_0_or_1(j, 80);
      p.push_back(r);
    } // here we have genrated a particle



    particles.push_back(p);
  }

  init_solution.particles = particles;
  return init_solution;
}

// run function
void run(int dim,int nb_objects, int values[], int capacities[], int *weights)
{
  Sol init_solution = init_particles(5, 20);
  print_particle(init_solution.particles[0]);
}

int main()
{
  int dim = 2;
  int nb_obj = 3;
  int values[3] = {};
  int capacities[2] = {8, 7};
  int weights[3][2] = {{3, 2}, {5, 4}, {4, 3}};
  run(dim, nb_obj,values, capacities, *weights);
}
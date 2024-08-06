#include <bits/stdc++.h>
#include <random>
#include <ctime>

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
std::vector<std::vector<bool>> init_particles(int nb_particles, int dim)
{
  std::vector<std::vector<bool>> particles;
  for (int i = 0; i < nb_particles; i++)
  {
    std::vector<bool> p;
    for (int j = 0; j < dim; j++)
    {

      bool r = generate_random_value_0_or_1(j, 80);
      p.push_back(r);
    }
    particles.push_back(p);
  }
  return particles;
}

// run function
void run()
{
  std::vector<std::vector<bool>> particles = init_particles(5, 20);
  print_particle(particles[0]);
}

int main()
{
  run();
}
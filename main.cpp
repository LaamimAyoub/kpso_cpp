#include <bits/stdc++.h>
#include <random>


//generate random number
bool generate_random_value_0_or_1(int seed, int probability){
 srand(seed);  // Seed with current time
  
  // Generate a random number between 0 and 99
  int randomNumber = rand() % 100 ;

  if (randomNumber < probability){
    return 1;
  } else {
    return 0;
  };

};


int main()
{


}


void print_particle(std::vector<bool> p){

    
}

// Here we define the init_particles function
std::vector<std::vector<bool>> init_particles(int nb_particles, int dim){
std::vector<std::vector<bool>> particles;
for (int i=0; i < nb_particles; i++ ){
std::vector<bool> p;
for (int j=0; j < nb_particles; j++){

bool r = generate_random_value_0_or_1(j, 20);
p.push_back(r);

}
}
}

int run(){
    init_particles();

}

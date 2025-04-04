#include <iostream>
#include "Empirical/include/emp/math/Random.hpp"


class Organism {
  public:
    double behavior;

    // a constructor that takes a double and sets the instance variable.
    Organism(double b) : behavior(b) { }

};

int main() {

    emp::vector<Organism> population;

    double b = emp::Random random(1);

    for (int i = 0; i < 100; i++) {
      population.push_back(Organism(b));
      cout << "Organism " << i << " behavior: " << population[i].behavior << std::endl;
    }

}
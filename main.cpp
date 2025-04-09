#include <iostream>
#include "Empirical/include/emp/math/Random.hpp"


class Organism {
public:
    double behavior;

    Organism(double b) : behavior(b) { }

    Organism* reproduce(emp::Random thing) {
        Organism* child = new Organism(behavior);
        child->mutate(thing);
        return child;
    }

    double getBehavior() const {
        return behavior;
    }

    void mutate(emp::Random random) {  
        double number = random.GetRandNormal(0.0, 0.02);
        behavior += number;
    }
};

int main() {
    emp::Random random(1);
    emp::vector<Organism> population;

    for (int i = 0; i < 100; i++) {
        double b = random.GetDouble(0, 1);
        population.push_back(Organism(b));
        // std::cout << "Organism " << i << " behavior: " << population[i].behavior << std::endl;
    }

    Organism parent = population[0];

    Organism child = *parent.reproduce(random);

    std::cout << "Parent behavior: " << parent.behavior << std::endl;   
    std::cout << "Child behavior: " << child.behavior << std::endl;

    // Updates from exercise 3
    double highest_behavior = 0.0;
    Organism highest_organism = population[0];
    
    for (int k = 0; k < 10000; k++) {
        for (Organism j : population){
            // Gets organism with highest numerical behavior
            double current_behavior = j.getBehavior();
            if (current_behavior > highest_behavior) {
                std::cout << "New highest behavior achieved: " << current_behavior << std::endl;
                highest_behavior = current_behavior;
                // Declare a variable to hold the highest behavior
                highest_organism = j;
                
            }
        }
    }   

    int overwrite = random.GetUInt(0,100);

    // Reproduce with it and save the child
    Organism child_organism = *highest_organism.reproduce(random);
    std::cout << "Original score of org:" << population[overwrite].getBehavior() << std::endl;

    // Replace a random organism in the population with the child
    
    population[overwrite] = child_organism;

    std::cout << "New score of org:" << population[0].getBehavior() << std::endl;

    std::cout << "Size of population: " << population.size() << std::endl;

    return 0;
}
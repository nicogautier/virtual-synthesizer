#include "harmonics.hpp"
#include <iostream>
#include <vector>

void testHarmonics(){
  std::cout << "----- Test Harmonics -----\n";
  Harmonics h1 = Harmonics({{1,2}, {2,3}, {8,2}, {9,2}, {4,4}, {2,4}, {5,6}});

  h1.addHarmonic(4,5);
  std::cout << h1.addHarmonic(7,2.5);
  h1.updateHarmonic(12,3);
  h1.updateHarmonic(5,8);
  h1.updateHarmonic(9,3);
  
  std::vector<harmonic> harm = h1.harmonics();

  for (auto &h : harm){
    std::cout << h << "\n";
  }

}


int main()
{
  
  testHarmonics();

  return 0;
}
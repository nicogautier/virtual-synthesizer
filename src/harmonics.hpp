#ifndef SYNTH_HARMONICS
#define SYNTH_HARMONICS

#include <vector>

class Harmonics
{
public:

    

    Harmonics();
    Harmonics(const std::vector<int> &number, const std::vector<double> &value);
  
    bool addHarmonic(int number, double value);
    bool updateHarmonic(int number, double value);
    bool removeHarmonic(int number);

    bool getHarmonics(std::vector<double> &number, std::vector<double> &value);



private:
    int n; //number of harmonics
    std::vector<int> numberHarmonics; //multiple number of the fundamental
    std::vector<double> valueHarmonics; //value harmonics

};





#endif
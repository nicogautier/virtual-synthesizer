#ifndef SYNTH_HARMONICS
#define SYNTH_HARMONICS

#include <vector>
#include <iostream>



struct harmonic
{
    int number; //multiple of the fundamental
    double value; //value harmonic
    

    harmonic(int n, double v) : number{n}, value{v}{};

};

inline std::ostream& operator<< (std::ostream& o, const harmonic& h){
        o << "harmonic  " << h.number << " value : " << h.value;
        return o;
    }




class Harmonics
{
public:

    Harmonics() : n_{}, harmonics_{} {harmonics_.reserve(14);}
    Harmonics(const std::vector<harmonic> &h);

    bool isHarmonic(int number); //return true if number is an harmonic
    double valueHarmonic(int number); //return the value of the harmonci number

    bool addHarmonic(int number, double value); //create a nex harmonic number
    bool updateHarmonic(int number, double value);  //update the value of the harmonic number
    bool removeHarmonic(int number); //remove the harmonic number

    
    int n() {return n_;}
    const std::vector<harmonic>& harmonics() const { return harmonics_; }

private:
    int n_; //number of harmonics
    std::vector<harmonic> harmonics_; //vector of all the harmonics


};





#endif
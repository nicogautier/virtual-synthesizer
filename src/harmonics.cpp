#include "harmonics.hpp"

#include <vector>
#include <stdexcept>
#include <algorithm>




bool isValidHarmonic(int number, double value){
    if(number<1 || value<0){return false;}
    return true;
}



Harmonics::Harmonics(const std::vector<harmonic> &h)
:Harmonics{}
{

    n_ = (int)h.size();

    //assert validity of all harmonics
    for(int i=0; i<n_ ; i++){ 
        if (!isValidHarmonic(h[i].number,h[i].value)){
            throw std::invalid_argument( "received invalid value for harmonic" );
        } 
    
    } 

    harmonics_ = h;

    //sort and remove duplicate harmonics
    std::sort(harmonics_.begin(), harmonics_.end(),  [] (harmonic const& lhs, harmonic const& rhs) {return lhs.number < rhs.number;});
    harmonics_.erase( unique( harmonics_.begin(), harmonics_.end(), [] (harmonic const& lhs, harmonic const& rhs) {return lhs.number == rhs.number;} ), harmonics_.end() );


}

bool Harmonics::isHarmonic(int number){
    for (auto &h : harmonics_){
        if(h.number == number){return true;}
    }
    return false;
}




bool Harmonics::addHarmonic(int number, double value){
    
    if(!isValidHarmonic(number, value)){return false;}  

    //if the harmonic already exist just update it
    if(isHarmonic(number)){
        updateHarmonic(number, value);
    }
    else{
       
        //find the first harmonic above and insert it before
        for(int i=0 ; i<n_ ; i++){
            
            if (harmonics_[i].number>number){
                harmonics_.insert ( harmonics_.begin()+i , {number, value} );
                n_++;
                return true;
            }
        }      
        
    }

    return false;
    
}

bool Harmonics::updateHarmonic(int number, double value){
    if(!isValidHarmonic(number, value)){return false;}

    //find index of the harmonic
    auto it = std::find_if(harmonics_.begin(), harmonics_.end(), [&] (harmonic const& h) {return h.number == number;});
    if(it == harmonics_.end()){return false;}//if harmonic not found

    harmonics_[it - harmonics_.begin()].value = value;
    harmonics_[it - harmonics_.begin()].number = number;

    return true;

}

bool Harmonics::removeHarmonic(int number){
    auto it = std::find_if(harmonics_.begin(), harmonics_.end(), [&] (harmonic const& h) {return h.number == number;});
    if(it == harmonics_.end()){return false;}//if harmonic not found
    harmonics_.erase(it);
    n_--;
    return true;
}



double Harmonics::valueHarmonic(int number){

    auto it = std::find_if(harmonics_.begin(), harmonics_.end(), [&] (harmonic const& h) {return h.number == number;});
    if(it == harmonics_.end()){return -1;}// harmonic not found

    return harmonics_[it - harmonics_.begin()].value;

}

#include "harmonics.hpp"

#include <vector>
#include <stdexcept>
#include <algorithm>




Harmonics::Harmonics(const std::vector<harmonic> &h)
:Harmonics{}
{

    n_ =(int) h.size();

    for(int i=0; i<n_ ; i++){
        if(h[i].number<1){throw std::invalid_argument( "received invalid fundamental multiple value" );};
        if(h[i].value<0 ){throw std::invalid_argument( "received negative value for harmonic" );}
    } 

    harmonics_ = h;

    //sort and remove duplicate harmonics
    std::sort(harmonics_.begin(), harmonics_.end(),  [] (harmonic const& lhs, harmonic const& rhs) {return lhs.number < rhs.number;});
    harmonics_.erase( unique( harmonics_.begin(), harmonics_.end(), [] (harmonic const& lhs, harmonic const& rhs) {return lhs.number == rhs.number;} ), harmonics_.end() );


}
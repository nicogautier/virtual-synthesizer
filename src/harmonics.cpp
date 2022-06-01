#include "harmonics.hpp"

#include <assert.h>
#include <stdexcept>

Harmonics::Harmonics()
:numberHarmonics{}, valueHarmonics{}, n{}
{
}


Harmonics::Harmonics(const std::vector<int> &number, const std::vector<double> &value)
:Harmonics{}
{
    if(number.size()!=value.size()){throw std::invalid_argument( "received different vector size" );}
    
    n = number.size();

    for(int i=0; i<n ; i++){
        if(number[i]<1 || value[i]<0 ){throw std::invalid_argument( "received negative value" );}
    } 

    numberHarmonics = number;
    valueHarmonics = value;

}
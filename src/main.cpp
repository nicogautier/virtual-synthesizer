#include "harmonics.hpp"
#include "musicNotes.hpp"


#include <pulse/pulseaudio.h>
#include <pulse/simple.h>



#include <iostream>
#include <vector>

void testHarmonics(){
  std::cout << "----- Test Harmonics -----\n";
  Harmonics h1 = Harmonics({{1,2}, {2,3}, {8,2}, {9,2}, {4,4}, {2,4}, {5,6}});

  

  h1.addHarmonic(4,5);
  h1.addHarmonic(7,2.5);
  h1.updateHarmonic(12,3);
  h1.updateHarmonic(5,8);
  h1.updateHarmonic(9,3);
  h1.removeHarmonic(8);
  
  std::vector<harmonic> harm = h1.harmonics();

  for (auto &h : harm){
    std::cout << h << "\n";
  }

  std::cout << "\nharmonic 5: " << h1.valueHarmonic(5) << " harmonic 25: " << h1.valueHarmonic(25)<<"\n";

  std::cout << "\nLA3: " << NOTES[OCTAVE_3][LA] << " Hz\n";

}


int main()
{
  
  testHarmonics();



  pa_simple *s;
  pa_sample_spec ss;

  ss.format = PA_SAMPLE_S16NE;
  ss.channels = 2; 
  ss.rate=   44100;

  s = pa_simple_new(NULL, "Synthesizer", PA_STREAM_PLAYBACK, NULL, "Music", &ss, NULL, NULL, NULL);

  return 0;
}


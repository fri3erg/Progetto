#include "Artifact.hpp"

Artifact::Artifact(): Drawable()
{
   
}

Artifact::Artifact(int y, int x,chtype ch): Drawable(y,x,ch)
{
   
}
Artifact::Artifact(int y, int x): Drawable(y,x,RandomArtifact())
{
   
}

chtype Artifact::RandomArtifact()
{
    srand(time(NULL));
    int i = (rand() % (5));
    switch(i){
        case 0:
            return 'R'; //range
        case 1:
            return 'E'; //danno
        case 2:
            return 'H'; //cura
        default:
            return 'J'; //chiave
     };
}
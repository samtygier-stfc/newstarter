#include "shape.h"

ostream& operator<<(ostream &os, Shape &sh){
    return sh.display(os);
}

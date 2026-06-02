#include <iostream>

#include "tiere/Schwein.h"
#include "tiere/Tier.h"

class Metzger {
public:
    void schlachten(Tier *tier){
        std::cout << "Messer wetz" << std::endl;
    }
};

template<class T>
class Spediteur {
public:
    void fahren(T *Ware) {
        std::cout << "Wir fahren auf der Autobahn" << std::endl;


    }
};

class MyPropertyChangedListener {
public:
    void onPropertyChanged(PropertyChangedEvent &event) {
        std::cout << "Property changed: " << event << std::endl;
    }
};

int main() {
    Metzger metzger;
    Spediteur<Schwein> spediteur;
    MyPropertyChangedListener listener;
    Schwein piggy{"Miss piggy"};
    piggy.addpropertyChangedListeners(
        [&listener](PropertyChangedEvent &e){listener.onPropertyChanged(e);}
        );
    piggy.addPigTooFatListener([&metzger](Schwein *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener(
           std::bind(&Metzger::schlachten, &metzger, std::placeholders::_1)
   );
    piggy.addPigTooFatListener([&spediteur](Schwein *s){spediteur.fahren(s);});

    piggy.set_name("Babe");

    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
    return 0;
}
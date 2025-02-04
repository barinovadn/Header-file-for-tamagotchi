#include "tamagotchi.h"

#include <iostream>

using namespace std;

class MyTamagotchi : public Tamagotchi {
private:
    TamagotchiStat* hungerStat = get_stat("hunger");
    TamagotchiStat* happinessStat = get_stat("happiness");
public:
    MyTamagotchi() : Tamagotchi({
        {"hunger", new TamagotchiStat(100)}, 
        {"happiness", new TamagotchiStat(100)},
        {"discipline", new TamagotchiStat(100)}
        }) {}

    ~MyTamagotchi() { // destructor
        for (auto& pair : stats) {
            delete pair.second;
        }
    }

    void play() {
        if (hungerStat && happinessStat) {
            hungerStat->set(hungerStat->get_value() - 10);
            happinessStat->set(happinessStat->get_value() + 15);
        }
    }

    void feed() {
        if (hungerStat) {
            hungerStat->set(hungerStat->get_value() + 25);
        }
    }
};






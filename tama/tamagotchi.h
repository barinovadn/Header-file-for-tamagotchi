#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <iostream>
#include <ctime>
#include <climits>
#include <unordered_map>

using namespace std;


class TamagotchiStat {
private:

    static constexpr double CHANGE_PER_SECOND = -0.1;
    static constexpr int VALUE_MIN = 0;
    static constexpr int VALUE_MAX = 100;

    int value;
    time_t updated;

public:

    TamagotchiStat(int default_value = 100) : value(default_value), updated(time(nullptr)) {}

    void set(int new_value) {
        value = new_value;
        value = min(VALUE_MAX, max(VALUE_MIN, value));
        updated = time(nullptr);
    }

    void update() {
        time_t current_time = time(nullptr);
        double time_passed = difftime(current_time, updated);
        set(value + static_cast<int>(time_passed * CHANGE_PER_SECOND));
    }

    int get_value() const { return value; }
};


class Tamagotchi : public TamagotchiStat {
protected:
    unordered_map<string, TamagotchiStat*> stats;
public:

    Tamagotchi(initializer_list<pair<const string, TamagotchiStat*>> initList) {
        for (const auto& pair : initList) {
            stats[pair.first] = pair.second;
        }
    }

    void update() {
        for (auto& pair : stats) {
            pair.second->update();
        }
    }

    TamagotchiStat* get_stat(const string& stat_name) const {
        auto it = stats.find(stat_name);
        if (it != stats.end()) {
            return it->second;
        }
        return nullptr;
    }
};


#endif
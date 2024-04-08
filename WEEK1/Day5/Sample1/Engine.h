#ifndef ENGINE_H
#define ENGINE_H
#include <ostream>

class Engine
{
private:
    int _horsepower;
    float _torque;
    
public:
    Engine() = delete;
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (const Engine&) = delete;
    Engine&& operator = (Engine&&) = delete;
    ~Engine() = default;

    Engine(int horsepower, float torque);

    int horsepower() const { return _horsepower; }
    void setHorsepower(int horsepower) { _horsepower = horsepower; }

    float torque() const { return _torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

    

};

#endif // ENGINE_H

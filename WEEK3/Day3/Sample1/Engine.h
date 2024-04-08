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
    Engine(const Engine&) = delete;//engine e1; Engine e2(e1);
    Engine(Engine&&) = delete;//engine e2(std::move(e1))
    Engine& operator = (const Engine&) = delete;//engine e1; engine e2; e2=e1;
    Engine&& operator = (Engine&&) = delete;
    ~Engine() = default;

    Engine(int horsepower, float torque);

    int horsepower() const { return _horsepower; }
    void setHorsepower(int horsepower) { _horsepower = horsepower; }

    float torque() const { return _torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

    

};

#endif // ENGINE_H

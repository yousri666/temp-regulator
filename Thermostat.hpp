#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP

class Heater {
public:
    virtual void start() = 0;
};

class Cooler {
public:
    virtual void start() = 0;
};

class Thermostat
{
private:
    int _currentTemp{0};
    int _targetTemp {0};
    int _minTemp{0};
    int _maxTemp{0};
    Heater* _heater;
    Cooler* _cooler;
public:
    Thermostat(int min, int max, Heater* heater, Cooler* cooler);

    virtual int getCurrentTemp(void) const;
    int getMinTemp(void) const;
    int getMaxTemp(void) const;
    void setMinTemp(int min);
    void setMaxTemp(int max);
    void adjustTemp(void);
};


#endif // THERMOSTAT_HPP

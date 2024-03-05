#include "Thermostat.hpp"
#include <cmath>

Thermostat::Thermostat(int min, int max, Heater* heater, Cooler* cooler): _minTemp(min), _maxTemp(max), _heater(heater), _cooler(cooler)
{
}

int Thermostat::getCurrentTemp(void) const
{
    //temperature could be measured from sensor
    return _currentTemp;
}

int Thermostat::getMinTemp(void) const
{
    return _minTemp;
}

int Thermostat::getMaxTemp(void) const
{
    return _maxTemp;
}

void Thermostat::setMinTemp(int min)
{
    _minTemp = min;
}

void Thermostat::setMaxTemp(int max)
{
    _maxTemp = max;
}

void Thermostat::adjustTemp(void)
{
    int temp = getCurrentTemp();
    if(temp < _minTemp) {
        _heater->start();
    }        
    else if(temp > _maxTemp) {
        _cooler->start();
    }
}

// StubHeater.hpp
#ifndef STUB_HEATER_H
#define STUB_HEATER_H

#include "Thermostat.hpp"

class StubHeater : public Heater {
public:
    void start() override {}
};

#endif // STUB_HEATER_HPP

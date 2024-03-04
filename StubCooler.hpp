// StubCooler.hpp
#ifndef STUB_COOLER_H
#define STUB_COOLER_H

#include "Thermostat.hpp"

class StubCooler : public Cooler {
public:
    void start() override {}
};

#endif // STUB_COOLER_HPP

#pragma once
#include "Job.h"

class Archer : public Job{
public:
    std::string toString() const override {
        return "Archer";
    }
};
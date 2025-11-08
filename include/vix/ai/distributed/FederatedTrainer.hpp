#pragma once
#include <cstddef>

namespace vix::ai::distributed
{

    struct FederatedTrainer
    {
        std::size_t round{0};
        void step() { ++round; } // simulate one FL round
        std::size_t current_round() const { return round; }
    };

} // namespace vix::ai::distributed

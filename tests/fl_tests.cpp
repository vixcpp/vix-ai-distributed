#include <cassert>
#include <vix/ai/distributed/FederatedTrainer.hpp>
using namespace vix::ai::distributed;

int main()
{
    FederatedTrainer fl;
    assert(fl.current_round() == 0);
    fl.step();
    fl.step();
    assert(fl.current_round() == 2);
    return 0;
}

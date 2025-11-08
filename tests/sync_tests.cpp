#include <cassert>
#include <vix/ai/distributed/SyncManager.hpp>
using namespace vix::ai::distributed;

int main()
{
    SyncManager sm;
    sm.add_peer(Peer{"p1"});
    sm.add_peer(Peer{"p2"});
    assert(sm.size() == 2);

    auto n = sm.sync(); // simulate sync pass
    assert(n == 2);
    assert(sm.total_synced() == 2);

    n = sm.sync();
    assert(sm.total_synced() == 4);
    (void)n;
    return 0;
}

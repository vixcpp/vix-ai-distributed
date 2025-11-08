#include <cassert>
#include <vix/ai/distributed/Peer.hpp>
using namespace vix::ai::distributed;

int main()
{
    Peer p1("peer-A"), p2("peer-B"), p3("peer-A");
    assert(p1 != p2);
    assert(p1 == p3);
    assert(p1.name() == "peer-A");
    return 0;
}

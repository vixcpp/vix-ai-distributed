#include <cassert>
#include <vix/ai/distributed/SecureChannel.hpp>
using namespace vix::ai::distributed;

int main()
{
    SecureChannel ch;
    assert(!ch.is_established());
    bool ok = ch.handshake("peer-remote");
    assert(ok && ch.is_established());
    (void)ok;
    return 0;
}

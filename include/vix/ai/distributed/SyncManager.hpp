#pragma once
#include <cstddef>
#include <vector>
#include <string>
#include "Peer.hpp"

namespace vix::ai::distributed
{

    // v0 stub: sync() returns number of peers "synced"
    // ready for future: model/version vectors, conflict resolution, CRDT/clock
    struct SyncManager
    {
        std::vector<Peer> peers{};
        std::size_t sync_count{0};

        void add_peer(const Peer &p) { peers.push_back(p); }
        std::size_t size() const noexcept { return peers.size(); }

        std::size_t sync()
        {
            // simulate a sync pass
            sync_count += peers.size();
            return peers.size();
        }
        std::size_t total_synced() const noexcept { return sync_count; }
    };

} // namespace vix::ai::distributed

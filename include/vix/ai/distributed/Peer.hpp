#pragma once
#include <string>
#include <utility>

namespace vix::ai::distributed
{

    struct Peer
    {
        std::string id{"peer-0"};
        explicit Peer(std::string pid = "peer-0") : id(std::move(pid)) {}
        const std::string &name() const noexcept { return id; }
        bool operator==(const Peer &other) const noexcept { return id == other.id; }
        bool operator!=(const Peer &other) const noexcept { return !(*this == other); }
    };

} // namespace vix::ai::distributed

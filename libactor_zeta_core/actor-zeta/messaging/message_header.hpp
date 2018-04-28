#ifndef MESSAGING_MESSAGE_HEADER_HPP
#define MESSAGING_MESSAGE_HEADER_HPP

#include "actor-zeta/behavior/type_action.hpp"
#include "message_priority.hpp"
#include "actor-zeta/actor/actor_address.hpp"

namespace actor_zeta {
    namespace messaging {
///
/// @brief
///
        class message_header final {
        public:
            message_header() = default;

            message_header(const message_header &) = default;

            message_header &operator=(const message_header &) = default;

            message_header(message_header &&) = default;

            message_header &operator=(message_header &&) = default;

            ~message_header() = default;

            message_header(actor::actor_address sender_, const std::string& name);

            message_header(actor::actor_address sender_, const std::string& name, actor::actor_address recipient_);

            message_header(actor::actor_address sender_, const std::string& name, message_priority p);

            message_header(actor::actor_address sender_, const std::string& name, message_priority p, actor::actor_address recipient_);

            auto  priorities() const -> message_priority;

            auto command() const noexcept -> const behavior::type_action &;

            auto recipient() const -> actor::actor_address ;

            auto sender() const -> actor::actor_address ;

            auto is_callback() const -> bool;

        private:
            actor::actor_address sender_;
            actor::actor_address recipient_;
            behavior::type_action command_;
            message_priority prioritie;
        };
    }
}
#endif //MESSAGE_HEADER_HPP

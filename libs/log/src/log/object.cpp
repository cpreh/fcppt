//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/log/context.hpp> // IWYU pragma: keep
#include <fcppt/log/context_reference.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/detail/context_tree.hpp> // IWYU pragma: keep
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/impl/node_to_location.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

fcppt::log::object::object(
    fcppt::log::context_reference const _context, fcppt::log::name const &_name)
    : object{_context, _context.get().root(), _name}
{
}

fcppt::log::object::object(
    fcppt::log::object const &_parent, fcppt::log::name const &_name)
    : object{_parent.context_, _parent.node_, _name}
{
}

fcppt::log::object::object(
    fcppt::log::context_reference const _context,
    fcppt::log::location const &_location,
    fcppt::log::name const &_name)
    : object{_context, _context.get().find_location(_location), _name}
{
}

fcppt::log::object::~object() = default;

void fcppt::log::object::log(
    fcppt::log::level const _level, fcppt::log::detail::temporary_output const &_helper) const
{
  if (this->enabled(_level))
  {
    this->level_sink(_level).log(_helper, this->location_);
  }
}

fcppt::log::level_stream const &fcppt::log::object::level_sink(fcppt::log::level const _level) const
{
  return *this->level_streams()[_level];
}

bool fcppt::log::object::enabled(fcppt::log::level const _level) const
{
  return fcppt::optional::maybe(
      this->level(), fcppt::const_(false), [_level](fcppt::log::level const _enabled_level) {
        return _level >= _enabled_level;
      });
}

fcppt::log::level_stream_array const &fcppt::log::object::level_streams() const
{
  return this->context_.get().level_streams().get();
}

fcppt::log::optional_level fcppt::log::object::level() const
{
  return this->node_.get().value().level();
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

fcppt::log::object::object(
    fcppt::log::context_reference const _context,
    context_tree_ref const _node,
    fcppt::log::name const &_name)
    : context_{_context},
      node_{_context.get().find_child(_node, _name)},
      location_{fcppt::log::impl::node_to_location(this->node_.get())}
{
}

FCPPT_PP_POP_WARNING

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/log/context.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/context_reference.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/detail/context_tree.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/log/impl/tree_formatter.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

fcppt::log::object::object(
    fcppt::log::context_reference const _context, fcppt::log::parameters const &_parameters)
    : object{_context, _context.get().root(), _parameters}
{
}

fcppt::log::object::object(
    fcppt::log::object const &_parent, fcppt::log::parameters const &_parameters)
    : object{_parent.context_, _parent.node_, _parameters}
{
}

fcppt::log::object::object(
    fcppt::log::context_reference const _context,
    fcppt::log::location const &_location,
    fcppt::log::parameters const &_parameters)
    : object{_context, _context.get().find_location(_location), _parameters}
{
}

fcppt::log::object::~object() = default;

void fcppt::log::object::log(
    fcppt::log::level const _level, fcppt::log::detail::temporary_output const &_helper)
{
  if (this->enabled(_level))
  {
    this->level_sink(_level).log(_helper, this->formatter_);
  }
}

fcppt::log::level_stream const &fcppt::log::object::level_sink(fcppt::log::level const _level) const
{
  return this->level_streams()[_level];
}

bool fcppt::log::object::enabled(fcppt::log::level const _level) const
{
  return fcppt::optional::maybe(
      this->level(), fcppt::const_(false), [_level](fcppt::log::level const _enabled_level) {
        return _level >= _enabled_level;
      });
}

fcppt::log::format::optional_function const &fcppt::log::object::formatter() const
{
  return this->formatter_;
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
    fcppt::log::parameters const &_parameters)
    : context_{_context},
      node_{_context.get().find_child(_node, _parameters.name())},
      formatter_{fcppt::log::format::chain(
          _parameters.formatter(), fcppt::log::impl::tree_formatter(this->node_.get()))}
{
}

FCPPT_PP_POP_WARNING

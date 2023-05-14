//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/log/const_level_stream_array_reference.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_stream_array_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_level_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>

namespace fcppt::log
{
/**
\brief A logger context manages log levels

\ingroup fcpptlog
*/
class context
{
public:
  FCPPT_NONMOVABLE(context);

  /**
  \brief Constructs a context

  \param root The root log level which will be the default for new log locations

  \param streams The stream sinks to use for all log locations
  */
  FCPPT_LOG_DETAIL_SYMBOL
  context(fcppt::log::optional_level const &root, fcppt::log::level_stream_array &&streams);

  FCPPT_LOG_DETAIL_SYMBOL
  ~context();

  /**
  \brief Updates the log level at a location

  Note that every location below is also updated.
  */
  FCPPT_LOG_DETAIL_SYMBOL
  void set(fcppt::log::location const &, fcppt::log::optional_level const &);

  /**
  \brief Gets the current log level for a location
  */
  [[nodiscard]] FCPPT_LOG_DETAIL_SYMBOL
  fcppt::log::optional_level get(fcppt::log::location const &) const;

  /**
  \brief The level streams of this context
  */
  [[nodiscard]] FCPPT_LOG_DETAIL_SYMBOL
  fcppt::log::const_level_stream_array_reference level_streams() const;
private:
  struct impl;

  // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
  fcppt::unique_ptr<impl> const impl_;

  friend class fcppt::log::object;

  [[nodiscard]] fcppt::reference<fcppt::log::detail::context_tree const> root() const;

  [[nodiscard]] fcppt::reference<fcppt::log::detail::context_tree const>
  find_location(fcppt::log::location const &);

  [[nodiscard]] fcppt::reference<fcppt::log::detail::context_tree const>
  find_child(fcppt::reference<fcppt::log::detail::context_tree const>, fcppt::log::name const &);
};

}

#endif

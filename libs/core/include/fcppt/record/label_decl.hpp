//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_LABEL_DECL_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_DECL_HPP_INCLUDED

#include <fcppt/record/element_init_fwd.hpp>
#include <fcppt/record/label_fwd.hpp>
#include <fcppt/record/detail/is_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief A type identifying an element of a record.

\ingroup fcpptrecord

\tparam Tag An implementation-defined type, passed by #FCPPT_RECORD_MAKE_LABEL.
*/
template <typename Tag>
struct label
{
  using tag = Tag;

  static_assert(fcppt::record::detail::is_tag<Tag>::value, "Tag must be a tag");

  /**
  \brief Creates a value used to initialize an element of a record.
  */
  template <typename Arg>
  // NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
  fcppt::record::element_init<Tag, std::remove_cvref_t<Arg>>
  operator=(Arg &&);
};

}

#endif

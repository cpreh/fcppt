//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_IS_BASE_OF_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_BASE_OF_HPP_INCLUDED

#include <fcppt/assert_complete.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace type_traits
{
/**
\brief Like <code>std::is_base_of</code>, but only works on complete types

\ingroup fcppttypetraits

<code>std::is_base_of</code> is undefined behavior if the Derived type is
incomplete, which is another source of mistakes. This class, instead, checks if
both \a Base and \a Derived are complete.

\tparam Base A complete type

\tparam Derived A complete type
*/
template <typename Base, typename Derived>
struct is_base_of : std::is_base_of<Base, Derived>
{
  FCPPT_ASSERT_COMPLETE(Base);

  FCPPT_ASSERT_COMPLETE(Derived);
};

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_TYPE_INFO_HPP_INCLUDED
#define FCPPT_VARIANT_TYPE_INFO_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace variant
{
/**
\brief Returns an <code>std::%type_info</code> of the held type

\ingroup fcpptvariant
*/
template <typename... Types>
std::type_info const &type_info(fcppt::variant::object<Types...> const &_variant)
{
  return fcppt::variant::apply(
      [](auto const &_value) -> std::type_info const & {
        FCPPT_USE(_value);

        return typeid(fcppt::type_traits::remove_cv_ref_t<decltype(_value)>);
      },
      _variant);
}

}
}

#endif

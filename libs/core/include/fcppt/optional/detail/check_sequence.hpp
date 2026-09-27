//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_DETAIL_CHECK_SEQUENCE_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_CHECK_SEQUENCE_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/optional/is_object.hpp>
#include <fcppt/optional/is_object_v.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/tuple/types_of.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional::detail
{
template <typename Result, typename Source>
struct check_sequence
{
  using source_optional = fcppt::type_traits::value_type<Source>;

  static constexpr bool const value =
      fcppt::optional::is_object_v<source_optional>
      &&
      std::is_same_v<
          fcppt::type_traits::value_type<Result>,
          fcppt::type_traits::value_type<source_optional>>;
};

template <typename Result, typename... Types>
struct check_sequence<Result, fcppt::tuple::object<Types...>>
{
  static constexpr bool const value =
      std::conjunction_v<fcppt::optional::is_object<Types>...>
      &&
      fcppt::tuple::is_object<Result>::value
      &&
      std::is_same_v<
          fcppt::mpl::list::object<fcppt::type_traits::value_type<Types>...>,
          fcppt::tuple::types_of<Result>>;
};

}

#endif

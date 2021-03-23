//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_DETAIL_CHECK_SEQUENCE_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_CHECK_SEQUENCE_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/tuple/types_of.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace optional
{
namespace detail
{
template <typename Result, typename Source>
struct check_sequence
{
  using source_optional = fcppt::type_traits::value_type<Source>;

  static_assert(
      fcppt::optional::is_object<source_optional>::value,
      "The source must be a container of optionals");

  static_assert(
      std::is_same_v<
          fcppt::type_traits::value_type<Result>,
          fcppt::type_traits::value_type<source_optional>>,
      "ResultContainer must be a container of the source's success type");
};

template <typename Result, typename... Types>
struct check_sequence<Result, fcppt::tuple::object<Types...>>
{
  static_assert(
      std::conjunction_v<fcppt::optional::is_object<Types>...>,
      "Source must be an fcppt::tuple::object of optionals");

  static_assert(fcppt::tuple::is_object<Result>::value, "Result must be an fcppt::tuple::object");

  static_assert(
      std::is_same_v<
          ::metal::list<fcppt::type_traits::value_type<Types>...>,
          fcppt::tuple::types_of<Result>>,
      "The tuple types must match");
};

}
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//! [mpl_invoke_on]
// In the following example, we are going to create a function that can
// transform a color type given at runtime (defined via an enum) into a static
// color type (represented by variant over static color types).
#include <fcppt/tag.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/mpl/list/invoke_on.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/variant/from_list.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
// Our color enum
enum class color_enum : std::uint8_t
{
  bgr,
  rgb
  // + more color types
};

// Our static color types
struct bgr
{
};

struct rgb
{
};

// Typedef the available static color types
using static_color_types = fcppt::mpl::list::object<bgr, rgb>;

// The variant type that can hold any of the static color types
using color_variant = fcppt::variant::from_list<static_color_types>;

// Transforms a concrete color type into a color_variant. This function will be
// used with invoke_on.
struct create_function
{
  template <typename ConcreteColor>
  color_variant operator()(fcppt::tag<ConcreteColor>) const
  {
    return color_variant(ConcreteColor());
  }
};

// Transforms a color enum into a static color type using invoke_on
color_variant make_color_variant(color_enum const _value)
{
  return fcppt::mpl::list::invoke_on<static_color_types>(
      fcppt::cast::enum_to_underlying(_value),
      create_function(),
      []() -> color_variant { std::terminate(); });
}

}

int main()
{
  color_variant const variant(make_color_variant(color_enum::rgb));

  // variant now holds the type rgb
  std::cout << fcppt::variant::holds_type<rgb>(variant) << '\n';
}
//! [mpl_invoke_on]

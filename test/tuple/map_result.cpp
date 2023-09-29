//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/use.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/tuple/map_result.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

int main()
{
  {
    auto const function([](auto const _arg) {
      return std::integral_constant<int, std::remove_const_t<decltype(_arg)>::value + 1U>{};
    });

    static_assert(
        std::is_same_v<
            fcppt::tuple::map_result<
                fcppt::tuple::
                    object<std::integral_constant<int, 1>, std::integral_constant<int, 2>>,
                decltype(function)>,
            fcppt::tuple::object<std::integral_constant<int, 2>, std::integral_constant<int, 3>>>);

    FCPPT_USE(function);
  }

  {
    using int_movable = fcppt::catch_::movable<int>;

    FCPPT_DECLARE_STRONG_TYPEDEF(int_movable, strong_int_movable);

    auto const function{[](int_movable &&_value) { return strong_int_movable{std::move(_value)}; }};

    static_assert(std::is_same_v<
                  fcppt::tuple::map_result<fcppt::tuple::object<int_movable> &&, decltype(function)>,
                  fcppt::tuple::object<strong_int_movable>>);
  }
}

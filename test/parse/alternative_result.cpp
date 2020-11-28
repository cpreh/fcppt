//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/parse/alternative_result.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<
                fcppt::parse::alternative_result<int, char>,
                fcppt::variant::object<int, char>>);

  static_assert(std::is_same_v<fcppt::parse::alternative_result<int, int>, int>);

  static_assert(
      std::is_same_v<fcppt::parse::alternative_result<fcppt::variant::object<int>, int>, int>);

  static_assert(std::is_same_v<
                fcppt::parse::alternative_result<fcppt::variant::object<int>, char>,
                fcppt::variant::object<int, char>>);

  static_assert(
      std::is_same_v<
          fcppt::parse::
              alternative_result<fcppt::variant::object<int, char>, fcppt::variant::object<int>>,
          fcppt::variant::object<int, char>>);

  static_assert(std::is_same_v<
                fcppt::parse::alternative_result<fcppt::variant::object<int, float>, char>,
                fcppt::variant::object<int, float, char>>);
}

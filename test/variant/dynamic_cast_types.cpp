//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/variant/dynamic_cast_types.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<
                fcppt::variant::dynamic_cast_types<fcppt::mpl::list::object<int, char const>>,
                fcppt::mpl::list::object<fcppt::reference<int>, fcppt::reference<char const>>>);
}

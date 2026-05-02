//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/type.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(
      std::is_same_v<
          fcppt::mpl::list::map<
              fcppt::mpl::list::object<int, float>,
              fcppt::mpl::
                  bind<fcppt::mpl::lambda<fcppt::mpl::type>, fcppt::mpl::lambda<std::is_integral>>>,
          fcppt::mpl::list::object<std::true_type, std::false_type>>);
}

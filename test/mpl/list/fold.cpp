//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/add.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
template<unsigned N>
using integral = std::integral_constant<unsigned,N>;
}

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::fold<
                    fcppt::mpl::list::object<integral<1U>, integral<2U>>,
                    fcppt::mpl::lambda<fcppt::mpl::add>,
                    integral<0U>>,
                integral<3U>>);
}

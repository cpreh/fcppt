//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/fold.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
template<unsigned N>
using integral = std::integral_constant<unsigned,N>;

// TODO(philipp): Put this into fcppt::mpl
template<typename T, typename U>
struct add_impl;

template<typename T, T A, T B>
struct add_impl<std::integral_constant<T,A>,std::integral_constant<T,B>>
{
  using type = std::integral_constant<T,A+B>;
};
template<typename T, typename U>
using add =  typename add_impl<T,U>::type;
}

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::fold<
                    fcppt::mpl::list<integral<1U>, integral<2U>>,
                    fcppt::mpl::lambda<add>,
                    integral<0U>>,
                integral<3U>>);
}

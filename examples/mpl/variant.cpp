//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object.hpp>

namespace
{
//![variant_decl]
template<typename... Types> class variant
{
//![variant_decl]
//![variant_impl]
  using type_list = fcppt::mpl::list::object<Types...>;
  static_assert(fcppt::mpl::list::distinct<type_list>::value);

  template<typename T>
  using sizeof_ = fcppt::mpl::size_type<sizeof(T)>;

  using sizes = fcppt::mpl::list::map<type_list,fcppt::mpl::lambda<sizeof_>>;
};
//![variant_impl]
}

int main()
{
}

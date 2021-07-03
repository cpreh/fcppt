//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{

//![lambda_decl]
using add_pointer = fcppt::mpl::lambda<std::add_pointer_t>;
using common_type = fcppt::mpl::lambda<std::common_type_t>;
using make_list = fcppt::mpl::lambda<fcppt::mpl::list::object>;
//![lambda_decl]

//![lambda_call]
using r1 = fcppt::mpl::apply<add_pointer,int>;
static_assert(std::is_same_v<r1,int *>);

using r2 = fcppt::mpl::apply<common_type,char,int>;
static_assert(std::is_same_v<r2,int>);

using r3 = fcppt::mpl::apply<make_list,int,float>;
static_assert(std::is_same_v<r3,fcppt::mpl::list::object<int,float>>);
//![lambda_call]

//![is_int]
template<typename T>
using is_int_impl = std::is_same<T,int>;

using is_int = fcppt::mpl::lambda<is_int_impl>;
//![is_int]
//![is_int2]
using is_int2 = fcppt::mpl::bind<fcppt::mpl::lambda<std::is_same>, fcppt::mpl::arg<1>, fcppt::mpl::constant<int>>;
//![is_int2]

}
int main()
{
}

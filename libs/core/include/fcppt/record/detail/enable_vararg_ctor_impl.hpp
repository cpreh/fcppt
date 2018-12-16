//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_ENABLE_VARARG_CTOR_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ENABLE_VARARG_CTOR_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Ref,
	typename... Args
>
struct enable_vararg_ctor_impl
:
std::true_type
{
};

template<
	typename Ref,
	typename Arg
>
struct enable_vararg_ctor_impl<
	Ref,
	Arg
>
:
std::negation<
	std::disjunction<
		std::is_same<
			Ref,
			fcppt::type_traits::remove_cv_ref_t<
				Arg
			>
		>,
		std::is_same<
			fcppt::no_init,
			fcppt::type_traits::remove_cv_ref_t<
				Arg
			>
		>
	>
>
{
};

}
}
}

#endif

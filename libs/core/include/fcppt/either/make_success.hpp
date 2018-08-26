//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_MAKE_SUCCESS_HPP_INCLUDED
#define FCPPT_EITHER_MAKE_SUCCESS_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Create an either with a success.

\ingroup fcppteither

\tparam Failure The failure type of the either.
*/
template<
	typename Failure,
	typename Success
>
inline
fcppt::either::object<
	Failure,
	fcppt::type_traits::remove_cv_ref_t<
		Success
	>
>
make_success(
	Success &&_success
)
{
	return
		fcppt::either::object<
			Failure,
			fcppt::type_traits::remove_cv_ref_t<
				Success
			>
		>{
			std::forward<
				Success
			>(
				_success
			)
		};
}

}
}

#endif

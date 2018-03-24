//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_MAKE_FAILURE_HPP_INCLUDED
#define FCPPT_EITHER_MAKE_FAILURE_HPP_INCLUDED

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
\brief Create an either with a failure.

\ingroup fcppteither

\tparam Success The success type of the either.
*/
template<
	typename Success,
	typename Failure
>
inline
fcppt::either::object<
	fcppt::type_traits::remove_cv_ref_t<
		Failure
	>,
	Success
>
make_failure(
	Failure &&_failure
)
{
	return
		fcppt::either::object<
			fcppt::type_traits::remove_cv_ref_t<
				Failure
			>,
			Success
		>{
			std::forward<
				Failure
			>(
				_failure
			)
		};
}

}
}

#endif

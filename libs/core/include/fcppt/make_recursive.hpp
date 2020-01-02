//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_RECURSIVE_HPP_INCLUDED
#define FCPPT_MAKE_RECURSIVE_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Creates an #fcppt::recursive.

\ingroup fcpptvarious
*/
template<
	typename Type
>
fcppt::recursive<
	fcppt::type_traits::remove_cv_ref_t<
		Type
	>
>
make_recursive(
	Type &&_value
)
{
	return
		fcppt::recursive<
			fcppt::type_traits::remove_cv_ref_t<
				Type
			>
		>{
			std::forward<
				Type
			>(
				_value
			)
		};
}

}

#endif

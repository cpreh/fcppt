//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_MAKE_MOVABLE_HPP_INCLUDED
#define FCPPT_CATCH_MAKE_MOVABLE_HPP_INCLUDED

#include <fcppt/catch/movable_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace catch_
{

template<
	typename Type
>
inline
fcppt::catch_::movable<
	fcppt::type_traits::remove_cv_ref_t<
		Type
	>
>
make_movable(
	Type &&_value
)
{
	return
		fcppt::catch_::movable<
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
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_SUCCESS_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_SUCCESS_HPP_INCLUDED

#include <fcppt/either/make_success.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Creates a success value.

\ingroup fcpptoptions
*/
template<
	typename Type
>
inline
fcppt::options::result<
	fcppt::type_traits::remove_cv_ref_t<
		Type
	>
>
make_success(
	Type &&_value
)
{
	return
		fcppt::either::make_success<
			fcppt::options::error
		>(
			std::forward<
				Type
			>(
				_value
			)
		);
}

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_COMBINE_ERRORS_HPP_INCLUDED
#define FCPPT_OPTIONS_COMBINE_ERRORS_HPP_INCLUDED

#include <fcppt/options/error.hpp>
#include <fcppt/options/detail/combined_error_type.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Combines two errors.

\ingroup fcpptoptions

Combines two errors by extracting their strings and passing them to \a _function.
The type of the resulting error is \link fcppt::options::other_error\endlink
if and only if \a _error1 or \a _error2 is \link fcppt::options::other_error\endlink.
In other words, \link fcppt::options::other_error\endlink has a higher priority
than \link fcppt::options::missing_error\endlink.
*/
template<
	typename Function
>
inline
fcppt::options::error
combine_errors(
	fcppt::options::error &&_error1,
	fcppt::options::error &&_error2,
	Function const &_function
)
{
	return
		fcppt::variant::apply_binary(
			[
				&_function
			](
				auto &&_val1,
				auto &&_val2
			)
			{
				return
					fcppt::options::error{
						fcppt::options::detail::combined_error_type<
							fcppt::type_traits::remove_cv_ref_t<
								decltype(
									_val1
								)
							>,
							fcppt::type_traits::remove_cv_ref_t<
								decltype(
									_val2
								)
							>
						>{
							_function(
								std::move(
									_val1.get()
								),
								std::move(
									_val2.get()
								)
							)
						}
					};
			},
			std::move(
				_error1
			),
			std::move(
				_error2
			)
		);
}

}
}

#endif

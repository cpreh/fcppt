//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_IMPL_HPP_INCLUDED

#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Function
>
inline
fcppt::options::missing_error
combine_errors_impl(
	fcppt::options::missing_error &&_error1,
	fcppt::options::missing_error &&_error2,
	Function const &_function
)
{
	return
		fcppt::options::missing_error{
			std::move(
				_error2.state_
			),
			_function(
				std::move(
					_error1.error_
				),
				std::move(
					_error2.error_
				)
			)
		};
}

template<
	typename Function
>
inline
fcppt::options::other_error
combine_errors_impl(
	fcppt::options::other_error &&_error1,
	fcppt::options::missing_error &&_error2,
	Function const &_function
)
{
	return
		fcppt::options::other_error{
			_function(
				std::move(
					_error1.get()
				),
				std::move(
					_error2.error_
				)
			)
		};
}

template<
	typename Function
>
inline
fcppt::options::other_error
combine_errors_impl(
	fcppt::options::missing_error &&_error1,
	fcppt::options::other_error &&_error2,
	Function const &_function
)
{
	return
		fcppt::options::other_error{
			_function(
				std::move(
					_error1.error_
				),
				std::move(
					_error2.get()
				)
			)
		};
}

template<
	typename Function
>
inline
fcppt::options::other_error
combine_errors_impl(
	fcppt::options::other_error &&_error1,
	fcppt::options::other_error &&_error2,
	Function const &_function
)
{
	return
		fcppt::options::other_error{
			_function(
				std::move(
					_error1.get()
				),
				std::move(
					_error2.get()
				)
			)
		};
}

}
}
}

#endif

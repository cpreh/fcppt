//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_OUTPUT_HPP_INCLUDED
#define FCPPT_EITHER_OUTPUT_HPP_INCLUDED

#include <fcppt/either/match.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

template<
	typename Failure,
	typename Success,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::either::object<
		Failure,
		Success
	> const &_either
)
{
	auto const output(
		[
			&_stream
		](
			auto const &_value
		)
		{
			_stream
				<<
				_value;
		}
	);

	fcppt::either::match(
		_either,
		output,
		output
	);

	return
		_stream;
}

}
}

#endif

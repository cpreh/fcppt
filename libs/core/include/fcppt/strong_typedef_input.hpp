//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_INPUT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_INPUT_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Input operator for strong typedefs

\ingroup fcpptstrongtypedef
*/
template<
	typename Ch,
	typename Traits,
	typename T,
	typename Tag
>
std::basic_istream<
	Ch,
	Traits
> &
operator>>(
	std::basic_istream<
		Ch,
		Traits
	> &_stream,
	fcppt::strong_typedef<
		T,
		Tag
	> &_value
)
{
	fcppt::optional::maybe_void(
		fcppt::io::extract<
			T
		>(
			_stream
		),
		[
			&_value
		](
			T &&_result
		)
		{
			_value =
				fcppt::strong_typedef<
					T,
					Tag
				>(
					std::move(
						_result
					)
				);
		}
	);

	return
		_stream;
}

}

#endif

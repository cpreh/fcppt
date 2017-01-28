//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_INPUT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_INPUT_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
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
	// TODO: Make it possible to use no_init here
	T in;

	if(
		_stream >> in
	)
		_value =
			fcppt::strong_typedef<
				T,
				Tag
			>(
				std::move(
					in
				)
			);

	return
		_stream;
}

}

#endif

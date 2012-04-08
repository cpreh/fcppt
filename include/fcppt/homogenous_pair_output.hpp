//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HOMOGENOUS_PAIR_OUTPUT_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_OUTPUT_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Writes a pair to an ostream

Writes the pair \a _pair to \a _stream, using the formatting
<code>(_pair.first, _pair.second)</code>.

\param _stream The stream to write to

\param _pair The pair to write

\return \a _stream
*/
template<
	typename T,
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
	fcppt::homogenous_pair<
		T
	> const &_pair
)
{
	return
		_stream
		<< _stream.widen('(')
		<< _pair.first
		<< _stream.widen(',')
		<< _pair.second
		<< _stream.widen(')');
}

}

#endif

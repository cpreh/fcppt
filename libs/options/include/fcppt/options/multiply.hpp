//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MULTIPLY_HPP_INCLUDED
#define FCPPT_OPTIONS_MULTIPLY_HPP_INCLUDED

#include <fcppt/options/product_impl.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The identity of multiplication

\ingroup fcpptoptions
*/
template<
	typename Parser1
>
inline
Parser1
multiply(
	Parser1 const &_parser1
)
{
	return
		_parser1;
}

/**
\brief Multiplies parsers

\ingroup fcpptoptions
*/
template<
	typename Parser1,
	typename... Parsers
>
inline
auto
multiply(
	Parser1 const &_parser1,
	Parsers const &..._parsers
)
{
	return
		fcppt::options::product<
			Parser1,
			decltype(
				fcppt::options::multiply(
					_parsers...
				)
			)
		>(
			_parser1,
			fcppt::options::multiply(
				_parsers...
			)
		);
}

}
}

#endif

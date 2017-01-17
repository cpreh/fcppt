//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MULTIPLY_HPP_INCLUDED
#define FCPPT_OPTIONS_MULTIPLY_HPP_INCLUDED

#include <fcppt/options/detail/multiply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Multiplies parsers

\ingroup fcpptoptions

\tparam Parsers Must be at least two parsers.
*/
template<
	typename... Parsers
>
inline
auto
multiply(
	Parsers &&..._parsers
)
{
	return
		fcppt::options::detail::multiply(
			std::forward<
				Parsers
			>(
				_parsers
			)...
		);
}

}
}

#endif

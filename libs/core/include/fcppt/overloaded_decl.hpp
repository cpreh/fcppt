//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OVERLOADED_DECL_HPP_INCLUDED
#define FCPPT_OVERLOADED_DECL_HPP_INCLUDED

#include <fcppt/overloaded_fwd.hpp>


namespace fcppt
{

/**
\brief Overloads multiple lambdas.

\ingroup fcpptvarious
*/
template<
	typename... Types
>
struct overloaded // NOLINT(fuchsia-multiple-inheritance)
:
	Types...
{
	template<
		typename... Args
	>
	explicit
	overloaded(
		Args &&...
	);

	using
	Types::operator()...;
};

}

#endif

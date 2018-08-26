//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_NOTHING_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_NOTHING_IMPL_HPP_INCLUDED

#include <fcppt/optional/nothing_decl.hpp>
#include <fcppt/optional/object_impl.hpp>


template<
	typename T
>
fcppt::optional::nothing::
operator
fcppt::optional::object<
	T
>
() const
{
	return
		fcppt::optional::object<
			T
		>{};
}

#endif

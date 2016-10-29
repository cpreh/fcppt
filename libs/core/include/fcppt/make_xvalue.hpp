//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_XVALUE_HPP_INCLUDED
#define FCPPT_MAKE_XVALUE_HPP_INCLUDED

#include <fcppt/xvalue_impl.hpp>


namespace fcppt
{

/**
\brief Convenience function to create xvalues

\ingroup fcpptref
*/
template<
	typename Type
>
inline
fcppt::xvalue<
	Type
>
make_xvalue(
	Type &_ref
)
noexcept
{
	return
		fcppt::xvalue<
			Type
		>(
			_ref
		);
}

}

#endif

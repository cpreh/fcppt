//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INTEGRAL_C_HPP_INCLUDED
#define FCPPT_MPL_INTEGRAL_C_HPP_INCLUDED

namespace fcppt
{
namespace mpl
{

/**
\brief Replacement for boost::mpl::integral_c

\ingroup fcpptmpl

boost::mpl::integral_c has problems with the minimum and maximum of integer
types. This class does not emulate the prior and next typedefs.
*/
template<
	typename Type,
	Type Value
>
struct integral_c
{
	typedef Type type;

	static Type const value = Value;
};

}
}

#endif

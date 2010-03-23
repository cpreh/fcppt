//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_MPL_VALUE_TYPE_HPP_INCLUDED

namespace fcppt
{
namespace mpl
{

/// value_type meta function, calculates T::value_type
template<
	typename T
>
struct value_type
{
	typedef typename T::value_type type;
};

}
}

#endif

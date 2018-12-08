//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_HAS_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_HAS_TYPE_HPP_INCLUDED

#include <fcppt/brigand/found_t.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename Element
>
using
has_type
=
fcppt::brigand::found_t<
	Types,
	Element
>;

}
}
}

#endif
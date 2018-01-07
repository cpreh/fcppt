//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_INDEX_OF_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_INDEX_OF_HPP_INCLUDED

#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/brigand/integral_cast.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/index_of.hpp>
#include <fcppt/config/external_end.hpp>


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
using index_of
=
fcppt::brigand::integral_cast<
	fcppt::variant::size_type,
	fcppt::cast::static_cast_fun,
	::brigand::index_of<
		Types,
		Element
	>
>;

}
}
}

#endif

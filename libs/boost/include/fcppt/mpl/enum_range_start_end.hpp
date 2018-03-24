//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_ENUM_RANGE_START_END_HPP_INCLUDED
#define FCPPT_MPL_ENUM_RANGE_START_END_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/mpl/copy.hpp>
#include <fcppt/mpl/integral_cast_tpl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/transform.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief An MPL range over enums from a minimum to a maximum

\ingroup fcpptenum
*/
template<
	typename Enum,
	Enum Start,
	Enum Max
>
struct enum_range_start_end
:
boost::mpl::transform<
	typename
	fcppt::mpl::copy<
		boost::mpl::range_c<
			std::underlying_type_t<
				Enum
			>,
			fcppt::cast::enum_to_int<
				std::underlying_type_t<
					Enum
				>
			>(
				Start
			),
			fcppt::cast::enum_to_int<
				std::underlying_type_t<
					Enum
				>
			>(
				Max
			)
			+
			fcppt::literal<
				std::underlying_type_t<
					Enum
				>
			>(
				1
			)
		>
	>::type,
	fcppt::mpl::integral_cast_tpl<
		Enum,
		fcppt::cast::int_to_enum_fun,
		boost::mpl::_1
	>
>::type
{
};

}
}

#endif

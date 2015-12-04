//          Copyright Carl Philipp Reh 2009 - 2015.
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
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

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
			typename
			std::underlying_type<
				Enum
			>::type,
			fcppt::cast::enum_to_int<
				typename
				std::underlying_type<
					Enum
				>::type
			>(
				Start
			),
			fcppt::cast::enum_to_int<
				typename
				std::underlying_type<
					Enum
				>::type
			>(
				Max
			)
			+
			fcppt::literal<
				typename
				std::underlying_type<
					Enum
				>::type
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

FCPPT_PP_POP_WARNING

}
}

#endif

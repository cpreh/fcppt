//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DETAIL_BASE_VALUE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DETAIL_BASE_VALUE_HPP_INCLUDED

#include <fcppt/random/distribution/base_type.hpp>
#include <fcppt/random/distribution/detail/is_terminal.hpp>
#include <fcppt/random/distribution/transform/terminal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace detail
{

template<
	typename Type
>
typename
std::enable_if<
	fcppt::random::distribution::detail::is_terminal<
		Type
	>::value,
	Type
>::type
base_value(
	Type const &_value
)
{
	return
		_value;
}

template<
	typename Type
>
typename
std::enable_if<
	!fcppt::random::distribution::detail::is_terminal<
		Type
	>::value,
	typename
	fcppt::random::distribution::base_type<
		Type
	>::type
>::type
base_value(
	Type const &_value
)
{
	return
		fcppt::random::distribution::detail::base_value(
			fcppt::random::distribution::transform<
				Type
			>::base_value(
				_value
			)
		);
}

}
}
}
}

#endif

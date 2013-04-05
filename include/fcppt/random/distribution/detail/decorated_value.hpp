//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DETAIL_DECORATED_VALUE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DETAIL_DECORATED_VALUE_HPP_INCLUDED

#include <fcppt/random/distribution/transform/terminal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
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
	typename Result,
	typename Type
>
typename
boost::enable_if<
	std::is_same<
		Result,
		Type
	>,
	Result
>::type
decorated_value(
	Type const &_value
)
{
	return
		_value;
}

template<
	typename Result,
	typename Type
>
typename
boost::disable_if<
	std::is_same<
		Result,
		Type
	>,
	Result
>::type
decorated_value(
	Type const &_value
)
{
	typedef
	fcppt::random::distribution::transform<
		Result
	>
	transform_type;

	return
		transform_type::decorated_value(
			fcppt::random::distribution::detail::decorated_value<
				typename
				transform_type::base_type
			>(
				_value
			)
		);
}

}
}
}
}

#endif

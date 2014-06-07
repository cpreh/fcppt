//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_TRANSFORM_BOOST_UNITS_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_TRANSFORM_BOOST_UNITS_HPP_INCLUDED

#include <fcppt/random/distribution/transform/terminal_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

template<
	typename Unit,
	typename Type
>
struct transform<
	boost::units::quantity<
		Unit,
		Type
	>
>
{
	typedef
	Type
	base_type;

	typedef
	boost::units::quantity<
		Unit,
		Type
	>
	decorated_type;

	static
	inline
	decorated_type
	decorated_value(
		base_type const &_value
	)
	{
		return
			decorated_type::from_value(
				_value
			);
	}

	static
	inline
	base_type
	base_value(
		decorated_type const &_value
	)
	{
		return
			_value.value();
	}
};

}
}
}

#endif

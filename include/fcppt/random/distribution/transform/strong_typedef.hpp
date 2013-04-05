//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_TRANSFORM_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_TRANSFORM_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/random/distribution/transform/terminal_fwd.hpp>
#include <fcppt/strong_typedef_impl.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

template<
	typename Type,
	typename Alias
>
struct transform<
	fcppt::strong_typedef<
		Type,
		Alias
	>
>
{
	typedef
	Type
	base_type;

	typedef
	fcppt::strong_typedef<
		Type,
		Alias
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
			decorated_type(
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
			_value.get();
	}
};

}
}
}

#endif

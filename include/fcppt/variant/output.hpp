//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OUTPUT_HPP_INCLUDED
#define FCPPT_VARIANT_OUTPUT_HPP_INCLUDED

#include <fcppt/variant/detail/output.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <iosfwd>

namespace fcppt
{
namespace variant
{

/// Outputs the object held by the variant to a basic_ostream
template<
	typename Types,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &stream_,
	object<
		Types
	> const &object_
)
{
	return
		apply_unary(
			detail::output<
				std::basic_ostream<
					Ch,
					Traits
				>
			>(
				stream_
			),
			object_
		);
}


}
}

#endif

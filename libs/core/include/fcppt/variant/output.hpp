//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OUTPUT_HPP_INCLUDED
#define FCPPT_VARIANT_OUTPUT_HPP_INCLUDED

#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Outputs the value held by the variant to a basic_ostream

\ingroup fcpptvariant

Outputs the value held by \a _object to \a _stream. This function requires all
possibles types to be printable.

\param _stream The stream to output to

\param _object The variant to output

\return \a _stream
*/
template<
	typename Types,
	typename Ch,
	typename Traits
>
inline
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::variant::object<
		Types
	> const &_object
)
{
	return
		fcppt::variant::apply(
			[
				&_stream
			](
				auto const &_value
			)
			->
			std::basic_ostream<
				Ch,
				Traits
			> &
			{
				return
					_stream
					<<
					_value;
			},
			_object
		);
}

}
}

#endif

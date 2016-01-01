//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_OUTPUT_HPP_INCLUDED
#define FCPPT_OPTIONAL_OUTPUT_HPP_INCLUDED

#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Outputs an optional to a basic_ostream

\ingroup fcpptoptional

Outputs the value held by \a _opt_value to \a _stream, or nothing.

\param _stream The stream to output to

\param _opt_value The optional to output

\return \a _stream
*/
template<
	typename Type,
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
	> &_stream,
	fcppt::optional::object<
		Type
	> const &_opt_value
)
{
	typedef
	std::basic_ostream<
		Ch,
		Traits
	> &
	result_type;

	return
		fcppt::optional::maybe(
			_opt_value,
			[
				&_stream
			]()
			-> result_type
			{
				return
					_stream
					<<
					_stream.widen(
						'N'
					);
			},
			[
				&_stream
			](
				Type const &_value
			)
			-> result_type
			{
				return
					_stream
					<<
					_stream.widen(
						'J'
					)
					<<
					_stream.widen(
						' '
					)
					<<
					_value;
			}
		);
}

}
}

#endif

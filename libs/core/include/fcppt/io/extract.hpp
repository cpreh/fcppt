//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_EXTRACT_HPP_INCLUDED
#define FCPPT_IO_EXTRACT_HPP_INCLUDED

#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Reads a value from a stream, returning an optional.

\ingroup fcpptio

Uses <code>operator>></code> to extract a value of type \a Type from \a
_stream. If extracting the value fails, an empty optional is returned.
*/
template<
	typename Type,
	typename Ch,
	typename Traits
>
fcppt::optional::object<
	Type
>
extract(
	std::basic_istream<
		Ch,
		Traits
	> &_stream
)
{
	Type result;

	return
		_stream
		>>
		result
		?
			fcppt::optional::make(
				std::move(
					result
				)
			)
		:
			fcppt::optional::nothing{}
		;
}

}
}

#endif

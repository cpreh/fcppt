//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_EXTRACT_HPP_INCLUDED
#define FCPPT_IO_EXTRACT_HPP_INCLUDED

#include <fcppt/io/detail/extract.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
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

\tparam Type Must have a default constructor or a constructor for \link fcppt::no_init\endlink.
*/
template<
	typename Type,
	typename Ch,
	typename Traits
>
inline
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
	return
		fcppt::io::detail::extract<
			Type
		>(
			_stream
		);
}

}
}

#endif

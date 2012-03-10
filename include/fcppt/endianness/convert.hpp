//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_CONVERT_HPP_INCLUDED
#define FCPPT_ENDIANNESS_CONVERT_HPP_INCLUDED

#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/swap.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief Converts the endianness of an object

\ingroup fcpptendianness

If \a _format does not match the fcppt::endianness::host_format, then \a _value
will have its endianness converted, otherwise it will be returned as-is. This
function can be used to convert from the host format to \a _format, or from \a
_format to the host format.

\tparam Type Must be a fundamental type

\param _value The value to convert

\param _format The endianness to convert to

\return The converted value
*/
template<
	typename Type
>
typename boost::enable_if<
	boost::is_fundamental<
		Type
	>,
	Type
>::type
convert(
	Type const &_value,
	fcppt::endianness::format::type const _format
)
{
	return
		_format
		==
		fcppt::endianness::host_format()
		?
			_value
		:
			fcppt::endianness::swap(
				_value
			);
}

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_CHAR_PTR_HPP_INCLUDED
#define FCPPT_CAST_TO_CHAR_PTR_HPP_INCLUDED

#include <fcppt/type_traits/is_raw_pointer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

template<
	typename Dest,
	typename Source
>
inline
typename
boost::enable_if<
	fcppt::type_traits::is_raw_pointer<
		Dest
	>,
	Dest
>::type
to_char_ptr(
	Source *const _source
)
{
	return
		reinterpret_cast<
			Dest
		>(
			_source
		);
}

}
}

#endif

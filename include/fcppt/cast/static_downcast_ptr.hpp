//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_STATIC_DOWNCAST_PTR_HPP_INCLUDED
#define FCPPT_CAST_STATIC_DOWNCAST_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Statically converts a pointer to a base class to a pointer to a derived
class

\ingroup fcpptcasts

Converts \a _source to the pointer type specified by \a Dest. This cast is
unsafe and should only be used if the \a _source has dynamic type \a Dest.
Consider using fcppt::cast::dynamic instead.
*/
template<
	typename Dest,
	typename Source
>
typename
boost::enable_if<
	std::is_base_of<
		typename
		std::remove_cv<
			Source
		>::type,
		typename
		std::remove_cv<
			typename
			std::remove_pointer<
				Dest
			>::type
		>::type
	>,
	Dest
>::type
static_downcast_ptr(
	Source *const _source
)
{
	return
		static_cast<
			Dest
		>(
			_source
		);
}

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_STATIC_DOWNCAST_HPP_INCLUDED
#define FCPPT_CAST_STATIC_DOWNCAST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

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
		std::decay<
			Dest
		>::type
	>,
	Dest
>::type
static_downcast(
	Source &_source
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

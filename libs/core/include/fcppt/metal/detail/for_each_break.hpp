//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename List,
	::metal::int_ Index,
	typename Fun
>
std::enable_if_t<
	::metal::size<
		List
	>::value
	==
	Index,
	void
>
for_each_break(
	Fun const &
)
{
}

template<
	typename List,
	::metal::int_ Index,
	typename Fun
>
inline
std::enable_if_t<
	::metal::size<
		List
	>::value
	!=
	Index,
	void
>
for_each_break(
	Fun const &_func
)
{
	switch(
		_func(
			fcppt::tag<
				::metal::at<
					List,
					::metal::number<
						Index
					>
				>
			>()
		)
	)
	{
	case fcppt::loop::continue_:
		fcppt::metal::detail::for_each_break<
			List,
			Index + 1u
		>(
			_func
		);
		return;
	case fcppt::loop::break_:
		return;
	}
}

}
}
}

#endif

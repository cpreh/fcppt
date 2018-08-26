//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_DETAIL_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_BRIGAND_DETAIL_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{
namespace detail
{

template<
	typename List,
	unsigned Index,
	typename Fun
>
std::enable_if_t<
	::brigand::size<
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
	unsigned Index,
	typename Fun
>
inline
std::enable_if_t<
	::brigand::size<
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
				::brigand::at_c<
					List,
					Index
				>
			>()
		)
	)
	{
	case fcppt::loop::continue_:
		fcppt::brigand::detail::for_each_break<
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

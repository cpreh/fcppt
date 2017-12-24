//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_ELEMENT_AT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_AT_HPP_INCLUDED

#include <fcppt/mpl/index_of_iterator.hpp>
#include <fcppt/record/detail/find_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Types,
	typename Label,
	typename Tuple
>
inline
decltype(
	auto
)
element_at(
	Tuple &_elements
)
{
	return
		std::get<
			fcppt::mpl::index_of_iterator<
				Types,
				fcppt::record::detail::find_element<
					Types,
					Label
				>
			>::value
		>(
			_elements
		);
}

}
}
}

#endif

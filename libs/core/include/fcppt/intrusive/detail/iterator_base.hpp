//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_INTRUSIVE_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/iterator/base_fwd.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace intrusive
{
namespace detail
{

template<
	typename Type
>
using
iterator_base
=
fcppt::iterator::base<
	fcppt::iterator::types<
		fcppt::intrusive::iterator<
			Type
		>,
		std::remove_const_t<
			Type
		>,
		Type &,
		std::ptrdiff_t,
		std::bidirectional_iterator_tag
	>
>;

}
}
}

#endif

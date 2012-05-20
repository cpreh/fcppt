//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_ITERATOR_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_ITERATOR_TYPE_HPP_INCLUDED

#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <cstddef>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{
namespace detail
{

template<
	typename StoredType,
	typename Reference
>
struct iterator_type
{
	typedef boost::iterator_facade<
		fcppt::container::bitfield::iterator<
			StoredType,
			Reference
		>,
		fcppt::container::bitfield::value_type,
		std::random_access_iterator_tag,
		Reference,
		std::ptrdiff_t
	> type;
};

}
}
}
}

#endif

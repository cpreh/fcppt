//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_ITERATOR_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_ITERATOR_TYPE_HPP_INCLUDED

#include <fcppt/container/bitfield/difference_type.hpp>
#include <fcppt/container/bitfield/size_type.hpp>
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/container/bitfield/iterator_fwd.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>

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
		bitfield::iterator<
			StoredType,
			Reference
		>,
		bitfield::value_type,
		std::random_access_iterator_tag,
		Reference,
		bitfield::difference_type
	> type;
};

}
}
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INDEX_MAP_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_INDEX_MAP_DECL_HPP_INCLUDED

#include <fcppt/container/index_map_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
TODO: Document this?
\ingroup fcpptcontainer
*/
template<
	typename T,
	typename A
>
class index_map
{
public:
	typedef std::vector<
		T,
		A
	> internal_type;

	typedef A allocator_type;

	typedef T value_type;

	typedef typename internal_type::size_type size_type;

	typedef typename internal_type::reference reference;

	typedef typename internal_type::const_reference const_reference;

	index_map();

	reference
	operator[](
		size_type
	);

	reference
	get_default(
		size_type,
		const_reference
	);

	size_type
	size() const;
private:
	internal_type impl_;
};

}
}

#endif

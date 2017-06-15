//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INDEX_MAP_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_INDEX_MAP_DECL_HPP_INCLUDED

#include <fcppt/function_fwd.hpp>
#include <fcppt/container/index_map_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief An index-based container that grows on demand.

\ingroup fcpptcontainer

This container is a wrapper around a vector that grows on demand. If the
container is accessed with an out-of-bounds index, it inserts a new element
first. This is most useful with \link fcppt::optional::object\endlink.

\tparam T The element type.

\tparam A The allocator type.
*/
template<
	typename T,
	typename A
>
class index_map
{
public:
	typedef
	std::vector<
		T,
		A
	>
	internal_type;

	typedef
	typename
	internal_type::size_type
	size_type;

	typedef
	typename
	internal_type::reference
	reference;

	index_map();

	typedef
	fcppt::function<
		T ()
	>
	insert_function;

	/**
	\brief Returns the element at an index or inserts new ones using a function.

	Returns the element at \a index. If there is no such element, the
	result of <code>insert()</code> is inserted. Note that \a insert might
	be called multiple times.
	*/
	reference
	get(
		size_type index,
		insert_function insert
	);

	/**
	\brief Returns the element at an index or inserts new default-constructed one.

	Returns the element at \a index. If there is no such element,
	<code>T()</code> is inserted.
	*/
	reference
	operator[](
		size_type index
	);

	internal_type const &
	impl() const;
private:
	internal_type impl_;
};

}
}

#endif

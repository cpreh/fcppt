//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAP_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_MAP_DECL_HPP_INCLUDED

#include <fcppt/container/map_fwd.hpp>
#include <fcppt/string.hpp>
#include <utility>

namespace fcppt
{
namespace container
{

template<
	typename MapType
>
class map
{
public:
	typedef MapType map_type;
	typedef typename map_type::key_type key_type;
	typedef typename map_type::mapped_type mapped_type;

	typedef typename map_type::value_type value_type;
	typedef typename map_type::key_compare key_compare;
	typedef typename map_type::allocator_type allocator_type;
	typedef typename map_type::reference reference;
	typedef typename map_type::const_reference const_reference;
	typedef typename map_type::iterator iterator;
	typedef typename map_type::const_iterator const_iterator;
	typedef typename map_type::size_type size_type;
	typedef typename map_type::difference_type difference_type;
	typedef typename map_type::pointer pointer;
	typedef typename map_type::const_pointer const_pointer;
	typedef typename map_type::reverse_iterator reverse_iterator;
	typedef typename map_type::const_reverse_iterator const_reverse_iterator;

	map();

	explicit map(
		map_type const &
	);

	template<
		typename In
	>
	map(
		In beg,
		In end
	);

	void
	insert(
		key_type const &,
		mapped_type const &
	);

	iterator
	insert(
		iterator,
		value_type const &
	);

	void
	insert(
		value_type const &
	);

	void
	erase(
		key_type const &
	);

	void
	erase(
		iterator
	);

	iterator
	find(
		key_type const &
	);

	const_iterator
	find(
		key_type const &
	) const;

	mapped_type const &
	operator[](
		key_type const &
	) const;

	mapped_type &
	operator[](
		key_type const &
	);

	bool
	contains(
		key_type const &
	) const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	size_type
	size() const;

	bool
	empty() const;

	iterator
	lower_bound(key_type const &);

	const_iterator
	lower_bound(key_type const &) const;
private:
	static fcppt::string const
	format_error(
		fcppt::string const &
	);

	map_type impl_;
};

}
}

#endif

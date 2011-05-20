//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CYCLIC_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CYCLIC_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/cyclic_iterator_fwd.hpp>
#include <fcppt/detail/cyclic_iterator_base.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace fcppt
{

template<
	typename ContainerIterator
>
class cyclic_iterator
:
	public fcppt::detail::cyclic_iterator_base<
		ContainerIterator
	>::type
{
public:
	typedef typename detail::cyclic_iterator_base<
		ContainerIterator
	>::type base_type;

	typedef ContainerIterator container_iterator_type;

	typedef typename base_type::value_type value_type;

	typedef typename base_type::reference reference;

	typedef typename base_type::pointer pointer;

	typedef typename base_type::difference_type difference_type;

	typedef typename base_type::iterator_category iterator_category;

	cyclic_iterator();

	template<
		typename OtherIterator
	>
	explicit cyclic_iterator(
		cyclic_iterator<OtherIterator> const &
	);

	cyclic_iterator(
		container_iterator_type const &it,
		container_iterator_type const &begin,
		container_iterator_type const &end
	);

	template<
		typename OtherIterator
	>
	cyclic_iterator<ContainerIterator> &
	operator=(
		cyclic_iterator<OtherIterator> const &
	);

	container_iterator_type
	begin() const;

	container_iterator_type
	end() const;

	container_iterator_type
	get() const;
private:
	friend class boost::iterator_core_access;

	void
	increment();

	void
	decrement();

	bool
	equal(
		cyclic_iterator const &
	) const;

	reference
	dereference() const;

	difference_type
	distance_to(
		cyclic_iterator const &
	) const;
private:
	container_iterator_type
		it_,
		begin_,
		end_;
};

}

#endif

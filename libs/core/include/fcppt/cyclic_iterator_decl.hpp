//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CYCLIC_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CYCLIC_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/cyclic_iterator_fwd.hpp>
#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/detail/cyclic_iterator_base.hpp>
#include <fcppt/iterator/base_decl.hpp>


namespace fcppt
{

/**
\brief An iterator adaptor that cycles through a range

\ingroup fcpptvarious

\tparam ContainerIterator The underlying iterator which must be at least a
forward iterator

A cyclic iterator can be useful in cases where you want <code>end()</code> to
become <code>begin()</code> again. For example, imagine a cycling through a
list of items which means if you skip over the last, you will return to the
first one.

Here is a short example demonstrating its use.

\snippet cyclic_iterator.cpp cyclic_iterator
*/
template<
	typename ContainerIterator
>
class cyclic_iterator final
:
	public
		fcppt::detail::cyclic_iterator_base<
			ContainerIterator
		>
{
public:
	using
	base_type
	=
	fcppt::detail::cyclic_iterator_base<
		ContainerIterator
	>;

	using
	container_iterator_type
	=
	ContainerIterator;

	using
	value_type
	=
	typename
	base_type::value_type;

	using
	reference
	=
	typename
	base_type::reference;

	using
	pointer
	=
	typename
	base_type::pointer;

	using
	difference_type
	=
	typename
	base_type::difference_type;

	using
	iterator_category
	=
	typename
	base_type::iterator_category;

	using
	boundary
	=
	fcppt::homogenous_pair<
		container_iterator_type
	>;

	cyclic_iterator();

	/**
	\brief Copy constructs from another cyclic iterator

	Copy constructs from another cyclic iterator \a other. This only works
	if the underlying iterators are convertible.

	\param other The iterator to copy construct from
	*/
	template<
		typename OtherIterator
	>
	explicit
	cyclic_iterator(
		cyclic_iterator<
			OtherIterator
		> const &other
	);

	/**
	\brief Constructs a new cyclic iterator

	Constructs a new cyclic iterator, starting at \a it, inside a range of
	\a boundary.
	*/
	cyclic_iterator(
		container_iterator_type const &pos,
		boundary const &boundary
	);

	/**
	\brief Assigns from another cyclic iterator

	Assigns from another cyclic iterator \a other. This only works if the
	underlying iterators are convertible.

	\param other The iterator to assign from

	\return <code>*this</code>
	*/
	template<
		typename OtherIterator
	>
	cyclic_iterator &
	operator=(
		cyclic_iterator<
			OtherIterator
		> const &other
	);

	/**
	\brief Returns the boundary
	*/
	[[nodiscard]]
	boundary const &
	get_boundary() const;

	/**
	\brief Returns the underlying iterator
	*/
	[[nodiscard]]
	container_iterator_type
	get() const;

	void
	advance(
		difference_type
	);

	void
	increment();

	void
	decrement();

	[[nodiscard]]
	bool
	equal(
		cyclic_iterator const &
	) const;

	[[nodiscard]]
	reference
	dereference() const;

	[[nodiscard]]
	difference_type
	distance_to(
		cyclic_iterator const &
	) const;
private:
	container_iterator_type it_;

	boundary boundary_;
};

}

#endif

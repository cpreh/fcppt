//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CYCLIC_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CYCLIC_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/cyclic_iterator_fwd.hpp>
#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/detail/cyclic_iterator_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

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
	/**
	\brief The base type which is a <code>boost::iterator_facade</code>
	*/
	typedef
	fcppt::detail::cyclic_iterator_base<
		ContainerIterator
	>
	base_type;

	/**
	\brief The underlying iterator type
	*/
	typedef
	ContainerIterator
	container_iterator_type;

	/**
	\brief The value type adapted from \a ContainerIterator
	*/
	typedef
	typename
	base_type::value_type
	value_type;

	/**
	\brief The reference type adapted from \a ContainerIterator
	*/
	typedef
	typename
	base_type::reference
	reference;

	/**
	\brief The pointer type adapted from \a ContainerIterator
	*/
	typedef
	typename
	base_type::pointer
	pointer;

	/**
	\brief The difference type adapted from \a ContainerIterator
	*/
	typedef
	typename
	base_type::difference_type
	difference_type;

	/**
	\brief The iterator category, either Forward or Bidirectional
	*/
	typedef
	typename
	base_type::iterator_category
	iterator_category;

	typedef
	fcppt::homogenous_pair<
		container_iterator_type
	>
	boundary;

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
	boundary const &
	get_boundary() const;

	/**
	\brief Returns the underlying iterator
	*/
	container_iterator_type
	get() const;
private:
	friend class boost::iterator_core_access;

	void
	advance(
		difference_type
	);

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
	container_iterator_type it_;

	boundary boundary_;
};

FCPPT_PP_POP_WARNING

}

#endif

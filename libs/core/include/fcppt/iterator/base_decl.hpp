//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_BASE_DECL_HPP_INCLUDED
#define FCPPT_ITERATOR_BASE_DECL_HPP_INCLUDED

#include <fcppt/iterator/base_fwd.hpp>
#include <fcppt/iterator/category_at_least.hpp>
#include <fcppt/iterator/is_types.hpp>
#include <fcppt/iterator/types.hpp>
#include <fcppt/mpl/implication.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/or.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Types
>
class base
{
public:
	static_assert(
		fcppt::iterator::is_types<
			Types
		>::value,
		"Types must be fcppt::iterator::types"
	);

	typedef
	typename
	Types::derived
	derived;

	typedef
	typename
	Types::value_type
	value_type;

	typedef
	typename
	Types::reference
	reference;

	typedef
	typename
	Types::difference_type
	difference_type;

	typedef
	typename
	std::remove_reference<
		reference
	>::type *
	pointer;

	typedef
	typename
	Types::iterator_category
	iterator_category;
private:
	template<
		typename Category
	>
	using
	my_category_at_least
	=
	fcppt::iterator::category_at_least<
		iterator_category,
		Category
	>;

	static_assert(
		fcppt::mpl::implication<
			my_category_at_least<
				std::forward_iterator_tag
			>,
			boost::mpl::or_<
				std::is_same<
					reference,
					value_type &
				>,
				std::is_same<
					reference,
					value_type const &
				>
			>
		>::value,
		"Forward iterators need real reference types"
	);

	static_assert(
		fcppt::mpl::implication<
			my_category_at_least<
				std::random_access_iterator_tag
			>,
			std::is_signed<
				difference_type
			>
		>::value,
		"difference_type must be signed for random access iterators"
	);
protected:
	base();
public:
	reference
	operator*() const;

	derived &
	operator++();

	bool
	operator==(
		base const &
	) const;

	bool
	operator!=(
		base const &
	) const;

	pointer
	operator->() const;

	derived
	operator++(
		int
	);

	void
	swap(
		base &
	);

	// Bidirectional iterator
	derived &
	operator--();

	derived
	operator--(
		int
	);

	// Random access iterator
	derived &
	operator+=(
		difference_type
	);

	derived
	operator+(
		difference_type
	) const;

	derived &
	operator-=(
		difference_type
	);

	derived
	operator-(
		difference_type
	) const;

	reference
	operator[](
		difference_type
	) const;

	difference_type
	operator-(
		base const &
	) const;
private:
	derived &
	get();

	derived const &
	get() const;
};

template<
	typename Types
>
void
swap(
	fcppt::iterator::base<
		Types
	> &,
	fcppt::iterator::base<
		Types
	> &
);

// Random access iterator
template<
	typename Types
>
typename
fcppt::iterator::base<
	Types
>::derived
operator+(
	typename
	fcppt::iterator::base<
		Types
	>::difference_type,
	fcppt::iterator::base<
		Types
	> const &
);

template<
	typename Types
>
bool
operator<(
	fcppt::iterator::base<
		Types
	> const &,
	fcppt::iterator::base<
		Types
	> const &
);

template<
	typename Types
>
bool
operator>(
	fcppt::iterator::base<
		Types
	> const &,
	fcppt::iterator::base<
		Types
	> const &
);

template<
	typename Types
>
bool
operator<=(
	fcppt::iterator::base<
		Types
	> const &,
	fcppt::iterator::base<
		Types
	> const &
);

template<
	typename Types
>
bool
operator>=(
	fcppt::iterator::base<
		Types
	> const &,
	fcppt::iterator::base<
		Types
	> const &
);

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/intrusive/base_fwd.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/detail/iterator_base.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace intrusive
{

template<
	typename Type
>
class iterator
:
public
	fcppt::intrusive::detail::iterator_base<
		Type
	>
{
public:
	typedef
	fcppt::intrusive::detail::iterator_base<
		Type
	>
	iterator_base;

	typedef
	typename
	iterator_base::reference
	reference;

	typedef
	fcppt::intrusive::base<
		typename
		std::remove_const<
			Type
		>::type
	>
	base_type;

	typedef
	typename
	std::conditional<
		std::is_const<
			Type
		>::value,
		base_type const,
		base_type
	>::type *
	pointer_type;

	iterator();

	explicit
	iterator(
		pointer_type
	);

	void
	increment();

	void
	decrement();

	reference
	dereference() const;

	bool
	equal(
		iterator const &
	) const;
private:
	pointer_type cur_;
};

}
}

#endif

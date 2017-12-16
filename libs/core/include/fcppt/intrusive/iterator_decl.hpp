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
	base_type;

	typedef
	typename
	base_type::reference
	reference;

	iterator();

	explicit
	iterator(
		fcppt::intrusive::base *
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
	fcppt::intrusive::base *cur_;
};

}
}

#endif

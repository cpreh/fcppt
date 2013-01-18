//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/tree/iterator_fwd.hpp>
#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/container/tree/detail/iterator_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename It
>
class iterator
:
	public fcppt::container::tree::detail::iterator_base<
		It
	>::type
{
	typedef typename fcppt::container::tree::detail::iterator_base<
		It
	>::type base;
public:
	typedef typename base::value_type value_type;

	typedef typename base::reference reference;

	typedef typename base::difference_type difference_type;

	typedef typename base::pointer pointer;

	typedef typename base::iterator_category iterator_category;

	iterator();

	template<
		typename OtherIt
	>
	iterator(
		fcppt::container::tree::iterator<
			OtherIt
		> const &
	);
private:
	friend class boost::iterator_core_access;

	explicit
	iterator(
		It
	);

	It
	get() const;

	template<
		typename T
	>
	friend class object;

	template<
		typename OtherIt
	>
	friend class iterator;

	void
	increment();

	void
	decrement();

	bool
	equal(
		iterator const &
	) const;

	reference
	dereference() const;

	It impl_;
};

FCPPT_PP_POP_WARNING

}
}
}

#endif

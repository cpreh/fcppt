//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_LIST_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_LIST_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/list_fwd.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/detail/link_fwd.hpp>


namespace fcppt
{
namespace intrusive
{

template<
	typename Type
>
class list
{
	FCPPT_NONCOPYABLE(
		list
	);
public:
	list();

	list(
		list &&
	);

	list &
	operator=(
		list &&
	);

	~list();

	typedef
	fcppt::intrusive::iterator<
		Type
	>
	iterator;

	typedef
	fcppt::intrusive::iterator<
		Type const
	>
	const_iterator;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	bool
	empty() const;
private:
	typedef
	fcppt::intrusive::detail::link<
		Type
	>
	link_type;

	typedef
	fcppt::intrusive::base<
		Type
	>
	base_type;

	link_type
	push_back(
		base_type &
	)
	noexcept;

	template<
		typename T
	>
	friend class fcppt::intrusive::base;

	base_type head_;
};

}
}

#endif
